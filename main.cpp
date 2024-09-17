#include <iostream>
#include "tools.h"
#include <vector>
#include <filesystem>
using namespace std;

int main() {
    vector<string> vectorDeLogs;
    tools::cargarDocumento("../bitacora.txt",vectorDeLogs);

    tools::ordenarDocumento(vectorDeLogs);
    tools::imprimirDocumento(vectorDeLogs);



    return 0;
}
