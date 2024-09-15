#include <iostream>
#include "tools.h"
#include <vector>
using namespace std;

int main() {
    vector<string> vectorDeLogs;
    tools::cargarDocumento("/Users/alonsoparra/TC1031/act-1.3-2.0/bitacora.txt",vectorDeLogs);

    tools::ordenarDocumento(vectorDeLogs);
    tools::imprimirDocumento(vectorDeLogs);

    //test


    return 0;
}
