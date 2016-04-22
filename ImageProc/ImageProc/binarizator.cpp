#include "binarizator.h"
#include <omp.h>

using namespace cv;

Binarizator::Binarizator()
{

}

void Binarizator::blockProc(const Mat &scr, Mat &img, int x, int y)
{
    uchar block[BLOCK_SIZE][BLOCK_SIZE];
    uchar binBlock[BLOCK_SIZE][BLOCK_SIZE];

    int sum = 0;

    for (int i = 0; i < BLOCK_SIZE; ++i) {
        const uchar *rowPtr = scr.ptr<uchar>(x + i) + y;
        for (int j = 0; j < BLOCK_SIZE; ++j) {
            block[i][j] = rowPtr[j];
            binBlock[i][j] = 0;
            sum += rowPtr[j];
        }
    }

    sum /= 255;

    int lessThan = 256;                                                           // заполняем бинарный блок белым
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
        } else {                                          // рандомизация
            for (int i = 0; i < sum; ++i) {
                int pos = std::rand() % count;
                *points[pos] = 255;
                points[pos] = points[count - 1];
                --count;
            }
            sum = 0;
        }
    }

    for (int i = 0; i < BLOCK_SIZE; ++i) {            // записываем блок в изображение
        uchar *rowPtr = img.ptr<uchar>(x + i) + y;
        for (int j = 0; j < BLOCK_SIZE; ++j) {
            rowPtr[j] = binBlock[i][j];
        }
    }
}

Mat Binarizator::blockBinarize(const Mat &scr)
{
    int rows = scr.rows + BLOCK_SIZE - scr.rows % BLOCK_SIZE;
    int cols = scr.cols + BLOCK_SIZE - scr.cols % BLOCK_SIZE;

    Mat img = Mat(rows, cols, CV_8U);
    Mat bordered = Mat(rows, cols, CV_8U);
    scr.copyTo(bordered(Rect(0, 0, scr.cols, scr.rows)), scr);

    #pragma omp parallel for
    for (int i = 0; i < rows; i += BLOCK_SIZE) {
        for (int j = 0; j < cols; j += BLOCK_SIZE) {
            blockProc(bordered, img, i, j);
        }
    }
    return img(Rect(0, 0, scr.cols, scr.rows));
}

Mat Binarizator::thresholdBinarize(const Mat &scr)
{
    Mat img = Mat(scr.rows, scr.cols, CV_8U);

	for (int i = 0; i < scr.rows; ++i) {
        const uchar *rowScr = scr.ptr<uchar>(i);
        uchar *rowImg = img.ptr<uchar>(i);
        for (int j = 0; j < scr.cols; ++j) {
            rowImg[j] = rowScr[j] < 127 ? 0 : 255;
        }
    }
    return img;
}

Mat Binarizator::randomDither(const Mat &scr)
{
    Mat img = Mat(scr.rows, scr.cols, CV_8U);

    for (int i = 0; i < scr.rows; ++i) {
        const uchar *rowStr = scr.ptr<uchar>(i);
        uchar *rowImg = img.ptr<uchar>(i);
        for (int j = 0; j < scr.cols; ++j) {
            uchar thresh = 50 + (std::rand() % 151);
            rowImg[j] = rowStr[j] < thresh ? 0 : 255;
        }
    }
    return img;
}

Mat Binarizator::orderedDither(const Mat &scr)
{
    Mat img = Mat(scr.rows, scr.cols, CV_8U);
    double thresholdMatrix[4][4] = {{5,9,6,10}, {13,1,14,2}, {7,11,4,8}, {15,3,12,0}};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            thresholdMatrix[i][j] = 255.0 / 16 * (thresholdMatrix[i][j] + 0.5);
        }
    }

    for (int i = 0; i < scr.rows; ++i) {
        const uchar *rowStr = scr.ptr<uchar>(i);
        uchar *rowImg = img.ptr<uchar>(i);
        for (int j = 0; j < scr.cols; ++j) {
            rowImg[j] = rowStr[j] < thresholdMatrix[i % 4][j % 4] ? 0 : 255;
        }
    }
    return img;
}

Mat Binarizator::errorDiffusion(const Mat &scr)
{
    Mat img = Mat(scr.rows, scr.cols, CV_8U);
    Mat ar;
    scr.convertTo(ar, CV_32F);

    for (int i = 0; i < ar.rows; ++i) {
        uchar *rowImg = img.ptr<uchar>(i);
        float *rowAr = ar.ptr<float>(i);
        float *nextRowAr = NULL;
        if (i < ar.rows - 1) {
            nextRowAr = ar.ptr<float>(i + 1);
        }
        for (int j = 0; j < ar.cols; ++j) {
            rowImg[j] = rowAr[j] < 128 ? 0 : 255;
            float err = rowAr[j] - rowImg[j];
            if (i < ar.rows - 1) {
                nextRowAr[j] += err * 5.0 / 16;
                if (j < ar.cols - 1) {
                    nextRowAr[j + 1] += err * 1.0 / 16;
                }
                if (j > 0) {
                    nextRowAr[j - 1] += err * 3.0 / 16;
                }
            }
            if (j < ar.cols - 1) {
                rowAr[j + 1] += err * 7.0 / 16;
            }
        }
    }

    return img;
}

Binarizator::~Binarizator()
{

}
