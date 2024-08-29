#include <iostream>
#include <cstdlib>  // Para las funciones srand() y rand()
#include <ctime>    // Para la función time()

using namespace std;

const int tamano = 100;  // Define el tamaño del arreglo

// Función para combinar dos mitades de un arreglo ordenado
void combinar(int a[], int izquierda, int medio, int derecha) {
    // Calcula el tamaño de las dos subarreglos (mitad izquierda y derecha)
    int aux1 = medio - izquierda + 1;
    int aux2 = derecha - medio;
    // Arreglos temporales para almacenar las dos mitades
    int mitadIzquierda[tamano];
    int mitadDerecha[tamano];
    // Copia los datos a los arreglos temporales
    for (int i = 0; i < aux1; i++)
        mitadIzquierda[i] = a[izquierda + i];
    for (int i = 0; i < aux2; i++)
        mitadDerecha[i] = a[medio + 1 + i];

    int i = 0, j = 0, k = izquierda;
    // Combina los arreglos temporales de vuelta en el arreglo original `a`
    while (i < aux1 && j < aux2) {
        if (mitadIzquierda[i] <= mitadDerecha[j]) {
            a[k] = mitadIzquierda[i];
            i++;
        } else {
            a[k] = mitadDerecha[j];
            j++;
        }
        k++;
    }
    // Copia los elementos restantes de la mitad izquierda, si los hay
    while (i < aux1) {
        a[k] = mitadIzquierda[i];
        i++;
        k++;
    }
    // Copia los elementos restantes de la mitad derecha, si los hay
    while (j < aux2) {
        a[k] = mitadDerecha[j];
        j++;
        k++;
    }
}

// Función recursiva para dividir el arreglo y luego combinarlo usando "combinar"
void mergeSort(int a[], int izquierda, int derecha) {
    if (izquierda >= derecha) {
        return;  // Caso base: si el arreglo tiene un solo elemento, ya está ordenado
    }
    // Encuentra el punto medio del arreglo
    int medio = izquierda + (derecha - izquierda) / 2;

    // Aplica mergeSort recursivamente en la mitad izquierda
    mergeSort(a, izquierda, medio);

    // Aplica mergeSort recursivamente en la mitad derecha
    mergeSort(a, medio + 1, derecha);

    // Combina las dos mitades ordenadas
    combinar(a, izquierda, medio, derecha);
}

// Función para imprimir el arreglo
void imprimirArreglo(int a[]) {
    for (int i = 0; i < tamano; i++) {
        cout << a[i] << " |";
    }
    cout << endl;
}

// Función para generar un número aleatorio
int generarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    int a[tamano] = {};  // Define un arreglo 

    srand(time(0));  // Inicializa la semilla del generador de números aleatorios

    // Llena el arreglo con números aleatorios entre 1 y 500
    for (int i = 0; i < tamano; i++) {
        a[i] = generarNumeroAleatorio(1, 500);
    }

    cout << "Arreglo inicial: ";
    imprimirArreglo(a);  // Imprime el arreglo antes de ordenar

    mergeSort(a, 0, tamano - 1);  // Ordena el arreglo usando mergeSort

    cout << "Arreglo ordenado con mergeSort: ";
    imprimirArreglo(a);  // Imprime el arreglo después de ordenar

    return 0;
}
