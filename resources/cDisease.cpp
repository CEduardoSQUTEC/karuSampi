//
// Created by eduar on 28-Nov-19.
//

#include "cDisease.h"

void cDisease::detectDisease() {
    vector<text_t> Flu = {"Fever", "Sore Throat", "Headache", "Extreme Tiredness", "Fatigue", "Muscular Paint", "Early Appearance", "Coughing", "Nasal Congestion"};
    vector<text_t> Cold = {"Sore Throat", "Headache", "Sneezing", "Nasal Congestion", "Thick Mucus"};
    vector<text_t> Allergies = {"Nasal Congestion" , "Sneezing" , "Constant Sneezing", "Eye Irritation"};

    size_t contFlu = 0;
    size_t contCold = 0;
    size_t contAll = 0;

    for (cSymptom &s: symptoms) {
        if ((std::find(Flu.begin(), Flu.end(), s.getName()) != Flu.end()) && s.getPresence()) ++contFlu;
        if ((std::find(Cold.begin(), Cold.end(), s.getName()) != Cold.end()) && s.getPresence()) ++contCold;
        if ((std::find(Allergies.begin(), Allergies.end(), s.getName()) != Allergies.end()) && s.getPresence()) ++contAll;

        size_t maxCont = max(max(contFlu, contCold), contAll);
        if ((maxCont == contAll && maxCont == contCold) || (maxCont == contAll == contFlu));
        else if (maxCont == contAll) this->name = "Allergies";
        else if (maxCont == contCold) this->name = "Cold";
        else if (maxCont == contFlu) this->name = "Flu";
    }
}
