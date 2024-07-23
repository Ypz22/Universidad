#include <iostream>
#include <stdlib.h>

using namespace std;

int tamano = 10;

void ordenamientoSeleccion(int a[]){
    for(int i = 0; i < tamano;i++){
        int auxiliar = i;
        for(int j = i + 1; j < tamano; j++){
            if(a[j] < a[auxiliar]){
                auxiliar = j;
            }
        }int temp = a[i];
        a[i] = a[auxiliar];
        a[auxiliar] = temp;
    }
}


void imprimirArreglo(int a[]){
    for(int i = 0; i < tamano; i++){
        cout<<a[i]<<" |";
    }cout<<endl;
}

int main(){
    int a[tamano] = {35, 12, 99, 18, 75, 22, 47, 3, 65, 54};
    imprimirArreglo(a);
    ordenamientoSeleccion(a);
    imprimirArreglo(a);
    return 0;
}