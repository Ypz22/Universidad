#include <iostream>
#include <stdlib.h>

using namespace std;

int tamano = 10;

void ordenamientoBurbuja(int a[]){
    int j = 0;
    for(int i = 0; i < tamano; i++){
        for(j = 0; j < tamano-1; j++){
            if(a[j] > a[j+1]){
                int auxiliar = a[j];
                a[j] = a[j+1];
                a[j+1] = auxiliar;
            }
        }
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
    ordenamientoBurbuja(a);
    imprimirArreglo(a);
    return 0;
}
