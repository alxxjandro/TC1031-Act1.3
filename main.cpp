#include <iostream>
#include "tools.h"
#include <vector>
using namespace std;

//A01563388 Alonso Alarcon
//A01563697 Eliel Mejia
//A01563581 Samuel Lopez

int main() {
    vector<string> vectorDeLogs;
    tools::cargarDocumento("../bitacora.txt",vectorDeLogs);
    tools::ordenarDocumento(vectorDeLogs);
    //tools::imprimirDocumento(vectorDeLogs);
    tools::busquedaDeFechas(vectorDeLogs);
    return 0;
}
