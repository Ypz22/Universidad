#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct nodo
{
    int data;
    nodo *siguiente;
}nodo;

nodo *cabeza = NULL;


void insertarDatosCola(int dato){
    nodo *newNodo = new nodo();
    newNodo->data = dato;
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

void eliminarDatosCola(){
    nodo *actual = cabeza;
    if(cabeza == NULL){
        cout<<"La lista esta vacia"<<endl;
    }else{
        cabeza = cabeza->siguiente;
        free(actual);
    }
}

void imprimirCola(){
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
    insertarDatosCola(1);
    insertarDatosCola(2);
    insertarDatosCola(3);
    insertarDatosCola(4);
    insertarDatosCola(5);
    insertarDatosCola(6);
    imprimirCola();
    cout<<endl;
    eliminarDatosCola();
    cout<<endl;
    imprimirCola();
    eliminarDatosCola();
    cout<<endl;
    imprimirCola();
    return 0;
}