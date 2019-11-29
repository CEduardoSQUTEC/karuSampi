//
// Created by eduar on 28-Nov-19.
//

#ifndef KARUSAMPI_CSYMPTOM_H
#define KARUSAMPI_CSYMPTOM_H

#include "../types.h"

class cSymptom {
    text_t name;
    state_t presence;
public:
    cSymptom(const text_t &n, state_t p) : name(n), presence(p) {}
    void setPresence(state_t p) {presence = p;}

    text_t getName() { return name; }
};

/* ostream &operator<<(ostream &os,cSymptom &cS) {
    os << cS.getName();
    return os;
} */

#endif //KARUSAMPI_CSYMPTOM_H
