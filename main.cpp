#include <iostream>
#include "tools.h"
#include <vector>
using namespace std;

int main() {
    vector<string> vectorDeLogs;
    tools::cargarDocumento("../bitacora.txt",vectorDeLogs);
    tools::ordenarDocumento(vectorDeLogs);
    //tools::imprimirDocumento(vectorDeLogs);
    tools::busquedaDeFechas(vectorDeLogs);
    return 0;
}
