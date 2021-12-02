#ifndef RECHERCHE_IDEAL_FILTER_H
#define RECHERCHE_IDEAL_FILTER_H

#include "filter.h"

class IdealFilter : public Filter
{
public:
    IdealFilter(const Size& size, float D0);

    float D0;

private:
    void fill_transfer_function();

};

#endif //RECHERCHE_IDEAL_FILTER_H
