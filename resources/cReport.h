//
// Created by eduar on 28-Nov-19.
//

#ifndef KARUSAMPI_CREPORT_H
#define KARUSAMPI_CREPORT_H

#include "cPatient.h"
#include "cDoctor.h"
#include "cMedicine.h"

class cReport {
    cPatient* pPatient;
    cDoctor* pDoctor;
    cMedicine* pMedicine;
    void findDoctor();
    void findMedicine();
public:
    cReport(cPatient* pP): pPatient(pP), pDoctor(nullptr), pMedicine(nullptr) {}
    void print();
};

#endif //KARUSAMPI_CREPORT_H
