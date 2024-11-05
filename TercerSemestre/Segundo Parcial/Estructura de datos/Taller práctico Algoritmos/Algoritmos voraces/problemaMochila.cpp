#include <iostream>
#include <stdlib.h>

using namespace std;

int contadorIteraciones = 0; 

typedef struct mochila{
    float valor; //precio del objeto
    float peso; //peso del objeto
    float indice; //indice del objeto
}mochila;

//Ingresar elementos valor y peso 
void ingresarElementosMochila(int tamano, mochila elemento[]){
    for(int i = 0; i < tamano; i++){
        cout<< "Elemento ("<< i +1 << ") de la mochila"<<endl;
        cout<< "Valor: ";
        cin>>elemento[i].valor;
        cout<< "Peso: ";
        cin>>elemento[i].peso;
        cout<<endl;
        //Calcula el indice como valor / peso
        elemento[i].indice = elemento[i].valor / elemento[i].peso;
    }
}

//Ordenando de mayor a menor por el metodo de burbuja
void metodoBurbuja(int tamano, mochila elemento[]){
    mochila auxiliar; 
    for(int i = 0; i < tamano; i++){
        for(int j = i+1; j < tamano; j++){
            contadorIteraciones++;
            if(elemento[i].indice < elemento[j].indice){
                auxiliar = elemento[i];
                elemento[i] = elemento[j];
                elemento[j] = auxiliar;
            }
        }
    }
}

//Ingresar objetos dentro de la mochila
int ingresarObjetosMochila(int pesoMaximo,int valorMaximo, mochila elemento[]){
    int i = 0;
    while(pesoMaximo > 0){
        contadorIteraciones++;
        if(pesoMaximo > elemento[i].peso){
            pesoMaximo = pesoMaximo - elemento[i].peso;
            valorMaximo = valorMaximo + elemento[i].valor;
        }else{
            valorMaximo = valorMaximo +(elemento[i].valor*(pesoMaximo/elemento[i].peso));
            pesoMaximo = 0;
        }
        i++;
    }
    return valorMaximo;
}

//Mostrar mochila
void imprimirMochila(int tamano, mochila elemento[]){
    for(int i = 0; i < tamano; i++){
        cout<< "Elemento ("<< i +1 << ") de la mochila"<<endl;
        cout<< "Indice: "<<elemento[i].indice<<endl;
        cout<< "Peso: "<<elemento[i].peso<<endl;
        cout<< "Valor: "<<elemento[i].valor<<endl;
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    int tamano = 0;
    cout << "Ingresar el numero de elementos en la mochila: ";
    cin>>tamano;

    mochila *elemento = new mochila[tamano];
    ingresarElementosMochila(tamano, elemento);

    metodoBurbuja(tamano, elemento);

    cout << "----------------------------------------------------------------"<<endl;
    cout << "Verificando que se ha ordenado de mayor a menor segun el indice"<<endl;
    cout << "----------------------------------------------------------------"<<endl;

    imprimirMochila(tamano, elemento);

    float pesoMaximo;
    float valorMaximo = 0;

    cout <<"Peso maximo de la mochila: "<<endl;
    cin>>pesoMaximo;

    cout<<"\nEl valor maximo de la mochila es: "<<ingresarObjetosMochila(pesoMaximo,valorMaximo,elemento)<<endl;

    cout << "Numero de iteraciones: " << contadorIteraciones << endl;
    return 0;
}