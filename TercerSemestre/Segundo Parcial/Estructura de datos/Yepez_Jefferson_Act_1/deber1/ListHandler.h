#include <iostream>
#include <stdlib.h>
#include "node.h"

class lista {
public:
    node *head; // Puntero al primer nodo de la lista

    lista() {
        head = 0; // Inicializa la cabeza de la lista como null
    }

    // Declaraciones de métodos
    void insertarFinal(int dato);
    void imprimirLista();
    void eliminarNumeroRepetido();
    void calcularSumatoriaLista();
    lista listaCuadradosOriginales();
};

// Método para insertar un nuevo nodo al final de la lista
void lista::insertarFinal(int dato) {
    node *newNode = new node(dato); // Crea un nuevo nodo con el dato proporcionado
    if (head == NULL) { // Si la lista está vacía
        head = newNode; // El nuevo nodo se convierte en la cabeza de la lista
    } else {
        node *actual = head; // Inicia desde la cabeza de la lista
        while (actual->siguiente != NULL) { // Recorre la lista hasta encontrar el último nodo
            actual = actual->siguiente;
        }
        newNode->previo = actual; // Enlaza el nuevo nodo al final de la lista
        actual->siguiente = newNode;
    }
}

// Método para imprimir todos los elementos de la lista
void lista::imprimirLista() {
    node *actual = head; // Inicia desde la cabeza de la lista
    if (head == NULL) {
        printf("La lista esta vacia\n"); // Mensaje si la lista está vacía
    }
    while (actual != NULL) { // Recorre la lista e imprime cada dato
        printf("%d |", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Método para calcular la sumatoria de los elementos de la lista
void lista::calcularSumatoriaLista() {
    int sumatoria = 0; // Inicializa la sumatoria
    node *actual = head; // Inicia desde la cabeza de la lista
    while (actual != NULL) { // Recorre la lista y suma cada dato
        sumatoria += actual->dato;
        actual = actual->siguiente;
    }
    printf("La sumatoria de la lista es: %d\n", sumatoria);
}

// Método para crear una nueva lista con los cuadrados de los elementos de la lista original
lista lista::listaCuadradosOriginales() {
    lista listaCuadrados; // Crea una nueva lista para los cuadrados
    if (head == NULL) {
        printf("La lista esta vacia\n"); // Mensaje si la lista está vacía
    } else {
        node *actual = head; // Inicia desde la cabeza de la lista original
        while (actual != NULL) { // Recorre la lista y añade el cuadrado de cada dato a la nueva lista
            listaCuadrados.insertarFinal((actual->dato) * (actual->dato));
            actual = actual->siguiente;
        }
    }
    return listaCuadrados; // Devuelve la nueva lista con los cuadrados
}

// Método para eliminar los números repetidos de la lista
void lista::eliminarNumeroRepetido() {
    if (head == NULL) {
        printf("La lista esta vacia\n"); // Mensaje si la lista está vacía
    } else {
        node *actual = head; // Inicia desde la cabeza de la lista
        node *repetidor; // Puntero para buscar nodos repetidos
        while (actual != NULL) { // Recorre la lista
            repetidor = actual->siguiente; // Comienza la búsqueda de repetidos desde el siguiente nodo
            while (repetidor != NULL) { // Recorre los nodos para encontrar repetidos
                if (repetidor->dato == actual->dato) { // Si encuentra un número repetido
                    repetidor->siguiente->previo = repetidor->previo; // Ajusta los punteros del nodo previo
                    repetidor->previo->siguiente = repetidor->siguiente; // Ajusta los punteros del nodo siguiente
                }
                repetidor = repetidor->siguiente; // Avanza al siguiente nodo
            }
            actual = actual->siguiente; // Avanza al siguiente nodo principal
        }
    }
}






