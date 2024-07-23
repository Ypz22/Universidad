#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int tamano = 10;

void lectura(string a[]){
    ifstream archivo;
    string datos;
    int i = 0;

    archivo.open("datos.txt", ios::in);

    if(archivo.fail()){
        cout <<"No se pudo abrir el archivo";
        exit(1);
    }
    while(!archivo.eof()){
        getline(archivo,datos);
        a[i] = datos;
        i++;
    }
    archivo.close();
}

void imprimirArreglo(string a[]){
    for(int i = 0; i < tamano; i++){
        cout<<a[i]<<" |";
    }cout<<endl;
}


int main()
{
    string a[tamano];
    lectura(a);
    imprimirArreglo(a);
    imprimirArreglo(a);
    return 0;
}
