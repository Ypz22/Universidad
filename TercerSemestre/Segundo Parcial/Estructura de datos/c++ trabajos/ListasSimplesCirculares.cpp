#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct nodo
{
    int data;
    nodo *siguiente;
}nodo;

nodo *cabeza = NULL;

void insertarDatosFinal(int dato){
    nodo *newNodo = new nodo();
    newNodo->data = dato;
    newNodo->siguiente = NULL;
    if(cabeza == NULL){
        cabeza = newNodo;
        newNodo->siguiente = cabeza;
    }else{
        nodo *actual = cabeza;
        while(actual->siguiente != cabeza){
            actual = actual->siguiente;
        }actual->siguiente = newNodo;
        newNodo->siguiente = cabeza;
    }
}

void insertarAlMedio(int dato,int datoEncontrar){
    nodo *newNodo = new nodo();
    newNodo->data = dato;
    newNodo->siguiente = NULL;
    if(cabeza == NULL){
        cout<<"La lista esta vacia"<<endl;
    }else{
        nodo *actual = cabeza;
        while(actual->siguiente != cabeza && actual->data != datoEncontrar){
            actual = actual->siguiente;
        }
        newNodo->siguiente = actual->siguiente;
        actual->siguiente = newNodo;
    }
}

void eliminarCabeza(){
    if(cabeza == NULL){
        cout<<"La lista esta vacia"<<endl;
    }else{
        nodo *actual = cabeza;
        while(actual->siguiente != cabeza){
            actual = actual->siguiente;
        }actual->siguiente = cabeza->siguiente;
        free(cabeza);
        cabeza = actual->siguiente;
    }
}

void imprimirListaCircular(){
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
    insertarAlMedio(999,5);
    insertarAlMedio(101,1);
    eliminarCabeza();
    eliminarCabeza();
    imprimirListaCircular();
    return 0;
}