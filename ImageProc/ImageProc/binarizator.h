#pragma once

#include <opencv2/opencv.hpp>

const int BLOCK_SIZE = 4;

class Binarizator
{
private:
    void blockProc(const cv::Mat &scr, cv::Mat &img, int x, int y);
public:
    Binarizator();
    cv::Mat blockBinarize(const cv::Mat &scr);
    cv::Mat thresholdBinarize(const cv::Mat &scr);
    cv::Mat randomDither(const cv::Mat &scr);
    cv::Mat orderedDither(const cv::Mat &scr);
    cv::Mat errorDiffusion(const cv::Mat &scr);
    ~Binarizator();
};
