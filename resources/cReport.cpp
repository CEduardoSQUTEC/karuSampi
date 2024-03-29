//
// Created by eduar on 28-Nov-19.
//

#include "cReport.h"

void cReport::findDoctor() {
    cDoctor cD ("Otorrinolaringolo");
    pDoctor = &cD;
}

void cReport::findMedicine() {
    cMedicine cM ("Ninguna", 0);
    pMedicine = &cM;
}

void cReport::print(ostream &o) {
    o << "\nPaciente: " << pPatient->getName() << '\n';

    o << "\nSignos y datos:\n";
    //  o << "Sexo: " << pPatient->getGender() << '\n';
    o << "Edad: " << pPatient->getAge() << '\n';
    o << "Peso: " << pPatient->getMass() << '\n';
    o << "Altura: " << pPatient->getHeight() << '\n';
    o << "Presion Sistolica: " << pPatient->getSystolicPressure() << '\n';
    o << "Presion Diastolica: " << pPatient->getDiastolicPressure() << '\n';
    o << "Ritmo Cardiaco: " << pPatient->getHeartRate() << '\n';
    o << "IMC: " << pPatient->getImc() << '\n';

    o << "\nEnfermedad: " << pPatient->getDiseaseName() << '\n';

    o << "\nSintomas:\n";
    for (auto &cS: pPatient->getDiseaseSymptoms()) o << cS.getName() << '\n';
    o << '\n';

    o << "\nDoctor: " << pDoctor->getName() << '\n';

    o << "\nMedicina: " << pMedicine->getName() << '\n';

}
