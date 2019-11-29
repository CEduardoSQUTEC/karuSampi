//
// Created by eduar on 28-Nov-19.
//

#ifndef KARUSAMPI_CPATIENT_H
#define KARUSAMPI_CPATIENT_H

#include "../types.h"
#include "cDisease.h"
#include "cPerson.h"

class cPatient : public cPerson {
private:
    text_t name;
    gender_t gender;
    age_t age;
    kilogram_t mass;
    meter_t height;
    mmhg_t systolicPressure;
    mmhg_t diastolicPressure;
    bpm_t heartRate;
    imc_t imc;
    cDisease disease;
public:
    cPatient(text_t &n, gender_t &g, age_t &a, kilogram_t &m, meter_t &h, mmhg_t &sP, mmhg_t &dP, bpm_t &hR) :
            cPerson(n, g, a, m, h, sP, dP, hR) {}

    text_t getDiseaseName() { return disease.getName(); }

    symptom_list_t& getDiseaseSymptoms(){return disease.getSymptoms();}

    friend void earlyAppearance(cPatient &cP);

    friend void constantSneezing(cPatient &cP);

    friend void soreThroat(cPatient &cP);

    friend void headache(cPatient &cP);

    friend void nasalCongestion(cPatient &cP);

    friend void extremeTiredness(cPatient &cP);

    friend void coughing(cPatient &cP);

    friend void thickMucus(cPatient &cP);

    friend void fever(cPatient &cP);

    friend void fatigue(cPatient &cP);

    friend void eyeIrritation(cPatient &cP);

    friend void sneezing(cPatient &cP);

    friend void muscularPain(cPatient &cP);
};

#endif //KARUSAMPI_CPATIENT_H
