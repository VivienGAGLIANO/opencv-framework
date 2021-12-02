#ifndef RECHERCHE_LOG_GABOR_FILTER_H
#define RECHERCHE_LOG_GABOR_FILTER_H

#include "filter.h"

class LogGaborFilter : public Filter
{
public:
    LogGaborFilter(const Size& size, float centre_frequency, float bandwidth);

    float freq, bandwidth;

private:
    void fill_transfer_function();
};

#endif //RECHERCHE_LOG_GABOR_FILTER_H
