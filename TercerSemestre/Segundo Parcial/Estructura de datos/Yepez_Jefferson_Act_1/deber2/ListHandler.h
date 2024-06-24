#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "node.h"

using namespace std;

class lista {
public:
    node *head; // Puntero al primer nodo de la lista.

    lista() {
        head = 0; // Inicializa el puntero 'head' como NULL.
    }

    void insertarPremios(string premio); // Función para insertar un premio en la lista.
    void imprimirLista(); // Función para imprimir todos los premios en la lista.
    int generarNumeroAleatorio(); // Función para generar un número aleatorio entre 2 y 7 (ambos inclusive).
    void girarRuleta(); // Función para "girar" la ruleta y seleccionar un premio aleatorio.
};

void lista::insertarPremios(string premio) {
    node *newNode = new node(premio); // Crea un nuevo nodo con el premio proporcionado.
    if (head == NULL) {
        newNode->siguiente = newNode; // Si la lista está vacía, el nuevo nodo es el único en la lista.
        newNode->previo = newNode;
        head = newNode;
    } else {
        node *actual = head;
        while (actual->siguiente != head) {
            actual = actual->siguiente;
        }
        newNode->siguiente = head; // Si la lista no está vacía, se agrega el nuevo nodo al final de la lista.
        newNode->previo = actual;
        actual->siguiente = newNode;
    }
}

void lista::imprimirLista() {
    node *actual = head;
    int x = 0;
    if (head == NULL) {
        printf("The list is empty\n");
    }
    do {
        x++;
        printf("Premio %i es: %s \n", x, actual->premio.c_str());
        actual = actual->siguiente;
    } while (actual != head);
}

int lista::generarNumeroAleatorio() {
    std::srand(std::time(nullptr)); // Inicializa la semilla del generador de números aleatorios.
    int numeroAleatorio = std::rand() % 6 + 2; // Genera un número aleatorio entre 2 y 7.
    return numeroAleatorio;
}

void lista::girarRuleta() {
    node *actual = head;
    actual = actual->previo; // El nodo actual es el último nodo de la lista.
    int numeroAleatorio = generarNumeroAleatorio(); // Genera un número aleatorio.
    for (int i = 1; i < numeroAleatorio; i++) {
        actual = actual->siguiente; // Avanza 'numeroAleatorio' posiciones en la lista.
    }
    printf("El premio ganado es: %s \n", actual->premio.c_str()); // Imprime el premio ganado.
}
