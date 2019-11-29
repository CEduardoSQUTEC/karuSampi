//
// Created by eduar on 28-Nov-19.
//

#ifndef KARUSAMPI_CPATIENT_H
#define KARUSAMPI_CPATIENT_H

#define DEF class cPatient : public cPerson {\
private:\
    text_t name;\
    gender_t gender;\
    age_t age;\
    kilogram_t mass;\
    meter_t height;\
    mmhg_t systolicPressure;\
    mmhg_t diastolicPressure;\
    bpm_t heartRate;\
    imc_t imc;\
    cDisease disease;\
public:\
    cPatient(text_t &n, gender_t &g, age_t &a, kilogram_t &m, meter_t &h, mmhg_t &sP, mmhg_t &dP, bpm_t &hR) :\
             cPerson(n, g, a, m, h, sP, dP, hR){}\
\
    friend void constantSneezing(cPatient&);\
    friend void soreThroat(cPatient&);\
    friend void earlyAppearance(cPatient&);\
    friend void headache(cPatient&);\
    friend void nasalCongestion(cPatient&);\
    friend void thickMucus(cPatient&);\
    friend void coughing(cPatient&);\
    friend void extremeTiredness(cPatient&);\
    friend void fever(cPatient&);\
    friend void fatigue(cPatient&);\
    friend void eyeIrritation(cPatient&);\
    friend void sneezing(cPatient&);\
    friend void muscularPain(cPatient&);\
}

#include "../types.h"
#include "cDisease.h"
#include "cPerson.h"

DEF;

#endif //KARUSAMPI_CPATIENT_H
