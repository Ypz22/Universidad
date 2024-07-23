#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int tamano = 10;

int cadenaAEntero(const string& cadena) {
    try {
        size_t posicion;
        int numero = stoi(cadena, &posicion);
        if (posicion < cadena.size()) {
            throw invalid_argument("La cadena contiene caracteres no numéricos.");
        }
        return numero;
    } catch (const invalid_argument& e) {
        cerr << "Argumento inválido: " << e.what() << '\n';
        return 0;
    } catch (const out_of_range& e) {
        cerr << "Fuera de rango: " << e.what() << '\n';
        return 0;
    }
}

void escritura(string nombreArchivo, int a[], int cantidadDatos){
    ofstream fich(nombreArchivo);
    if (!fich) {
        cout << "Error al abrir el archivo\n";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < cantidadDatos; ++i) {
        fich << a[i] << endl;
    }
}

void lectura(int a[], string nombreArchivo, int cantidadDatos){
    ifstream archivo;
    string dato;
    int i = 0;

    archivo.open(nombreArchivo, ios::in);

    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivo.eof() && i < cantidadDatos) {
        getline(archivo, dato);
        if (dato.empty()) continue;
        int numero = cadenaAEntero(dato);
        a[i] = numero;
        i++;
    }
    for (; i < cantidadDatos; i++) {
        a[i] = 0;
    }
    archivo.close();
}

void imprimirArreglo(int a[], int tamano) {
    for (int i = 0; i < tamano; i++) {
        cout << a[i] << " |";
    }
    cout << endl;
}

void mezclaDirectArchivos(int archivo1[], int archivo2[], int archivo3[], int tamano1, int tamano2) {
    int i = 0, j = 0, k = 0;
    while (i < tamano1 && j < tamano2) {
        if (archivo1[i] <= archivo2[j]) {
            archivo3[k++] = archivo1[i++];
        } else {
            archivo3[k++] = archivo2[j++];
        }
    }
    while (i < tamano1) {
        archivo3[k++] = archivo1[i++];
    }
    while (j < tamano2) {
        archivo3[k++] = archivo2[j++];
    }
}



int main() {
    int archivo1[tamano];
    string nombreArchivo1 = "datos1.txt";
    int archivo2[tamano];
    string nombreArchivo2 = "datos2.txt";
    int archivo3[tamano * 2];
    string nombreArchivo3 = "datos3.txt";

    lectura(archivo1, nombreArchivo1, tamano);
    lectura(archivo2, nombreArchivo2, tamano);
    mezclaDirectArchivos(archivo1, archivo2, archivo3, tamano, tamano);
    escritura(nombreArchivo3, archivo3, tamano * 2);
    cout << "Archivo 1: ";
    imprimirArreglo(archivo1, tamano);
    cout << "Archivo 2: ";
    imprimirArreglo(archivo2, tamano);
    cout << "Archivo 3 (Mezclado): ";
    imprimirArreglo(archivo3, tamano * 2);

    return 0;

    return 0;
}
