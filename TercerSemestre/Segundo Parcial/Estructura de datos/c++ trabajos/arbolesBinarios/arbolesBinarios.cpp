#include <iostream>
#include <stdlib.h>
#include "arbolFuciones.h"

using namespace std;

int main() {
    ArbolFunciones arbol(10);

    arbol.insertarArbol(1);
    arbol.insertarArbol(2);
    arbol.insertarArbol(3);
    arbol.insertarArbol(4);
    arbol.insertarArbol(5);
    arbol.insertarArbol(6);
    arbol.insertarArbol(8);
    arbol.insertarArbol(11);


    cout << "In-Orden: ";
    arbol.inOrdenArbol(arbol.raiz);
    cout << endl;

    cout << "Pre-Orden: ";
    arbol.preOrdenArbol(arbol.raiz);
    cout << endl;

    cout << "Post-Orden: ";
    arbol.postOrden(arbol.raiz);
    cout << endl;

    return 0;
}
