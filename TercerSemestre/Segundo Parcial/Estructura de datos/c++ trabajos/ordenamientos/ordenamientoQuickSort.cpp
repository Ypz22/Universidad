#include <iostream>
#include <stdlib.h>

using namespace std;

int tamano = 10;

void ordenamientoQuickSort(int a[], int inicio, int fin){
    int i = inicio, j = fin;
    int central = (inicio + fin) / 2;
    int pivote = a[central];
    do{
        while(a[i] < pivote){
            i++;
        }while(a[j] > pivote){
            j--;
        }
        if(i <= j){
            int auxiliar = a[i];
            a[i] = a[j];
            a[j] = auxiliar;
            i++;
            j--;
        }
    }while(i <= j);
    if(j > inicio){
        ordenamientoQuickSort(a,inicio,j);
    }if(i < fin){
        ordenamientoQuickSort(a,i,fin);
    }
}



void imprimirArreglo(int a[]){
    for(int i = 0; i < tamano; i++){
        cout<<a[i]<<" |";
    }cout<<endl;
}

int main(){
    int inicio = 0, fin = tamano-1;
    int a[tamano] = {35, 12, 99, 18, 75, 22, 47, 3, 65, 54};
    imprimirArreglo(a);
    ordenamientoQuickSort(a,inicio,fin);
    imprimirArreglo(a);
    return 0;
}