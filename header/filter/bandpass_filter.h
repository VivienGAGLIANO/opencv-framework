#ifndef RECHERCHE_BANDPASS_FILTER_H
#define RECHERCHE_BANDPASS_FILTER_H

#include "filter.h"

class BandpassFilter : public Filter
{
public:
    BandpassFilter(const Size& size, float lower_frequency, float upper_frequency);

    float low_freq, up_freq;

private:
    void fill_transfer_function();
};

#endif //RECHERCHE_BANDPASS_FILTER_H
