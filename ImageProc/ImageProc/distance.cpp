#include "distance.h"
#include <math.h>
#include <omp.h>

Distance::Distance()
{

}

float Distance::holder(const cv::Mat &scr1, const cv::Mat &scr2, float p)
{
    float result = 0;
    for (int i = 0; i < scr1.rows; ++i) {
        const uchar *rowStr1 = scr1.ptr<uchar>(i);
        const uchar *rowStr2 = scr2.ptr<uchar>(i);
        for (int j = 0; j < scr1.cols; ++j) {
            result += pow(abs(rowStr1[j] - rowStr2[j]), p);
        }
    }
	return result / scr1.rows / scr1.cols;
}

float Distance::psnr(const cv::Mat &scr1, const cv::Mat &scr2)
{
	return 20 * log10(255 / holder(scr1, scr2, 2));
}

Distance::~Distance()
{

}

