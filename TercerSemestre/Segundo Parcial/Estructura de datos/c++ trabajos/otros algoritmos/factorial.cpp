#include <iostream>
#include <stdlib.h>

using namespace std;

int factorial(int n){
    if(n == 0){
        return 1;
    }else{
        return n * factorial(n-1);
    }
}

int main(){
    int resultado = factorial(5);
    cout<<"El factorial de 5 es: "<<resultado<<endl;
    return 0;
}