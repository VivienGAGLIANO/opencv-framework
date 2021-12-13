#include <opencv2/highgui.hpp>
#include <string>

#include "pyramids/gaussian_pyramid.h"


GaussianPyramid::GaussianPyramid(const cv::Mat& src, int depth) : depth(depth)
{
    if (depth > log(src.rows))
        throw std::out_of_range("Chosen image cannot be reduced to given depth.");

    levels.reserve(depth);
    levels.push_back(src.clone());
    construct_pyramid();
}

void GaussianPyramid::construct_pyramid()
{
    for (int i = 0; i < depth; ++i)
        levels.push_back(reduce(levels.at(i)));
}

cv::Mat GaussianPyramid::reduce(const cv::Mat &prev)
{
    cv::Mat next(prev.rows / 2, prev.cols / 2, prev.type());
    for (int x = 0; x < next.cols; ++x)
        for (int y = 0; y < next.rows; ++y)
            for (int a = 0; a < 2; ++a)
                for (int b = 0; b < 2; ++b)
                    next.at<float>(x, y) += .25f * (prev.at<float>(2*x+a, 2*y+b));
    return next;
}

void GaussianPyramid::display_layers()
{
    for (int i = 0; i < depth; ++i)
    {
        cv::imshow("Pyramid layer " + std::to_string(i), levels.at(i));
    }
    cv::waitKey(0);
}


