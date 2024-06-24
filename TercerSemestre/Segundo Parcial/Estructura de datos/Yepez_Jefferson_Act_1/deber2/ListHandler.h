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

    void insertarPremios(string premio); // Funci�n para insertar un premio en la lista.
    void imprimirLista(); // Funci�n para imprimir todos los premios en la lista.
    int generarNumeroAleatorio(); // Funci�n para generar un n�mero aleatorio entre 2 y 7 (ambos inclusive).
    void girarRuleta(); // Funci�n para "girar" la ruleta y seleccionar un premio aleatorio.
};

void lista::insertarPremios(string premio) {
    node *newNode = new node(premio); // Crea un nuevo nodo con el premio proporcionado.
    if (head == NULL) {
        newNode->siguiente = newNode; // Si la lista est� vac�a, el nuevo nodo es el �nico en la lista.
        newNode->previo = newNode;
        head = newNode;
    } else {
        node *actual = head;
        while (actual->siguiente != head) {
            actual = actual->siguiente;
        }
        newNode->siguiente = head; // Si la lista no est� vac�a, se agrega el nuevo nodo al final de la lista.
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
    std::srand(std::time(nullptr)); // Inicializa la semilla del generador de n�meros aleatorios.
    int numeroAleatorio = std::rand() % 6 + 2; // Genera un n�mero aleatorio entre 2 y 7.
    return numeroAleatorio;
}

void lista::girarRuleta() {
    node *actual = head;
    actual = actual->previo; // El nodo actual es el �ltimo nodo de la lista.
    int numeroAleatorio = generarNumeroAleatorio(); // Genera un n�mero aleatorio.
    for (int i = 1; i < numeroAleatorio; i++) {
        actual = actual->siguiente; // Avanza 'numeroAleatorio' posiciones en la lista.
    }
    printf("El premio ganado es: %s \n", actual->premio.c_str()); // Imprime el premio ganado.
}
