#ifndef RECHERCHE_HIGH_PASS_FILTER_H
#define RECHERCHE_HIGH_PASS_FILTER_H

#include "filter.h"

class HighPassFilter : public Filter
{
public:
    HighPassFilter(const Size& size, float freq);

    float cutoff_freq;

private:
    void fill_transfer_function();
};


#endif //RECHERCHE_HIGH_PASS_FILTER_H
