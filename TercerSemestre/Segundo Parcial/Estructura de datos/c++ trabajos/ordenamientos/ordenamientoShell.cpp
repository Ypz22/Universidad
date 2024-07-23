#include <iostream>
#include <stdlib.h>

using namespace std;

int tamano = 10;

void imprimirArreglo(int a[]){
    for(int i = 0; i < tamano; i++){
        cout<<a[i]<<" |";
    }cout<<endl;
}

void ordenamientoShell(int a[]){
    int brecha = tamano/2;
    do{
        int brechaAuxiliar = brecha;
        int i = 0;
        while(brechaAuxiliar < tamano){
            if(a[brechaAuxiliar] < a[i]){
                int auxiliar = a[i];
                a[i] = a[brechaAuxiliar];
                a[brechaAuxiliar] = auxiliar;
            }
            brechaAuxiliar++;
            i++;
        }
        if(brecha == 1){
            for(int j = 0; j < tamano-1; j++){
                for(int k = j; k > 0;k--){
                    if(a[k] > a[k+1]){
                        int temporal = a[k];
                        a[k] = a[k+1];
                        a[k+1] = temporal;
                    }
                }
            }
        }
        brecha /=2;
    }while(brecha != 0);
}

int main(){
    int a[tamano] = {35, 12, 99, 18, 75, 22, 47, 3, 65, 54};
    imprimirArreglo(a);
    ordenamientoShell(a);
    imprimirArreglo(a);
    return 0;
}