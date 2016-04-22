#include <opencv2/opencv.hpp>
#include "binarizator.h"
#include "distance.h"
#include <omp.h>
#include <math.h>

using namespace cv;

int main()
{
    Mat scr = imread("test\\caprichos_-_plate_44__they_spin_finely-large.jpg", 0);
    double a = omp_get_wtime();

	Mat img = Binarizator().errorDiffusion(scr);

    double b = omp_get_wtime();

    std::cout << "Time: " << (b - a) * 1000 << " ms" << std::endl << std::endl;
	std::cout << "Holder dist: " << Distance().holder(scr, img, 2);
    //imwrite("Results\\binarized.jpg", img);
    int screen = scr.rows > 1080 || scr.cols > 1960 ? WINDOW_NORMAL : WINDOW_AUTOSIZE;
    namedWindow("Original", screen);
    imshow("Original", scr);
    namedWindow("Binarized", screen);
    imshow("Binarized", img);
    waitKey();
    return 0;	
}
