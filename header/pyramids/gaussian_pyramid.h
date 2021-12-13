#ifndef RECHERCHE_GAUSSIAN_PYRAMID_H
#define RECHERCHE_GAUSSIAN_PYRAMID_H

#include <opencv2/core.hpp>
#include <vector>

class GaussianPyramid
{
public:
    GaussianPyramid(const cv::Mat& src, int depth);
    void display_layers();

    int depth;
    std::vector<cv::Mat> levels;

private:

    void construct_pyramid();
    void expand();
    cv::Mat reduce(const cv::Mat& prev);
};

#endif //RECHERCHE_GAUSSIAN_PYRAMID_H
