#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void intercalacionArchivos(string archivo1, string archivo2, string archivoSalida) {
    ifstream entradaArchivo1(archivo1);
    ifstream entradaArchivo2(archivo2);
    ofstream salidaArchivo(archivoSalida);

    if (!entradaArchivo1.is_open() || !entradaArchivo2.is_open() || !salidaArchivo.is_open()) {
        cerr << "Error al abrir los archivos" << endl;
        return;
    }

    int datoArchivo1, datoArchivo2;
    bool archivoTerminado1 = !(entradaArchivo1 >> datoArchivo1);
    bool archivoTerminado2 = !(entradaArchivo2 >> datoArchivo2);

    while (!archivoTerminado1 || !archivoTerminado2) {
        if (archivoTerminado1) {
            salidaArchivo << datoArchivo2 << " ";
            archivoTerminado2 = !(entradaArchivo2 >> datoArchivo2);
        } else if (archivoTerminado2) {
            salidaArchivo << datoArchivo1 << " ";
            archivoTerminado1 = !(entradaArchivo1 >> datoArchivo1);
        } else if (datoArchivo1 < datoArchivo2) {
            salidaArchivo << datoArchivo1 << " ";
            archivoTerminado1 = !(entradaArchivo1 >> datoArchivo1);
        } else {
            salidaArchivo << datoArchivo2 << " ";
            archivoTerminado2 = !(entradaArchivo2 >> datoArchivo2);
        }
    }

    entradaArchivo1.close();
    entradaArchivo2.close();
    salidaArchivo.close();
}

int main() {
    intercalacionArchivos("datos1.txt", "datos2.txt", "datos3.txt");
    return 0;
}
