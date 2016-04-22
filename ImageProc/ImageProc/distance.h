#pragma once

#include <opencv2/opencv.hpp>

class Distance
{
public:
    Distance();
    float holder(const cv::Mat &scr1, const cv::Mat &scr2, float p);
	float psnr(const cv::Mat &scr1, const cv::Mat &scr2);
    ~Distance();
};
