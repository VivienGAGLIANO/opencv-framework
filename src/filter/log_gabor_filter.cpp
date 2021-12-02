#include "log_gabor_filter.h"

LogGaborFilter::LogGaborFilter(const Size &size, float centre_frequency, float bandwidth) : Filter(size, filterType::LOG_GABOR), freq(centre_frequency), bandwidth(bandwidth)
{
    fill_transfer_function();
}

void LogGaborFilter::fill_transfer_function()
{
    float w_1, w_2, n, d;
    for (int u = 0; u < H.rows; ++u)
    {
        w_2 = u - H.rows/2.0;
        for (int v = 0; v < H.cols; ++v)
        {
            w_1 = v - H.cols/2.0;
            n = pow(log(sqrt(w_1*w_1 + w_2*w_2) / freq), 2);
            d = 2 * pow(log(bandwidth), 2);
            H.at<float>(u, v) = exp(-n/d);
        }
    }
}
