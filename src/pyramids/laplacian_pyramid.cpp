#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "laplacian_pyramid.h"

LaplacianPyramid::LaplacianPyramid(const cv::Mat &src, int depth) : GaussianPyramid(src, depth) {}

LaplacianPyramid::LaplacianPyramid(const GaussianPyramid &gaussian_pyramid) : GaussianPyramid(gaussian_pyramid) {}


void LaplacianPyramid::construct_pyramid()
{
    GaussianPyramid::construct_pyramid();

    layers_laplace.push_back(layers_gauss.back().clone());

    cv::Mat prev, expa;
    for (int i = depth-1; i >= 0; --i)
    {
        prev = layers_gauss.at(i+1);
        cv::pyrUp(prev, expa, cv::Size(2*prev.rows, 2*prev.cols));
        layers_laplace.insert(layers_laplace.begin(), layers_gauss.at(i) - expa);
    }
}

void LaplacianPyramid::display_layers_laplace()
{
    for (int i = 0; i <= depth; ++i)
        cv::imshow("Laplacian pyramid " + std::to_string(i), layers_laplace.at(i));

    cv::waitKey(0);
}


