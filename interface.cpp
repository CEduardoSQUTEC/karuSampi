#include "interface.h"

void greeting(text_t &n, age_t &a, kilogram_t &m, meter_t &h, mmhg_t &sP, mmhg_t &dP, bpm_t &hR) {
    cout << "\n¡Hola! Mi nombre es Karu, tu asistente médico. ¿Podrías decirme tu nombre?\n";
    cin >> n;
    cout << "\nMuy bonito nombre." << "¿Cuántos años tienes?\n";
    cin >> a;
    cout << "\n¿Cuánto pesas y cuánto mides? ¡Sin mentir!\n";
    cin >> m >> h;
    cout << "\nMuy bien. Ahora, indique al asistente que ingrese su presión sistolica y diastolica, por favor\n";
    cin >> sP >> dP;
    cout << "\nY última pregunta, nuevamente el asistente ingrese el pulso cardiaco. ¡Tranquilo! Ya casi terminamos.\n";
    cin >> hR;
    cout << "\n¡Increíble! Muchas gracias por responder. Voy a procesar algunos de tus datos.\n";
}

void menu(cReport &cR) {
    char in;
    cout << "\nOK, hemos terminado tenemos las siguientes opciones para ti: \n";
    cout << "0: Imprimir tu reporte en la pantalla?\n";
    /* cout << "1: Imprimir tu reporte en un archivo?\n";
       cout << "2: Eres otra persona deseas que te hagos un diagnostico?\n"; */
    cout << "3: Salir\n";
    cout << "Respuesta: ";
    cin >> in;

    if (in == '0') {
        cR.print(cout);
        menu(cR);
        /* } else if (in == '1') {
             // ofstream fileReport;
             // fileReport.open("Reporte.txt");
             // cR.print(fileReport);
             menu(cR);
         } else if (in == '2') {
             greeting(); */
    } else {
        cout << "\nRespuesta invalida\n";
        menu(cR);
    }
}
