#include <iostream>
#include <stdlib.h>

class Arbol{
public:
    int dato;
    Arbol *derecha;
    Arbol *izquierda;

    Arbol(int dato){
        this->dato = dato;
        this->derecha = NULL;
        this->izquierda = NULL;
    }
};
