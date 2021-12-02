#ifndef RECHERCHE_FILTER_H
#define RECHERCHE_FILTER_H

#include "opencv2/core.hpp"

using namespace cv;

enum filterType
{
    PRODUCT=-1,
    LOW_PASS=0,
    HIGH_PASS=1,
    BANDPASS=2,
    BANDCUT=3,
    LOG_GABOR=4,
};

class Filter
{
public:
    void filter(Mat& src, Mat& dst);
    void display();

    Filter* operator *(const Filter& a) const;

protected:
    Mat H;
    filterType type;

    Filter(const Size& size, filterType type);
};

#endif //RECHERCHE_FILTER_H
