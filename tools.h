#ifndef ACT_1_3_2_0_TOOLS_H
#define ACT_1_3_2_0_TOOLS_H
#include <vector>
using namespace std;


class tools {
public:
    static void cargarDocumento(string rutaDocumento, vector<string> &vectorAlmacen);
    static void ordenarDocumento(vector<string> &vectorAlmacen);
    static string obtenerFechas(string log);
    static string tokenizarChar(string &str, char charAtokenizar);
    static void swapNumbers(string& a, string& b);
    static void ordenaBurbuja(vector<string>&vectorOriginal, vector<string> &vectorFechas);
    static void imprimirDocumento(vector<string> vectorAlmacen);
};


#endif
