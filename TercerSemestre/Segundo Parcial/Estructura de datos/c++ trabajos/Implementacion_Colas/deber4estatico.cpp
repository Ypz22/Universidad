#include <iostream>
#include <stdlib.h>

using namespace std;

int frente = -1;
int fin = -1;
int tamano = 5;
int contadorEliminados = 0;

void insertarElementosCola(int cola[], int numero){
    if(frente == -1 || fin == -1){
        frente = 0;
        fin = 0;
    }if(fin > tamano){
        cout<<"La cola esta llena!"<<endl;
    }else{
        cola[fin] = numero;
        fin++;
    }
}

void eliminarElementoCola(int cola[]){
     if (frente == -1 || frente > fin) {
        cout << "La cola está vacía" << endl;
    } else {
        cout << "Elemento removido: " << cola[frente] << endl;
        frente++;
}
}

void imprimirCola(int cola[]){
    int auxiliar = frente;
    for(int i = 0; i < tamano; i++){
        cout<<cola[auxiliar++]<<" ,";
    }
}

int main(){
    int cola[tamano];
    int opcion;
    cout << "En este ejercicio, el bibliotecario administra una cola de solicitudes de libros siguiendo el orden en que son recibidas. Cada cliente es atendido en la secuencia en la que realizaron su solicitud. Dado que la biblioteca cuenta con un límite en la cantidad de libros disponibles, se empleará memoria estática para gestionar esta cola de solicitudes.\n";

    do {
        cout << "\n1. Agregar solicitud de libro\n";
        cout << "2. Atender solicitud de libro\n";
        cout << "3. Mostrar solicitudes en la cola\n";
        cout << "4. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                int id;
                cout << "Ingrese el ID del libro: ";
                cin >> id;
                insertarElementosCola(cola,id);
                break;
            }
            case 2:
                eliminarElementoCola(cola);
                break;
            case 3:
                imprimirCola(cola);
                break;
            case 4:
                cout << "Salir\n";
                break;
            default:
                cout << "Opción no válida\n";
        }
    } while (opcion != 4);
    return 0;
}
