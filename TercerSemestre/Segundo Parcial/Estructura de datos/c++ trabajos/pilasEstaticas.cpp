#include <iostream>
#include <stdlib.h>

using namespace std;
int tamano = 5; 
int frente = -1;
int auxliar = 0;

void insertarDatosPila(int a[], int dato){
    if(frente >= tamano - 1){
        cout<<"La lista esta llena."<<endl;
    }else{
        frente++;
        a[frente] = dato;
    }
}

void eliminarDatoPila(int a[]){
    if(frente == -1){
        cout<<"La lista esta vacia."<<endl;
    }else{
        auxliar = frente;
        cout<<"El ultimo elemento eliminado es: "<<a[auxliar];
        a[auxliar] = 0;
        auxliar--;
        
    }
}

void imprimirPila(int a[]){
    int temporal = frente;
    if(temporal == -1){
        cout<<"La lista esta vacia."<<endl;
    }else{
        for(temporal;temporal - 1 >= -1;temporal--){
            cout<<a[temporal]<<" |";
        }
    }
}


int main(){
    int a[tamano];
    insertarDatosPila(a,1);
    insertarDatosPila(a,2);
    insertarDatosPila(a,3);
    insertarDatosPila(a,4);
    insertarDatosPila(a,5);
    insertarDatosPila(a,6);
    imprimirPila(a);
    cout<<endl;
    eliminarDatoPila(a);
    cout<<endl;
    eliminarDatoPila(a);
    cout<<endl;
    imprimirPila(a);
    return 0;
}