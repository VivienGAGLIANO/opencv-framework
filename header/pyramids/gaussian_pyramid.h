#ifndef RECHERCHE_GAUSSIAN_PYRAMID_H
#define RECHERCHE_GAUSSIAN_PYRAMID_H

#include <opencv2/core.hpp>
#include <vector>

class GaussianPyramid
{
public:
    GaussianPyramid(const cv::Mat& src, int depth);
    virtual void construct_pyramid();
    void display_layers_gauss();

    int depth;
    std::vector<cv::Mat> layers_gauss;

protected:

    cv::Mat reconstruct_image();
//    void expand();
//    cv::Mat reduce(const cv::Mat& prev);
};

#endif //RECHERCHE_GAUSSIAN_PYRAMID_H
