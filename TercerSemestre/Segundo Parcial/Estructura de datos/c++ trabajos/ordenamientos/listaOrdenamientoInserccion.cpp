#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct nodo{
    int dato;
    nodo *siguiente;
    nodo *anterior;
}nodo;

nodo *cabeza = NULL;

void insertarElementos(int dato){
    nodo *newNodo = new nodo();
    newNodo->dato = dato;
    newNodo->siguiente = NULL;
    newNodo->anterior = NULL;
    if(cabeza == NULL){
        cabeza = newNodo;
    }else{
        nodo *actual = cabeza;
        while(actual->siguiente != NULL){
            actual = actual->siguiente;
        }actual->siguiente = newNodo;
        newNodo->anterior = actual;
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

void ordenamientoInserccion() {
    if (cabeza == NULL) {
        cout << "La lista esta vacia" << endl;
        return;
    }
    nodo *actual = cabeza->siguiente; 
    while (actual != NULL) {
        nodo *temporal = actual;
        while (temporal->anterior != NULL && temporal->dato < temporal->anterior->dato) {
            int auxiliar = temporal->dato;
            temporal->dato = temporal->anterior->dato;
            temporal->anterior->dato = auxiliar;
            temporal = temporal->anterior;
        }
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
    ordenamientoInserccion();
    imprimirLista();
    return 0;
}