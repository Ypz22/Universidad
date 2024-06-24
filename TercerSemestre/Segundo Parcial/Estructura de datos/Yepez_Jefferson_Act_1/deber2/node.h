#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class node {
public:
    string premio; // Variable para almacenar el premio del nodo.
    node *siguiente; // Puntero al siguiente nodo en la lista.
    node *previo; // Puntero al nodo previo en la lista.

    // Constructor de la clase node.
    node(string premio) {
        this->premio = premio; // Asigna el valor del premio al nodo.
        this->siguiente = NULL; // Inicializa el puntero al siguiente nodo como NULL.
        this->previo = NULL; // Inicializa el puntero al nodo previo como NULL.
    }
};

