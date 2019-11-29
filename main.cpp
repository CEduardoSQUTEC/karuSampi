#include "interface.h"
#include "resources/cPatient.h"
#include "diagnosticAlgorithm.h"
#include "resources/cReport.h"

int main() {
    text_t n;
    age_t a;
    kilogram_t m;
    meter_t h;
    mmhg_t sP;
    mmhg_t dP;
    bpm_t hR;
    greeting(n, a, m, h, sP, dP, hR);
    cPatient cP(n, a, m, h, sP, dP, hR);
    diagnostic(cP);
    cPatient* pCP = &cP;
    cReport cR(pCP);
    menu(cR);
    return 0;
}