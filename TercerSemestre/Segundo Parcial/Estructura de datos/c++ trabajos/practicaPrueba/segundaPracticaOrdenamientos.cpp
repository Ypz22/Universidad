#include <iostream>
#include <stdlib.h>

using namespace std;

int tamano = 10;

void metodoBurbuja(int a[]){
    for(int i = 0;i < tamano; i++){
        for(int j = i+1; j < tamano; j++){
            if(a[i] > a[j]){
                int aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
}

void metodoSeleccion(int a[]){
    for(int i = 0; i < tamano; i++){
        int auxiliar = i;
        for(int j = i+1;j < tamano; j++){
            if(a[auxiliar] > a[j]){
                auxiliar = j;
            }
        }int temp = a[i];
        a[i] = a[auxiliar];
        a[auxiliar] = temp;
    }
}

void metodoInserccion(int a[]){
    for(int i = 0; i < tamano; i++){
        for(int j = i-1; j >= 0; j--){
            if(a[j] > a[j+1]){
                int aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
            }
        }
    }
}

void metodoQuickSort(int a[], int inicio, int final){
    int i = inicio,j = final;
    int centro = (inicio+final)/2;
    int pivote = a[centro];
    do{
        while(a[i] < pivote){
            i++;
        }while(a[j] > pivote){
            j--;
        }
        if(i <= j){
            int aux = a[i];
            a[i] = a[j];
            a[j] = aux;
            i++;
            j--;
        }
    }while(i <= j);
    if(i < final){
        metodoQuickSort(a,i,final);
    }if(j > inicio){
        metodoQuickSort(a,inicio,j);
    }
}

void metodoShell(int a[]){
    int brecha = tamano/2;
    do{
        int auxBrecha = brecha;
        int i = 0;
        while(auxBrecha < tamano){
            if(a[auxBrecha] < a[i]){
                int temp = a[auxBrecha];
                a[auxBrecha] = a[i];
                a[i] = temp;
            }auxBrecha++;
            i++;
        }
        if(brecha == 1){
            for(int k = 0; k < tamano; k++){
                for(int j = k -1; j >= 0; j--){
                    if(a[j] > a[j+1]){
                        int aux = a[j];
                        a[j] = a[j+1];
                        a[j+1] = aux;
                    }
                }
            }
        }
        brecha /= 2;
    }while(brecha != 0);
}

void busquedaSecuencial(int clave, int a[]){
    for(int i = 0; i <tamano; i ++){
        if(a[i] == clave){
            cout<<"El numero se encuentra en la posicion "<<i<<endl;
        }
    }
}

int busquedaBinaria(int a[], int clave,int bajo,int alto){
    if(bajo <= alto){
        int centro = (bajo+alto)/2;
        if(a[centro] == clave){
            return centro;
        }else if(a[centro] < clave){
            return busquedaBinaria(a,clave,centro +1 ,alto);
        }else{
            return busquedaBinaria(a,clave,bajo,centro -1 );
        }
    }return -1;
}


void imprimirArreglo(int a[]){
    for(int i = 0; i < tamano; i++){
        cout << a[i] <<" ";
    }cout <<endl;
}

int main(){
    int a[tamano] = {23, 87, 45, 12, 78, 56, 34, 99, 67, 21};
    cout<<"lista original: "<<endl;
    imprimirArreglo(a);
    busquedaSecuencial(99,a);
    metodoShell(a);
    cout<<"lista ordenada: "<<endl;
    imprimirArreglo(a);
    int resultado = busquedaBinaria(a,99,0,tamano-1);
    if(resultado != -1){
        cout<<"El numero se encuentra en la posicion "<<resultado<<endl;
    }else{
        cout<<"el numero no fue encontrado"<<endl;
    }
}