#include <iostream>
#include <stdlib.h>

using namespace std;

int tamano = 5;

int quickSort(int a[], int superior,int inferior){
    int centro = (superior + inferior)/2;
    int pivote = a[centro];
    int i = inferior, j = superior;
    do{
        while(a[i] < pivote){
        i++;
    }
    while(a[j] > pivote){
        j--;
    }
    if(i <= j){
        int temporal = a[i];
        a[i] = a[j];
        a[j] = temporal;
        i++;
        j--;
    }
    }while(i <= j);
    if(j > inferior){
        quickSort(a,j+1,inferior);
    }
    if(i < superior){
        quickSort(a,i-1,inferior);
    }

}

void imprimirVector(int a[]){
    for(int i = 0; i < tamano;i++){
        cout<<a[i]<<" |";
    }
}

int main(){
    int a[tamano] = {1,6,8,4,15};
    imprimirVector(a);
    quickSort(a,5,0);
    cout<<endl;
    imprimirVector(a);

    return 0;
}