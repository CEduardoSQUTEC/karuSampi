//
// Created by eduar on 28-Nov-19.
//

#ifndef KARUSAMPI_CPERSON_H
#define KARUSAMPI_CPERSON_H

#include "../types.h"

class cPerson {
protected:
    text_t name;
    // gender_t gender;
    age_t age;
    kilogram_t mass;
    meter_t height;
    mmhg_t systolicPressure;
    mmhg_t diastolicPressure;
    bpm_t heartRate;
    imc_t imc;
public:
    cPerson(text_t &n, age_t &a, kilogram_t &m, meter_t &h, mmhg_t &sP, mmhg_t &dP, bpm_t &hR) :
            name(std::move(n)), age(a), mass(m), height(m), systolicPressure(sP), diastolicPressure(dP), heartRate(hR),
            imc(m / h * h) {}

    cPerson(const text_t &n) : name(n) {}

    text_t getName() { return name; }

    // gender_t getGender() { return gender; }

    age_t getAge() { return age; }

    kilogram_t getMass() { return mass; }

    meter_t getHeight() { return height; }

    mmhg_t getSystolicPressure() { return systolicPressure; }

    mmhg_t getDiastolicPressure() { return diastolicPressure; }

    bpm_t getHeartRate() { return heartRate; }

    imc_t getImc() { return imc; }

};


#endif //KARUSAMPI_CPERSON_H
