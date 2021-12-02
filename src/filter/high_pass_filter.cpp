#include "high_pass_filter.h"

HighPassFilter::HighPassFilter(const Size& size, float freq) : Filter(size, filterType::HIGH_PASS), cutoff_freq(freq)
{
    fill_transfer_function();
}

void HighPassFilter::fill_transfer_function()
{
    float D;
    for (int u = 0; u < H.rows; ++u)
    {
        for (int v = 0; v < H.cols; ++v)
        {
            D = sqrt(pow(u-H.rows/2, 2) + pow(v-H.cols/2, 2));
            if (D > cutoff_freq)
                H.at<float>(u, v) = 1.0;
        }
    }
}
