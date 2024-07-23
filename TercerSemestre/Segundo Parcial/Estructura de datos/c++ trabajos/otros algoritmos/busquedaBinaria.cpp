#include <iostream>
#include <stdlib.h>

using namespace std;

int tamano = 10;

int busquedaBinaria(int a[],int n, int superior, int inferior){
    int centro = (superior+inferior)/2;
    if(inferior > superior){
        cout<<"Numero no encontrado"<<endl;
    }
    if(n == a[centro]){
        return centro;
    }
    if(a[centro] < n){
        busquedaBinaria(a,n,superior,centro +1);
    }else{
        busquedaBinaria(a,n,centro-1,inferior);
    }
}

void imprimirVector(int a[]){
    for(int i = 0; i < tamano;i++){
        cout<<a[i]<<" |";
    }
}

int main(){
    int a[tamano] = {1,5,15,20,40,45,50,100,159,999};
    imprimirVector(a);
    cout<<"en la posicion: "<<busquedaBinaria(a,159,10,0)<<endl;
    cout<<endl;
    imprimirVector(a);
    cout<<"en la posicion: "<<busquedaBinaria(a,15,10,0)<<endl;
    cout<<endl;
    imprimirVector(a);
    cout<<"en la posicion: "<<busquedaBinaria(a,999,10,0)<<endl;
    cout<<endl;
    imprimirVector(a);
    cout<<"en la posicion: "<<busquedaBinaria(a,1,10,0)<<endl;
    cout<<endl;
    imprimirVector(a);
    return 0;
}