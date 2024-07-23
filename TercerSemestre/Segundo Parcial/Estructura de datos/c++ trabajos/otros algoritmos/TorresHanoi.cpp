#include <iostream>
#include <stack>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

void push(Nodo*& cabeza, int dato) {
    Nodo* nuevo = crearNodo(dato);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

int pop(Nodo*& cabeza) {
    if (cabeza == nullptr) {
        cerr << "Error: la pila está vacía." << endl;
        return -1; // Valor de error
    }
    int dato = cabeza->dato;
    Nodo* temp = cabeza;
    cabeza = cabeza->siguiente;
    delete temp;
    return dato;
}

void moverDisco(Nodo*& origen, Nodo*& destino, char torreOrigen, char torreDestino) {
    int disco = pop(origen);
    push(destino, disco);
    cout << "Mover disco " << disco << " de torre " << torreOrigen << " a torre " << torreDestino << endl;
}

void torresDeHanoi(int numDiscos, Nodo*& torreOrigen, Nodo*& torreAuxiliar, Nodo*& torreDestino) {
    if (numDiscos == 1) {
        moverDisco(torreOrigen, torreDestino, 'A', 'C');
    } else {
        torresDeHanoi(numDiscos - 1, torreOrigen, torreDestino, torreAuxiliar);
        moverDisco(torreOrigen, torreDestino, 'A', 'C');
        torresDeHanoi(numDiscos - 1, torreAuxiliar, torreOrigen, torreDestino);
    }
}

void imprimirPila(Nodo* cabeza, const string& nombrePila) {
    cout << "Contenido de la pila " << nombrePila << ": ";
    while (cabeza != nullptr) {
        cout << cabeza->dato << " ";
        cabeza = cabeza->siguiente;
    }
    cout << endl;
}

int main() {
    int numDiscos = 3;
    Nodo* torreA = nullptr;
    Nodo* torreB = nullptr;
    Nodo* torreC = nullptr;

    for (int i = numDiscos; i > 0; --i) {
        push(torreA, i);
    }

    imprimirPila(torreA, "A");
    imprimirPila(torreB, "B");
    imprimirPila(torreC, "C");

    torresDeHanoi(numDiscos, torreA, torreB, torreC);

    imprimirPila(torreA, "A");
    imprimirPila(torreB, "B");
    imprimirPila(torreC, "C");

    while (torreA != nullptr) {
        pop(torreA);
    }
    while (torreB != nullptr) {
        pop(torreB);
    }
    while (torreC != nullptr) {
        pop(torreC);
    }

    return 0;
}
