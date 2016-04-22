#include <opencv2/opencv.hpp>
#include "cuda_runtime.h"
#include "cuda.h"
#include "device_launch_parameters.h"
#include "curand.h"
#include "curand_kernel.h"

#include <iostream>

const int threadN = 3;
const int blockSize = threadN * threadN;
const int BLOCK_SIZE = threadN;

// Функция-ядро запускается каждым потоком CUDA-блока
// Каждому потоку соответствует пиксель изображения
__global__ void binThreshold(
		unsigned char *scr
		, unsigned char *img
		, int width
	)
{
	__shared__ int sum;
	__shared__ int max;
	__shared__ int count;
	bool isCounted = false;
	int i = blockDim.x * blockIdx.x + threadIdx.x;
	int j = blockDim.y * blockIdx.y + threadIdx.y;
	int tmp = width * j + i;

	if (threadIdx.x == 0 && threadIdx.y == 0) {
		sum = 0;
	}
	__syncthreads();

	// Находим сумму элементов в блоке
	atomicAdd(&sum, scr[tmp]);
	__syncthreads();

	if (threadIdx.x == 0 && threadIdx.y == 0) {
		sum /= 255;
	}
	__syncthreads();

	// Расстановка пикселей бинарного изображения
	while (sum > 0) {
		if (threadIdx.x == 0 && threadIdx.y == 0) {
			max = 0;
			count = 0;
		}
		__syncthreads();

		// На каждой итерации находим пиксель
		// максимальной яркости 
		if (!isCounted) {
			atomicMax(&max, scr[tmp]);
		}
		__syncthreads();

		bool isMax = false;
		if (scr[tmp] == max) {
			atomicAdd(&count, 1);
			isCounted = true;
			isMax = true;
		}
		__syncthreads();

		if (isMax) {
			if (sum >= count) {
				atomicAdd(&sum, -1);
				img[tmp] = 255;
			} else {
				if (atomicAdd(&sum, -1) > 0) {
					img[tmp] = 255;
				}
			}
		}
		__syncthreads();
	}
}

// Бинаризация одного блока
void blockProc(const cv::Mat &scr, cv::Mat &img, int x, int y)
{
	uchar block[threadN][threadN];
    uchar binBlock[threadN][threadN];

    int sum = 0;

    for (int i = 0; i < threadN; ++i) {
        const uchar *rowPtr = scr.ptr<uchar>(x + i) + y;
        for (int j = 0; j < threadN; ++j) {
            block[i][j] = rowPtr[j];
            binBlock[i][j] = 0;
            sum += rowPtr[j];
        }
    }

    sum /= 255;

    int lessThan = 256;                  // заполняем бинарный блок белым
    while (sum != 0) {
        int max = 0;
        int count = 0;

        for (int i = 0 ; i < BLOCK_SIZE; ++i) {
            for (int j = 0; j < BLOCK_SIZE; ++j) {
                if (block[i][j] < lessThan) {
                    if (max < block[i][j]) {
                        max = block[i][j];
                        count = 1;
                    } else if (max == block[i][j]) {
                        ++count;
                    }
                }
            }
        }

        lessThan = max;         // находим точки максимальной яркости
		uchar *points[BLOCK_SIZE * BLOCK_SIZE];

        int k = 0;
        for (int i = 0; i < BLOCK_SIZE; ++i) {
            for (int j = 0 ; j < BLOCK_SIZE; ++j) {
                if (max == block[i][j]) {
                    points[k] = &binBlock[i][j];
                    ++k;
                }
            }
        }

        if (sum >= count) {
            for (int i = 0; i < count; ++i) {
                *points[i] = 255;
            }
            sum -= count;
        } else {                                    // рандомизация
            for (int i = 0; i < sum; ++i) {
                int pos = std::rand() % count;
                *points[pos] = 255;
                points[pos] = points[count - 1];
                --count;
            }
            sum = 0;
        }
	}

	for (int i = 0; i < BLOCK_SIZE; ++i) {        // записываем блок в изображение
        uchar *rowPtr = img.ptr<uchar>(x + i) + y;
        for (int j = 0; j < BLOCK_SIZE; ++j) {
            rowPtr[j] = binBlock[i][j];
        }
    }
}

int main()
{
	// Исходное изображение
	cv::Mat scr = cv::imread("test\\Cameraman.png", 0);

	int rows = scr.rows + threadN - scr.rows % threadN;
    int cols = scr.cols + threadN - scr.cols % threadN;
	cv::Mat bordered = cv::Mat(rows, cols, CV_8U);
    scr.copyTo(bordered(cv::Rect(0, 0, scr.cols, scr.rows)), scr);
	
	cudaEvent_t start, stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);

	//----------------------  GPU ------------------------------
	cudaEventRecord(start, 0);
	
	unsigned char *sourceData, *binData;

	// Выделение памяти
	cudaMallocManaged(&sourceData, rows * cols * sizeof(unsigned char));
	cudaMallocManaged(&binData, rows * cols * sizeof(unsigned char));
	memcpy(sourceData, bordered.data, rows * cols * sizeof(unsigned char));

	int blockX = cols / threadN;
	int blockY = rows / threadN;
	dim3 cblocks(blockX, blockY);
	dim3 cthreads(threadN, threadN);

	// Запуск функции-ядра на всех потоках
	binThreshold <<< cblocks, cthreads >>> (sourceData, binData, cols);
	cudaThreadSynchronize();
	cv::Mat bin(bordered.size(), CV_8U, binData);
	bin = bin(cv::Rect(0, 0, scr.cols, scr.rows));

	cudaEventRecord(stop);
	float msGPU = 0.0f;
    cudaEventSynchronize(stop);
    cudaEventElapsedTime(&msGPU, start, stop);
    std::cout << "Elapsed GPU time: " << msGPU << " milliseconds" << std::endl;

	//----------------------- CPU --------------------------------
	cudaEventRecord(start, 0);
	cudaEventSynchronize(start);

	cv::Mat img1 = cv::Mat(rows, cols, CV_8U);
	cv::Mat bordered2 = cv::Mat(rows, cols, CV_8U);
	scr.copyTo(bordered2(cv::Rect(0, 0, scr.cols, scr.rows)), scr);

	// Запуск параллельного цикла
	//#pragma omp parallel for
	for (int i = 0; i < rows; i += threadN) {
		for (int j = 0; j < cols; j += threadN) {
            blockProc(bordered2, img1, i, j);
        }
    }
	cv::Mat img = img1(cv::Rect(0, 0, scr.cols, scr.rows));

	cudaEventRecord(stop, 0);
	cudaEventSynchronize(stop);
	float msCPU = 0.0f;
	cudaEventElapsedTime(&msCPU, start, stop);
    std::cout << "Elapsed CPU time: " << msCPU << " milliseconds" << std::endl;
	std::cout << std::endl << "Rate: " << (msCPU / msGPU) << " x" << std::endl;

	int screen = scr.rows > 1080 || scr.cols > 1960 ? cv::WINDOW_NORMAL : cv::WINDOW_AUTOSIZE;
	//imwrite("binarizedGPU.jpg", bin);
	//imwrite("binarizedCPU.jpg", img);

    cv::namedWindow("GPU", screen);
	cv::imshow("GPU", bin);
	cv::namedWindow("CPU", screen);
	cv::imshow("CPU", img);
	cv::waitKey();
	//getchar();

	cudaFree(sourceData);
	cudaFree(binData);
	cudaEventDestroy(start);
	cudaEventDestroy(stop);
    return 0;
}