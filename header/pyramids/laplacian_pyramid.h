#ifndef RECHERCHE_LAPLACIAN_PYRAMID_H
#define RECHERCHE_LAPLACIAN_PYRAMID_H

#include <opencv2/core.hpp>

#include "gaussian_pyramid.h"


class LaplacianPyramid : public GaussianPyramid
{
public:
    LaplacianPyramid(const cv::Mat& src, int depth);
    explicit LaplacianPyramid(const GaussianPyramid& gaussian_pyramid);
    void construct_pyramid() override;
    void display_layers_laplace();
    cv::Mat reconstruct_image();

    std::vector<cv::Mat> layers_laplace;
};

#endif //RECHERCHE_LAPLACIAN_PYRAMID_H
