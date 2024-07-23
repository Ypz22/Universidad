#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct nodo{
    int dato;
    nodo *siguiente;
}nodo;

nodo *cabeza = NULL;

void insertarElementos(int dato){
    nodo *newNodo = new nodo();
    newNodo->dato = dato;
    newNodo->siguiente = NULL;
    if(cabeza == NULL){
        cabeza = newNodo;
    }else{
        nodo *actual = cabeza;
        while(actual->siguiente != NULL){
            actual = actual->siguiente;
        }actual->siguiente = newNodo;
    }
}

void imprimirLista(){
    nodo *actual = cabeza;
    if(cabeza == NULL){
        cout<<"La lista esta vacia"<<endl;
    }else{
        while(actual != NULL){
            cout<<actual->dato<<" |";
            actual = actual->siguiente;
        }cout<<endl;
    }
}

void ordenamientoSeleccion() {
    if (cabeza == NULL) {
        cout << "La lista esta vacia" << endl;
        return;
    }
    nodo *actual = cabeza;
    while (actual != NULL) {
        nodo *minimo = actual;
        nodo *temporal= actual->siguiente;
        while (temporal != NULL) {
            if (temporal->dato < minimo->dato) {
                minimo = temporal;
            }
            temporal = temporal->siguiente;
        }
        int temp = actual->dato;
        actual->dato = minimo->dato;
        minimo->dato = temp;

        actual = actual->siguiente;
    }
}

int main(){
    insertarElementos(35);
    insertarElementos(62);
    insertarElementos(56);
    insertarElementos(3);
    insertarElementos(16);
    imprimirLista();
    ordenamientoSeleccion();
    imprimirLista();
    return 0;
}