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
    cDisease disease();
public:
    cPatient(text_t &n, age_t &a, kilogram_t &m, meter_t &h, mmhg_t &sP, mmhg_t &dP, bpm_t &hR) :
            cPerson(n, a, m, h, sP, dP, hR) {}

    text_t getDiseaseName() { return disease().getName(); }

    symptom_list_t getDiseaseSymptoms() { return disease().getSymptoms(); }


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

    friend void diagnostic(cPatient &cP);

    friend void earlyAppearance(cPatient &cP);
};

#endif //KARUSAMPI_CPATIENT_H
