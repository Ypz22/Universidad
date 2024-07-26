#include <iostream>

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

int main() {
    int a[] = {12, 11, 13, 5, 6, 7};

    cout << "Arreglo inicial: ";
    imprimirArreglo(a);
    mergeSort(a, 0, tamano - 1);

    cout << "Array ordenado: ";
    imprimirArreglo(a);

    return 0;
}
