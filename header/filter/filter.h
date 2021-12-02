#ifndef RECHERCHE_FILTER_H
#define RECHERCHE_FILTER_H

#include "opencv2/core.hpp"

using namespace cv;

enum filterType
{
    IDEAL=0,
};

class Filter
{
public:
    Filter(const Size& size, filterType type);

    void filter(Mat& src, Mat& dst);
    void display();


protected:
    Mat H;
    filterType type;

    virtual ~Filter() = 0;
};

#endif //RECHERCHE_FILTER_H
