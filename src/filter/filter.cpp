#include <opencv2/highgui.hpp>

#include "filter.h"
#include "dft.h"

using namespace cv;

Filter::Filter(const Size& size, filterType type) : type(type)
{
    H = Mat(size, CV_32F, Scalar(1));
}


void Filter::filter(Mat& src, Mat& dst)
{
    shift_image(H, H);

    Mat planes_dft[] = {src, Mat::zeros(src.size(), CV_32F)};
    split(src, planes_dft);
    Mat planes_filtered[] = {Mat::zeros(src.size(), CV_32F), Mat::zeros(src.size(), CV_32F)};

    planes_filtered[0] = H.mul(planes_dft[0]);
    planes_filtered[1] = H.mul(planes_dft[1]);

    merge(planes_filtered, 2, dst);

    shift_image(H, H);
}

void Filter::display()
{
    std::string name;
    switch (type)
    {
        case filterType::IDEAL:
            name = "Ideal filter";
            break;

        default:
            name = "Filter";
            break;
    }
    imshow(name, H);
    waitKey(0);
}

Filter::~Filter() = default;