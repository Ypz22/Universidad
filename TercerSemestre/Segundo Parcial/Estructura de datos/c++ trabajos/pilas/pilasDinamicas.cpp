#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct nodo
{
    int data;
    nodo *siguiente;
}nodo;

nodo *cabeza = NULL;

void insertarDatosInicio(int dato){
    nodo *newNodo = new nodo();
    newNodo->data = dato;
    newNodo->siguiente = NULL;
    if(cabeza == NULL){
        cabeza = newNodo;
    }else{
        newNodo->siguiente = cabeza;
        cabeza = newNodo;
    }
}

void eliminarDatoPila(){
    if(cabeza == NULL){
        cout<<"La lista esta vacia"<<endl;
    }else{
        nodo *actual = cabeza;
        cabeza = cabeza->siguiente;
        free(actual);
    }
}


void imprimirLista(){
    nodo *actual = cabeza;
    if(cabeza == NULL){
        cout<<"La lista esta vacia"<<endl;
    }else{
        while(actual != NULL){
            cout<<actual->data<<" |";
            actual = actual->siguiente;
        }
    }
}

int main(){
    insertarDatosInicio(1);
    insertarDatosInicio(2);
    insertarDatosInicio(3);
    insertarDatosInicio(4);
    insertarDatosInicio(5);
    imprimirLista();
    cout<<endl;
    eliminarDatoPila();
    cout<<endl;
    imprimirLista();
    return 0;
}