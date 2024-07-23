#include <iostream>
using namespace std;

struct nodo {
    float dato;
    nodo *siguiente;
};

int tamano = 10;

int obtenerEntero(float valor) {
    return static_cast<int>(valor);  
}

void insertarElemento(nodo* b[], int indice, float valor) {
    nodo *nuevo = new nodo();
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (b[indice] == 0) {
        b[indice] = nuevo;  
    } else {
        nodo *actual = b[indice];
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

void ordenamiento(float a[]) {
    nodo *b[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i = 0; i < tamano; i++) {
        int auxiliar = obtenerEntero((a[i]) * tamano);
        insertarElemento(b, auxiliar, a[i]);
    }
    for(int i = 0; i < 10; i++) {
        if(b[i] != 0) {
            nodo *cabeza = b[i];
            nodo *actual = cabeza;
            while(actual->siguiente != NULL) {
                nodo *temporal = cabeza;
                while(temporal->siguiente != NULL) {
                    if(temporal->dato > temporal->siguiente->dato) {
                        float auxiliar = temporal->dato;
                        temporal->dato = temporal->siguiente->dato;
                        temporal->siguiente->dato = auxiliar;
                    }
                    temporal = temporal->siguiente;
                }
                actual = actual->siguiente;
            }
        }
    }
    int indiceA = 0;
    for(int i = 0; i < 10; i++) {
        if(b[i] != 0) {
            nodo *cabeza = b[i];
            nodo *actual = cabeza;
            while(actual != NULL) {
                a[indiceA] = actual->dato;
                indiceA++;
                actual = actual->siguiente;
            }
        }
    }
}

int main() {
    float a[tamano] = {0.76,0.17,0.39,0.26,0.72,0.94,0.21,0.12,0.23,0.68};

    cout << "Array original: ";
    for (int i = 0; i < tamano; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    ordenamiento(a);

    cout << "Array ordenado: ";
    for (int i = 0; i < tamano; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
