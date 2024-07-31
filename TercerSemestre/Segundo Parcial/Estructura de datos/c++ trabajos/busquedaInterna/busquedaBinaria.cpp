#include <iostream>
#include <stdlib.h>

using namespace std;

int tamano = 7;

int busquedaBinaria(int a[], int clave, int bajo, int alto){
    if(bajo <= alto){
        int central = (bajo + alto)/2;
        if(a[central] == clave){
            return central;
        }else if(a[central] < clave){
            return busquedaBinaria(a,clave,central + 1 ,alto);
        }else{
            return busquedaBinaria(a,clave,bajo,central -1 );
        }
    }
    return -1;
}

int main(){
    int a[tamano] = {13,44,75,100,120,275,325,510};
    int bajo = 0, alto = tamano;
    int resultado = busquedaBinaria(a,225,bajo,alto);
    if(resultado != -1){
        cout<<"El numero se encuentra en el indice "<<resultado<<endl;
    }else{
        cout<<"El numero no se encuentra"<<endl;
    }
    return 0;
}