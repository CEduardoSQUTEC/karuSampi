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

#endif //KARUSAMPI_CDOCTOR_H
