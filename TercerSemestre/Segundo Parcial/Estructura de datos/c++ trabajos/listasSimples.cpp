#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct nodo
{
    int data;
    nodo *siguiente;
}nodo;

nodo *cabeza = NULL;

void ingresarDatosInicio(int dato){
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

void insertarDatosFinal(int dato){
    nodo *newNodo = new nodo();
    newNodo->data = dato;
    newNodo->siguiente = NULL;
    if(cabeza == NULL){
        cabeza = newNodo;
    }else{
        nodo *actual = cabeza;
        while(actual->siguiente != NULL){
            actual = actual->siguiente;
        }
        actual->siguiente = newNodo;
    }
}

void insertarDatosMedio(int dato, int datoEncontrar){
    nodo *newNodo = new nodo();
    newNodo->data = dato;
    newNodo->siguiente = NULL;
    if(cabeza == NULL){
        cabeza = newNodo;
    }else{
        nodo *actual = cabeza;
        while(actual->siguiente != NULL && actual->data != datoEncontrar){
            actual = actual->siguiente;
        }
        if(actual->data == datoEncontrar){
            newNodo->siguiente = actual->siguiente;
            actual->siguiente = newNodo;
        }else{
            cout<<"Numero no encontrado"<<endl;
        }
    }
}

void borrarDatosCabeza(){
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
    }
    while ((actual != NULL))
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
    borrarDatosCabeza(); 
    imprimirLista();
    return 0;
}