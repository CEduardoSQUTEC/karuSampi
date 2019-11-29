//
// Created by eduar on 28-Nov-19.
//

#ifndef KARUSAMPI_CDISEASE_H
#define KARUSAMPI_CDISEASE_H

#include "../types.h"
#include "cSymptom.h"

using symptom_list_t = vector<cSymptom>;

class cDisease {
    text_t name;
    symptom_list_t symptoms;
public:
    cDisease();
    explicit cDisease(const text_t& name) : name("Unknown") {}

    void addSymptom(cSymptom &cS) { symptoms.emplace_back(cS); }

    void detectDisease();
    text_t getName() {return name;}
    symptom_list_t &getSymptoms() {return symptoms;}
};

#endif //KARUSAMPI_CDISEASE_H
