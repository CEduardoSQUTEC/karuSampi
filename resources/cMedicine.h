//
// Created by eduar on 28-Nov-19.
//

#ifndef KARUSAMPI_CMEDICINE_H
#define KARUSAMPI_CMEDICINE_H

#include "../types.h"

class cMedicine {
    text_t name;
    dose_t dose;
public:
    cMedicine(text_t &n, dose_t &d): name(n), dose(d) {}
};

#endif //KARUSAMPI_CMEDICINE_H
