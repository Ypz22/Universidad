#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct nodo{
    int dato;
    nodo *siguiente;
}nodo;

nodo *cabeza = NULL;

typedef struct matriz{
    int dato;
    matriz *siguiente;
}matriz;

matriz *inicioMatriz = NULL;

int arreglo[10] = {0,0,0,0,0,0,0,0,0,0};

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

void ordenamientoRadixSort(){
    if(cabeza == NULL){
        cout<<"La lista esta vacia"<<endl;
    }else{
        nodo *actual = cabeza;
        while(actual != NULL){
            actual = actual->siguiente;
        }
    }
}

int main(){
    insertarElementos(35);
    insertarElementos(62);
    insertarElementos(56);
    insertarElementos(3);
    insertarElementos(16);
    imprimirLista();  
    return 0;
}