#ifndef ACT_1_3_2_0_TOOLS_H
#define ACT_1_3_2_0_TOOLS_H
#include <vector>
using namespace std;

class tools {
private:
    static string tokenizarChar(string &str, char charAtokenizar);
    static void swapNumbers(string& a, string& b);
    static void quickSort(vector<string> &vectorOriginal, vector<string> &vectorFechas, int inicio, int fin);
    static string obtenerFechas(string log);
    static int busquedaBinaria(const vector<string>& vectorFechas, const string& fechaBuscada);
public:
    static void cargarDocumento(string rutaDocumento, vector<string> &vectorAlmacen);
    static void ordenarDocumento(vector<string> &vectorAlmacen);
    static void imprimirDocumento(vector<string> vectorAlmacen);
    static void busquedaDeFechas(vector<string>& vectorFechas);
    static void crearDocParaGuardar();
};


#endif
