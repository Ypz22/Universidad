#include "arbol.h"

using namespace std;

class ArbolFunciones{
public:
    Arbol *raiz;

    ArbolFunciones(int datoInicial) {
        raiz = new Arbol(datoInicial);
    }

    void insertarArbol(int dato) {
        insertar(raiz, dato);
    }

    void inOrdenArbol(Arbol *nodo) {
        if (nodo != NULL) {
            inOrdenArbol(nodo->izquierda);
            cout << nodo->dato << " ";
            inOrdenArbol(nodo->derecha);
        }
    }

    void preOrdenArbol(Arbol *nodo) {
        if (nodo != NULL) {
            cout << nodo->dato << " ";
            preOrdenArbol(nodo->izquierda);
            preOrdenArbol(nodo->derecha);
        }
    }

    void postOrden(Arbol *nodo) {
        if (nodo != NULL) {
            postOrden(nodo->izquierda);
            postOrden(nodo->derecha);
            cout << nodo->dato << " ";
        }
    }

    void insertar(Arbol *nodo, int dato) {
        if (dato < nodo->dato) {
            if (nodo->izquierda == NULL) {
                nodo->izquierda = new Arbol(dato);
            } else {
                insertar(nodo->izquierda, dato);
            }
        } else {
            if (nodo->derecha == NULL) {
                nodo->derecha = new Arbol(dato);
            } else {
                insertar(nodo->derecha, dato);
            }
        }
    }
};







