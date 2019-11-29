//
// Created by eduar on 28-Nov-19.
//

#ifndef KARUSAMPI_CDOCTOR_H
#define KARUSAMPI_CDOCTOR_H

#include "../types.h"
#include "cPerson.h"

class cDoctor: public cPerson{
public:
    explicit cDoctor(text_t &n): cPerson(n){}
};

/* ostream& operator<<(ostream &os, cDoctor& cD){
    os << cD.getName();
    return os;
} */

#endif //KARUSAMPI_CDOCTOR_H
