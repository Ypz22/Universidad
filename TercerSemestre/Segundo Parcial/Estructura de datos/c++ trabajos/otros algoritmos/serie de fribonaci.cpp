#include <iostream>
#include <stdlib.h>

using namespace std;

int  serieFribonaci(int n){
    if(n == 0 || n == 1){
        return n;
    }else{
        return serieFribonaci(n-1) + serieFribonaci(n-2);
    }
}

void mostrarSerie(){
    for(int i = 0; i<=10;i++){
        cout<<"Fibonacci "<<i<<" es: "<<serieFribonaci(i)<<endl;
    }
}

int main(){
    cout<<"Serie de fribonaci : "<<serieFribonaci(14)<<endl;
    //mostrarSerie();
}