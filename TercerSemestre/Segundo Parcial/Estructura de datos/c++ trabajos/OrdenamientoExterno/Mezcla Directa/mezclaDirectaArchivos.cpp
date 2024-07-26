#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void dividirArchivos(string archivoEntrada, string archivoF1, string archivoF2) {
    ifstream entrada(archivoEntrada);
    ofstream salidaAuxiliar1(archivoF1);
    ofstream salidaAuxiliar2(archivoF2);

    if (!entrada.is_open() || !salidaAuxiliar1.is_open() || !salidaAuxiliar2.is_open()) {
        cerr << "Error al abrir los archivos" << endl;
        return;
    }

    int datosArchivo;
    bool alternar = false;
    while (entrada >> datosArchivo) {
        if (alternar) {
            salidaAuxiliar2 << datosArchivo << " ";
        } else {
            salidaAuxiliar1 << datosArchivo << " ";
        }
        alternar = !alternar;
    }

    entrada.close();
    salidaAuxiliar1.close();
    salidaAuxiliar2.close();
}

void mezclarArchivos(string archivoF1, string archivoF2, string archivoSalida) {
    ifstream entradaF1(archivoF1);
    ifstream entradaF2(archivoF2);
    ofstream salida(archivoSalida);

    if (!entradaF1.is_open() || !entradaF2.is_open() || !salida.is_open()) {
        cerr << "Error al abrir los archivos" << endl;
        return;
    }

    int datosArchivoF1, datosArchivoF2;
    bool leerF1 = bool(entradaF1 >> datosArchivoF1);
    bool leerF2 = bool(entradaF2 >> datosArchivoF2);

    while (leerF1 && leerF2) {
        if (datosArchivoF1 <= datosArchivoF2) {
            salida << datosArchivoF1 << " ";
            leerF1 = bool(entradaF1 >> datosArchivoF1);
        } else {
            salida << datosArchivoF2 << " ";
            leerF2 = bool(entradaF2 >> datosArchivoF2);
        }
    }

    while (leerF1) {
        salida << datosArchivoF1 << " ";
        leerF1 = bool(entradaF1 >> datosArchivoF1);
    }

    while (leerF2) {
        salida << datosArchivoF2 << " ";
        leerF2 = bool(entradaF2 >> datosArchivoF2);
    }

    entradaF1.close();
    entradaF2.close();
    salida.close();
}

void ordenarArchivo(string archivoEntrada, string archivoSalida) {
    string archivoF1 = "archivoAuxiliar1.txt";
    string archivoF2 = "archivoAuxiliar2.txt";

    dividirArchivos(archivoEntrada, archivoF1, archivoF2);
    mezclarArchivos(archivoF1, archivoF2, archivoSalida);

    int subsecuencia = 2;
    while (true) {
        dividirArchivos(archivoSalida, archivoF1, archivoF2);
        mezclarArchivos(archivoF1, archivoF2, archivoSalida);
        subsecuencia *= 2;

        ifstream entrada(archivoSalida);
        int datosArchivoAnterior, datosArchivo;
        bool ordenado = true;

        if (entrada >> datosArchivoAnterior) {
            while (entrada >> datosArchivo) {
                if (datosArchivoAnterior > datosArchivo) {
                    ordenado = false;
                    break;
                }
                datosArchivoAnterior = datosArchivo;
            }
        }

        entrada.close();
        if (ordenado) break;
    }
}

int main() {
    ordenarArchivo("datosDesordenados.txt", "datosOrdenados.txt");
    return 0;
}
