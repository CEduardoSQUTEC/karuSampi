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


cSymptom earlyAppearance_obj("Early appearance", false);
cSymptom constantSneezing_obj("Constant Sneezing", false);
cSymptom soreThroat_obj("Sore Throat", false);
cSymptom headache_obj("Headache", false);
cSymptom nasalCongestion_obj("Nasal Congestion", false);
cSymptom extremeTiredness_obj("Extreme Tiredness",false);
cSymptom coughing_obj("Coughing",false);
cSymptom thickMucus_obj("Thick Mucosity",false);
cSymptom fever_obj("Fever", false);
cSymptom fatigue_obj("Fatigue",false);
cSymptom eyeIrritation_obj("Eye Irritation", false);
cSymptom sneezing_obj("Sneezing",false);
cSymptom muscularPain_obj("Muscular Pain", false);


symptom_list_t Flu = {fever_obj, soreThroat_obj, headache_obj, extremeTiredness_obj, fatigue_obj, muscularPain_obj, earlyAppearance_obj, coughing_obj, nasalCongestion_obj};
symptom_list_t Cold = {soreThroat_obj, headache_obj,sneezing_obj, nasalCongestion_obj, thickMucus_obj};
symptom_list_t Allergies = {nasalCongestion_obj, sneezing_obj, constantSneezing_obj, eyeIrritation_obj};


void earlyAppearance(cPatient &cP) {
    cout << "¿Sus malestares se manifestaron de manera rapida?" << endl;
    state_t presence = answer();
    if (presence) {
        earlyAppearance_obj.setPresence(true);
    }
}

void constantSneezing(cPatient &cP) {
    cout << "¿Presenta muchos estornudos seguidos en racha?" << endl;
    state_t presence = answer();
    if (presence) {
        constantSneezing_obj.setPresence(true);
    } else earlyAppearance(cP);
}

void soreThroat(cPatient &cP) {
    cout << "¿Le duele la garganta?" << endl;
    state_t presence = answer();
    if (presence) {
        soreThroat_obj.setPresence(true);
        headache(cP);
    } else nasalCongestion(cP);
}

void headache(cPatient &cP) {
    cout << "¿Le duele la cabeza?" << endl;
    state_t presence = answer();
    if (presence) {
        headache_obj.setPresence(true);
        extremeTiredness(cP);
    } else nasalCongestion(cP);
}

void nasalCongestion(cPatient &cP) {
    cout << "¿Tiene congestion nasal?" << endl;
    state_t presence = answer();
    if (presence) {
        nasalCongestion_obj.setPresence(true);
        coughing(cP);
    } else thickMucus(cP);
}

void extremeTiredness(cPatient &cP) {
    cout << "¿Tiene agotamiento extremo?" << endl;
    state_t presence = answer();
    if (presence) {
        extremeTiredness_obj.setPresence(true);
        fever(cP);
    } else fatigue(cP);
}

void coughing(cPatient &cP) {
    cout << "¿Tiene tos?" << endl;
    state_t presence = answer();
    if (presence) {
        coughing_obj.setPresence(true);
        extremeTiredness(cP);
    } else fatigue(cP);
}

void thickMucus(cPatient &cP) {
    cout << "¿Su mucosidad es espesa?" << endl;
    state_t presence = answer();
    if (presence) {
        thickMucus_obj.setPresence(true);
        coughing(cP);
    } else eyeIrritation(cP);
}

void fever(cPatient &cP) {
    cout << "¿Tiene fiebre?" << endl;
    state_t presence = answer();
    if (presence) {
        fever_obj.setPresence(true);
        muscularPain(cP);
    } else sneezing(cP);
}

void fatigue(cPatient &cP) {
    cout << "¿Tiene fatiga?" << endl;
    state_t presence = answer();
    if (presence) {
        fatigue_obj.setPresence(true);
        fever(cP);
    } else sneezing(cP);
}

void eyeIrritation(cPatient &cP) {
    cout << "¿Sus ojos estan irritados o producen lagrimeo?" << endl;
    state_t presence = answer();
    if (presence) {
        eyeIrritation_obj.setPresence(true);
        sneezing(cP);
    } else fatigue(cP);
}

void sneezing(cPatient &cP) {
    cout << "¿Estornuda?" << endl;
    state_t presence = answer();
    if (presence) {
        sneezing_obj.setPresence(true);
        constantSneezing(cP);
    } else earlyAppearance(cP);
}

void muscularPain(cPatient &cP) {
    cout << "¿Presenta dolores musculares?" << endl;
    state_t presence = answer();
    if (presence) {
        muscularPain_obj.setPresence(true);
    } else sneezing(cP);
}


void diagnose(){
    int counterCold = 0;
    int counterFlu = 0;
    int counterAllergies = 0;
    for (unsigned int i = 0; i < Cold.size(); i++){
        if (Cold[i].getPresence() == 1)
            counterCold++;
    }
    for (unsigned int i = 0; i < Flu.size(); i++){
        if (Flu[i].getPresence() == 1)
            counterFlu++;
    }
    for (unsigned int i = 0; i < Allergies.size(); i++){
        if (Allergies[i].getPresence() == 1)
            counterAllergies++;
    }

    if (counterCold > counterAllergies && counterCold > counterFlu)
        cDisease patientDisease("Resfrio");
    if (counterAllergies > counterCold && counterFlu)
        cDisease patientDisease("Alergia");
    if (counterFlu > counterAllergies && counterFlu > counterCold)
        cDisease patientDisease("Gripe");
    else
        cDisease patientDisease("Resfrio");
}

void diagnostic(cPatient &cP){
    cout<<"Ahora, ¿puedes contarme sobre tus síntomas," << cP.getName() <<"?";
    soreThroat(cP);
    diagnose();
    cout << "Usted ha sido diagnosticado con: " << patientDisease.getName() << endl;
}
