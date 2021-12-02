#ifndef RECHERCHE_LOW_PASS_FILTER_H
#define RECHERCHE_LOW_PASS_FILTER_H

#include "filter.h"

class LowPassFilter : public Filter
{
public:
    LowPassFilter(const Size& size, float freq);

    float cutoff_freq;

private:
    void fill_transfer_function();

};

#endif //RECHERCHE_LOW_PASS_FILTER_H
