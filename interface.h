//
// Created by eduar on 29-Nov-19.
//

#ifndef KARUSAMPI_INTERFACE_H
#define KARUSAMPI_INTERFACE_H

#include "types.h"
#include "resources/cReport.h"

void greeting(text_t &n, age_t &a, kilogram_t &m, meter_t &h, mmhg_t &sP, mmhg_t &dP, bpm_t &hR);

// void anomalies(cPatient &cP);

void menu(cReport &cR);

#endif //KARUSAMPI_INTERFACE_H
