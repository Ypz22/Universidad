#include <iostream>
#include <stdlib.h>

class node {
public:
    int dato; // Variable para almacenar el dato del nodo.
    node *siguiente; // Puntero al siguiente nodo en la lista.
    node *previo; // Puntero al nodo previo en la lista.

    // Constructor de la clase node.
    node(int dato) {
        this->dato = dato; // Asigna el valor del dato al nodo.
        this->siguiente = NULL; // Inicializa el puntero al siguiente nodo como NULL.
        this->previo = NULL; // Inicializa el puntero al nodo previo como NULL.
    }
};


