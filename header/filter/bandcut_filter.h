#ifndef RECHERCHE_BANDCUT_FILTER_H
#define RECHERCHE_BANDCUT_FILTER_H

#include "filter.h"

class BandcutFilter : public Filter
{
public:
    BandcutFilter(const Size& size, float lower_frequency, float upper_frequency);

    float low_freq, up_freq;

private:
    void fill_transfer_function();
};

#endif //RECHERCHE_BANDCUT_FILTER_H
