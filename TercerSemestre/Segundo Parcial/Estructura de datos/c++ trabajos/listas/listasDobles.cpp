#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct nodo
{
    int data;
    nodo *siguiente;
    nodo *anterior;
}nodo;

nodo *cabeza = NULL;

void insertarDatosInicio(int dato){
    nodo *newNodo = new nodo();
    newNodo->data = dato;
    newNodo->siguiente = NULL;
    newNodo->anterior = NULL;
    if(cabeza == NULL){
        cabeza = newNodo;
    }else{
        cabeza->anterior = newNodo;
        newNodo->siguiente = cabeza;
        cabeza = newNodo;
    }
}

void insertarDatosFinal(int dato){
    nodo *newNodo = new nodo();
    newNodo->data = dato;
    newNodo->siguiente = NULL;
    newNodo->anterior = NULL;
    if(cabeza == NULL){
        cabeza = newNodo;
    }else{
        nodo *actual = cabeza;        
        while(actual->siguiente != NULL){
            actual = actual->siguiente;
        }
        actual->siguiente = newNodo;
        newNodo->anterior = actual;
    }
}

void insertarDatosMedio(int dato, int datoEncontrar){
    nodo *newNodo = new nodo();
    newNodo->data = dato;
    newNodo->siguiente = NULL;
    newNodo->anterior = NULL;
    if(cabeza == NULL){
        cabeza = newNodo;
    }else{
        nodo *actual = cabeza;
        while(actual != NULL && actual->data != datoEncontrar){
            actual = actual->siguiente;
        }
        newNodo->siguiente = actual->siguiente;
        newNodo->anterior = actual;
        actual->siguiente = newNodo;
    }
}

void eliminarDatoLista(int dato){
    nodo *actual = cabeza;
    if(cabeza == NULL){
        cout<<"La lista esta vacia"<<endl;
    }
    while(actual != NULL && actual->data != dato){
        actual = actual->siguiente;
    }
    if(actual->data == dato){
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
        free(actual);
    }else{
        cout<<"Numero no encontrado"<<endl;
    }
}

void eliminarCabeza(){
    nodo *actual = cabeza;
    if(cabeza == NULL){
        cout<<"La lista esta vacia"<<endl;
    }else{
        cabeza = cabeza->siguiente;
        free(actual);
    }
}

void imprimirLista(){
    nodo *actual = cabeza;
    while ( actual != NULL)
    {
        cout<<actual->data<<" |";
        actual = actual->siguiente;
    }
    
}

int main(){
    insertarDatosFinal(1);
    insertarDatosFinal(2);
    insertarDatosFinal(3);
    insertarDatosFinal(4);
    insertarDatosFinal(5);
    insertarDatosMedio(999,5);
    insertarDatosMedio(101,3);
    eliminarDatoLista(5);
    eliminarCabeza();
    imprimirLista();
    return 0;
}