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


void insertarDatosFinal(int dato){
    nodo *newNodo = new nodo();
    newNodo->data = dato;
    newNodo->siguiente = NULL;
    newNodo->anterior = NULL;
    if(cabeza == NULL){
        cabeza = newNodo;
        newNodo->siguiente = cabeza;
        newNodo->anterior = cabeza;
    }else{
        nodo *actual = cabeza;
        while(actual->siguiente != cabeza){
            actual = actual->siguiente;
        }
        newNodo->siguiente = cabeza;
        newNodo->anterior = actual;
        actual->siguiente = newNodo;
    }
}

void insertarDatosMedio(int dato, int datoEncontrar){
    nodo *newNodo = new nodo();
    newNodo->data = dato;
    newNodo->siguiente = NULL;
    newNodo->anterior = NULL;
    if(cabeza == NULL){
        cabeza = newNodo;
        newNodo->siguiente = cabeza;
        newNodo->anterior = cabeza;
    }else{
        nodo *actual = cabeza;
        while(actual->siguiente != cabeza && actual->data != datoEncontrar){
            actual = actual->siguiente;
        }newNodo->siguiente = actual->siguiente;
        newNodo->anterior = actual;
        actual->siguiente = newNodo;
        cabeza->anterior = newNodo;
    }
}

void eliminarDato(int dato){
    if(cabeza == NULL){
        cout<<"La lista esta vacia"<<endl;
    }else{
        nodo *actual = cabeza;
        while(actual->siguiente != cabeza && actual->data != dato){
            actual = actual->siguiente;
        }actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
        free(actual);
    }
   
}

void eliminarCabeza(){
    if(cabeza == NULL){
        cout<<"La lista esta vacia"<<endl;
    }else{
        nodo *actual = cabeza;
        while(actual->siguiente != cabeza){
            actual = actual->siguiente;
        }
        nodo *temporal = cabeza;
        cabeza = cabeza->siguiente;
        cabeza->anterior = actual;
        actual->siguiente = cabeza;
        free(temporal);
        
    }
}

void imprimirLista(){
    nodo *actual = cabeza;
    if(cabeza == NULL){
        cout<<"La lista esta vacia"<<endl;
    }
    do{
        cout<<actual->data<<" |";
        actual = actual->siguiente;
    }while(actual != cabeza);
}

int main(){
    insertarDatosFinal(1);
    insertarDatosFinal(2);
    insertarDatosFinal(3);
    insertarDatosFinal(4);
    insertarDatosFinal(5);
    insertarDatosFinal(6);
    insertarDatosMedio(999,1);
    eliminarDato(3);
    eliminarCabeza();
    imprimirLista();
    return 0;
}