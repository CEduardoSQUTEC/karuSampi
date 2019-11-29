//
// Created by eduar on 28-Nov-19.
//

#ifndef KARUSAMPI_CSYMPTOM_H
#define KARUSAMPI_CSYMPTOM_H

#include "../types.h"

class cSymptom {
    text_t name;
    state_t presence;
public:
    cSymptom(const text_t &n, state_t &p): name(n), presence(p) {}
};

#endif //KARUSAMPI_CSYMPTOM_H
