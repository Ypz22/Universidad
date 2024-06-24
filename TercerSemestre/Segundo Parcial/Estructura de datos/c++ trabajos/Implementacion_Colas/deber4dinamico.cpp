#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct nodo
{
    int dato;
    nodo *siguiente; 
}nodo;

nodo *frente = NULL;
nodo *fin = NULL;

void insertarElmentosCola(int numero){
    nodo *newNodo = new nodo();
    newNodo->dato = numero;
    newNodo->siguiente = NULL;
    if(fin == NULL){
        frente = newNodo;
        fin = newNodo;
    }else{
        fin->siguiente = newNodo;
        fin = newNodo;
    }
}

void imprimirCola(){
    if(frente == NULL){
        cout<<"La cola esta vacia"<<endl;
    }else{
        nodo *actual = frente;
        while (actual != NULL){
            cout<< actual->dato<<" ,";
            actual = actual->siguiente;
        }        
    }
}

void eliminarElementoCola(){
    if (frente == NULL) {
        cout << "La cola está vacía\n";
        return;
    }
    nodo* actual = frente;
    frente = frente->siguiente;
    if (frente == NULL) {
        fin = NULL;
    }
    cout << "Elemento removido: " << actual->dato << endl;
    delete actual;
}


int main(){
    int opcion;
    cout<< "En el presente ejercicio, llevaremos a cabo la simulación de una fila de un supermercado, donde se atenderá a los clientes según el orden de su llegada. Se utilizarán listas dinámicas ya que no se conoce de antemano cuántos clientes llegarán a la fila para pagar sus compras.\n";

    do {
        cout << "\n1. Agregar cliente a la fila de compras\n";
        cout << "2. Atender cliente \n";
        cout << "3. Mostrar fila de supermercado\n";
        cout << "4. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                int id;
                cout << "Ingrese el ID del libro: ";
                cin >> id;
                insertarElmentosCola(id);
                break;
            }
            case 2:
                eliminarElementoCola();
                break;
            case 3:
                imprimirCola();
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