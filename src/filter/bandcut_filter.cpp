#include "bandcut_filter.h"

BandcutFilter::BandcutFilter(const Size &size, float lower_frequency, float upper_frequency) : Filter(size, filterType::BANDPASS), low_freq(min(lower_frequency, upper_frequency)), up_freq(max(lower_frequency, upper_frequency))
{
    fill_transfer_function();
}

void BandcutFilter::fill_transfer_function()
{
    float D;
    for (int u = 0; u < H.rows; ++u)
    {
        for (int v = 0; v < H.cols; ++v)
        {
            D = sqrt(pow(u-H.rows/2, 2) + pow(v-H.cols/2, 2));
            if (D < low_freq || up_freq < D)
                H.at<float>(u, v) = 1.0;
        }
    }
}
