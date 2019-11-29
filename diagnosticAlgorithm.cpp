//
// Created by eduar on 28-Nov-19.
//

#include "diagnosticAlgorithm.h"
#include "resources/cSymptom.h"
#include "resources/cPatient.h"

state_t answer() {
    string ans;
    do {
        cout << "\nRespuesta: ";
        cin >> ans;
        for (auto &c: ans) c = tolower(c);
        if (ans == "si" || ans == "1")
            return true;
        else if (ans == "no" || ans == "0")
            return false;
        else cout << "\nNo es una respuesta valida\n";
    } while (true);
}

void earlyAppearance(cPatient &cP) {
    cout << "¿Sus estornudos se manifestaron de manera rapida?" << endl;
    state_t presence = answer();
    if (presence) {
        cSymptom objCS("Early appearance of Sneezing", presence);
        cP.disease.addSymptom(objCS);
    }
}

void constantSneezing(cPatient &cP) {
    cout << "¿Presenta muchos estornudos seguidos en racha?" << endl;
    state_t presence = answer();
    if (presence) {
        cSymptom objCS("Constant Sneezing", presence);
        cP.disease.addSymptom(objCS);
    } else earlyAppearance(cP);
}

void soreThroat(cPatient &cP) {
    cout << "¿Le duele la garganta?" << endl;
    state_t presence = answer();
    if (presence) {
        cSymptom objCS("Sore Throat", presence);
        cP.disease.addSymptom(objCS);
        headache(cP);
    } else nasalCongestion(cP);
}

void headache(cPatient &cP) {
    cout << "¿Le duele la cabeza?" << endl;
    state_t presence = answer();
    if (presence) {
        cSymptom objCS("Headache", presence);
        cP.disease.addSymptom(objCS);
        extremeTiredness(cP);
    } else nasalCongestion(cP);
}

void nasalCongestion(cPatient &cP) {
    cout << "¿Tiene congestion nasal?" << endl;
    state_t presence = answer();
    if (presence) {
        cSymptom objCS("Nasal Congestion", presence);
        cP.disease.addSymptom(objCS);
        coughing(cP);
    } else thickMucus(cP);
}

void extremeTiredness(cPatient &cP) {
    cout << "¿Tiene agotamiento extremo?" << endl;
    state_t presence = answer();
    if (presence) {
        cSymptom objCS("Extreme Tiredness", presence);
        cP.disease.addSymptom(objCS);
        fever(cP);
    } else fatigue(cP);
}

void coughing(cPatient &cP) {
    cout << "¿Tiene tos?" << endl;
    state_t presence = answer();
    if (presence) {
        cSymptom objCS("Coughing", presence);
        cP.disease.addSymptom(objCS);
        extremeTiredness(cP);
    } else fatigue(cP);
}

void thickMucus(cPatient &cP) {
    cout << "¿Su mucosidad es espesa?" << endl;
    state_t presence = answer();
    if (presence) {
        cSymptom objCS("Thick Mucosity", presence);
        cP.disease.addSymptom(objCS);
        coughing(cP);
    } else eyeIrritation(cP);
}

void fever(cPatient &cP) {
    cout << "¿Tiene fiebre?" << endl;
    state_t presence = answer();
    if (presence) {
        cSymptom objCS("Fever", presence);
        cP.disease.addSymptom(objCS);
        muscularPain(cP);
    } else sneezing(cP);
}

void fatigue(cPatient &cP) {
    cout << "¿Tiene fatiga?" << endl;
    state_t presence = answer();
    if (presence) {
        cSymptom objCS("Fatigue", presence);
        cP.disease.addSymptom(objCS);
        fever(cP);
    } else sneezing(cP);
}

void eyeIrritation(cPatient &cP) {
    cout << "¿Sus ojos estan irritados o producen lagrimeo?" << endl;
    state_t presence = answer();
    if (presence) {
        cSymptom objCS("Eye Irritation", presence);
        cP.disease.addSymptom(objCS);
        sneezing(cP);
    } else fatigue(cP);
}

void sneezing(cPatient &cP) {
    cout << "¿Estornuda?" << endl;
    state_t presence = answer();
    if (presence) {
        cSymptom objCS("Sneezing", presence);
        cP.disease.addSymptom(objCS);
        constantSneezing(cP);
    } else earlyAppearance(cP);
}

void muscularPain(cPatient &cP) {
    cout << "¿Presenta dolores musculares?" << endl;
    state_t presence = answer();
    if (presence) {
        cSymptom objCS("Muscular Pain", presence);
        cP.disease.addSymptom(objCS);
    } else sneezing(cP);
}

