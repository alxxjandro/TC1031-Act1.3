#include "tools.h"
#include <fstream>
#include <iostream>
#include <unordered_map>

void tools::swapNumbers(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

void tools::cargarDocumento(std::string rutaDocumento, vector<std::string> &vectorAlmacen) {
    ifstream archivo(rutaDocumento);
    string linea;
    //si regresa true, es pq hay algo en la linea
    while(getline(archivo,linea)){
        vectorAlmacen.push_back(linea);
    }
    archivo.close();
}

void tools::ordenarDocumento(vector<std::string> &vectorAlmacen) {
    //preapar para ordenar
    vector<string> temporal;
    //obtener la fecha en numeros y agregarla al principio de cada linea
    for (int i = 0; i < vectorAlmacen.size(); ++i) {
        //tools::tokenizarChar(vectorAlmacen[i],' ');
        temporal.push_back(tools::obtenerFechas(vectorAlmacen[i]));

        //agregarla al inicio del original
        //vectorAlmacen[i] = tools::obtenerFechas(vectorAlmacen[i]) + vectorAlmacen[i];
    }
    tools::quickSort(vectorAlmacen, temporal, 0, temporal.size()-1);
}

void tools::ordenaBurbuja(vector<string> &vectorOriginal, vector<string> &vectorFechas) {
    bool interruptor = true;
    int longitud = vectorFechas.size();
    int tmp = 0;
    for (int pasada = 0; pasada < longitud - 1 && interruptor; pasada++) {
        interruptor = false;
        for (int j = 0; j < longitud - 1 - pasada; j++) {
            if (vectorFechas[j + 1] < vectorFechas[j]) {
                // Intercambiar en vectorFechas
                swapNumbers(vectorFechas[j], vectorFechas[j + 1]);
                // Intercambiar en vectorOriginal
                swapNumbers(vectorOriginal[j], vectorOriginal[j + 1]);
                interruptor = true;
            }
        }
    }
}

void tools::quickSort(vector<string> &vectorOriginal, vector<string> &vectorFechas, int inicio, int fin) {
    int izq = inicio, der = fin;
    string pivote = vectorFechas[(izq + der) / 2];

    do {
        // Comparar las fechas para hacer el ordenamiento
        while (vectorFechas[izq] < pivote && izq < fin) {
            izq++;
        }
        while (vectorFechas[der] > pivote && der > inicio) {
            der--;
        }
        if (izq <= der) {
            // Intercambiar tanto en vectorFechas como en vectorOriginal
            swap(vectorFechas[izq], vectorFechas[der]);
            swap(vectorOriginal[izq], vectorOriginal[der]);
            izq++;
            der--;
        }
    } while (izq <= der);

    // Llamadas recursivas
    if (inicio < der) {
        quickSort(vectorOriginal, vectorFechas, inicio, der);
    }
    if (izq < fin) {
        quickSort(vectorOriginal, vectorFechas, izq, fin);
    }
}

string tools::obtenerFechas(std::string log) {
    unordered_map<string,string> mapa = {
            {"Jan","01"}, {"Feb","02"},{"Mar","03"},
            {"Apr","04"}, {"May","05"},{"Jun","06"},
            {"Jul","07"}, {"Aug","08"},{"Sep","09"},
            {"Oct","10"}, {"Nov","11"},{"Dec","12"},
    };
    string mes,dia,hora;
    mes = mapa.at(log.substr(0,3));

    //saber si el dia es de 1 o 2 digitos
    if (log[8] == ':'){
        //1 digitos
        dia = "0"+log.substr(4,1);
        hora = log.substr(6,8);
    } else{
        //2 digitos
        dia = log.substr(4,2);
        hora = log.substr(7,8);
    }
    return mes+"-"+dia+"-"+hora+" ";
}

string tools::tokenizarChar(string &str, char charAtokenizar) {
    char *ptr = &str[0];
    for (int i = 0; i < str.length(); ++i) {
        if (charAtokenizar == *ptr){
            &str.erase(i,1);}
        ptr++;
    }
    return str;
}

void tools::imprimirDocumento(vector<std::string> vectorAlmacen) {
    for (int i = 0; i < vectorAlmacen.size(); ++i) {
        cout << vectorAlmacen[i] << endl;
    }
}

void tools::busquedaDeFechas(vector<string>& vectorFechas) {
    /* como estamos buscando por MM-DD puede que el que encuentre no sea el primero ent
    recorremos para encontrar el primero y ultimo index respectivamente */
    string busquedaInicial, busquedaFinal;
    cout << "Introduce la fecha de inicio en el formato MM-DD (09-25): "; cin >> busquedaInicial;
    cout << "Introduce la fecha final en el formato MM-DD (09-25): "; cin >> busquedaFinal;

    int indexInicial = busquedaBinaria(vectorFechas, busquedaInicial);
    int indexFinal = busquedaBinaria(vectorFechas, busquedaFinal);

    if (indexInicial == -1 || indexFinal == -1) {
        cout << "Fecha no encontrada." << endl;
        return;
    }
    //encontrar el primer y el ultimo MM-DD igual
    while (indexInicial > 0 && obtenerFechas(vectorFechas[indexInicial - 1]).substr(0, 5) == busquedaInicial) {
        indexInicial--;
    }
    while (indexFinal < vectorFechas.size() - 1 && obtenerFechas(vectorFechas[indexFinal + 1]).substr(0, 5) == busquedaFinal) {
        indexFinal++;
    }
    //imprimirlos
    for (int i = indexInicial; i <= indexFinal ; ++i) {
        cout << vectorFechas[i] << endl;
    }
}

int tools::busquedaBinaria(const vector<string>& vectorFechas, const string& fechaBuscada) {
    int inicio = 0;
    int fin = vectorFechas.size() - 1;
    int mejorMatch = -1;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        //"MM-DD-HH:MM:SS"
        string fechaActualFormateada = tools::obtenerFechas(vectorFechas[medio]);
        //convertir a "MM-DD"
        string fechaActualCorta = fechaActualFormateada.substr(0, 5);

        //buscar con "MM-DD"
        if (fechaActualCorta == fechaBuscada) {
            return medio;
        }
        if (fechaActualCorta < fechaBuscada) {
            mejorMatch = medio;
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return mejorMatch;
}
