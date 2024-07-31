#include <iostream>
#include <stdlib.h>

using namespace std;

int tamano = 10;

void busquedaSecuencial(int clave,int a[]){
    for(int  i = 0; i < tamano; i++){
        if(a[i] == clave){
            cout<< "El elemento esta en el indice "<<i<<endl;
            return;
        }
    }cout << "El elemento no fue encontrado"<<endl;
}

int main(){
    int a[tamano] = {55,10,49,13,14,47,150,96,21,48};
    busquedaSecuencial(200,a);
    return 0;
}