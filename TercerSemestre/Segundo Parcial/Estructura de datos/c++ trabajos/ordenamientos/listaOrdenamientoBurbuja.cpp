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

void ordenamientoBurbuja(){
    nodo *actual = cabeza;
    if(cabeza == NULL){
        cout<<"La lista esta vacia"<<endl;
    }
    while(actual != NULL){
        nodo *temporal = cabeza;
        nodo *aux = temporal->siguiente;
        while(temporal->siguiente != NULL){
            if(temporal->dato > aux->dato){
                int auxiliar = temporal->dato;
                temporal->dato = aux->dato;
                aux->dato = auxiliar;
            }
            temporal = temporal->siguiente;
            aux = aux->siguiente;
        }actual = actual->siguiente;
    }
}

int main(){
    insertarElementos(35);
    insertarElementos(62);
    insertarElementos(56);
    insertarElementos(3);
    insertarElementos(16);
    imprimirLista();
    ordenamientoBurbuja();
    imprimirLista();
    return 0;
}