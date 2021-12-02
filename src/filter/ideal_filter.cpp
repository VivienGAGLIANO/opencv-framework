#include "ideal_filter.h"

IdealFilter::IdealFilter(const Size& size, float D0) : Filter(size, filterType::IDEAL), D0(D0)
{
    fill_transfer_function();
}

void IdealFilter::fill_transfer_function()
{
    float D;
    for (int u = 0; u < H.rows; ++u)
    {
        for (int v = 0; v < H.cols; ++v)
        {
            D = sqrt(pow(u-H.rows/2, 2) + pow(v-H.cols/2, 2));
            if (D > D0)
                H.at<float>(u, v) = 0.0;
        }
    }
}