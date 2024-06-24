#include <iostream>

const int MAX_SIZE = 10;
int colaLineal[MAX_SIZE];
int frente = -1, fin = -1;

void insertarElementoscola(int dato) {
    if (fin == MAX_SIZE - 1) {
        printf("\nLa cola está llena\n");
    } else {
        if (frente == -1) {
            frente = 0;
        }
        fin++;
        colaLineal[fin] = dato;
    }
}

void quitarElemento() {
    if (frente == -1 || frente > fin) {
        printf("\nLa cola está vacía\n");
    } else {
        printf("\nElemento eliminado: %i\n", colaLineal[frente]);
        frente++;
        if (frente > fin) {
            frente = fin = -1; // Resetear la cola cuando se vacía
        }
    }
}

void imprimirCola() {
    if (frente == -1) {
        printf("\nLa cola está vacía\n");
    } else {
        for (int i = frente; i <= fin; i++) {
            printf("%i |", colaLineal[i]);
        }
        printf("\n");
    }
}

int obtenerFrente() {
    if (frente == -1) {
        printf("\nLa cola está vacía\n");
        return -1; // Indica que la cola está vacía
    } else {
        return colaLineal[frente];
    }
}

int tamanoCola() {
    return MAX_SIZE;
}

int main() {
    insertarElementoscola(5);
    insertarElementoscola(15);
    insertarElementoscola(20);
    insertarElementoscola(35);
    insertarElementoscola(15);
    insertarElementoscola(48);
    insertarElementoscola(98);
    insertarElementoscola(56);
    insertarElementoscola(1);
    insertarElementoscola(3);
    imprimirCola();

    quitarElemento();
    imprimirCola();

    insertarElementoscola(389);
    imprimirCola();

    printf("\nElemento en el frente: %i\n", obtenerFrente());
    printf("Tamaño de la cola: %i\n", tamanoCola());

    return 0;
}

