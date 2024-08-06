#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int tamano = 6;

void merge(int a[], int izquierda, int medio, int derecha) {
    int aux1 = medio - izquierda + 1;
    int aux2 = derecha - medio;

    int mitadIzquierda[tamano];
    int mitadDerecha[tamano];

    for (int i = 0; i < aux1; i++)
        mitadIzquierda[i] = a[izquierda + i];
    for (int i = 0; i < aux2; i++)
        mitadDerecha[i] = a[medio + 1 + i];

    int i = 0, j = 0, k = izquierda;
    while (i < aux1 && j < aux2) {
        if (mitadIzquierda[i] <= mitadDerecha[j]) {
            a[k] = mitadIzquierda[i];
            i++;
        } else {
            a[k] = mitadDerecha[j];
            j++;
        }
        k++;
    }

    while (i < aux1) {
        a[k] = mitadIzquierda[i];
        i++;
        k++;
    }

    while (j < aux2) {
        a[k] = mitadDerecha[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int izquierda, int derecha) {
    if (izquierda >= derecha)
        return;

    int medio = izquierda + (derecha - izquierda) / 2;
    mergeSort(a, izquierda, medio);
    mergeSort(a, medio + 1, derecha);
    merge(a, izquierda, medio, derecha);
}

void imprimirArreglo(int a[]) {
    for (int i = 0; i < tamano; i++) {
        cout << a[i] << " |";
    }
    cout << endl;
}

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
    intercalacionArchivos("datos1.txt", "datos2.txt", "datos3.txt");
    int a[] = {12, 11, 13, 5, 6, 7};

    cout << "Arreglo inicial: ";
    imprimirArreglo(a);
    mergeSort(a, 0, tamano - 1);

    cout << "Array ordenado: ";
    imprimirArreglo(a);

    ordenarArchivo("datosDesordenados.txt", "datosOrdenados.txt");

    return 0;
}