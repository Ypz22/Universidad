#include <iostream>
#include <cstdlib>  // Para las funciones srand() y rand()
#include <ctime>    // Para la función time()

using namespace std;
int contadorIteraciones = 0; 
const int tamano = 100;  

// Función para combinar dos mitades de un arreglo ordenado
void combinar(int a[], int izquierda, int medio, int derecha) {

    int aux1 = medio - izquierda + 1;
    int aux2 = derecha - medio;
    // Arreglos temporales para almacenar las dos mitades
    int mitadIzquierda[tamano];
    int mitadDerecha[tamano];

    for (int i = 0; i < aux1; i++)
        mitadIzquierda[i] = a[izquierda + i];
    for (int i = 0; i < aux2; i++)
        mitadDerecha[i] = a[medio + 1 + i];

    int i = 0, j = 0, k = izquierda;

    // Combina los arreglos temporales de vuelta en el arreglo original `a`
    while (i < aux1 && j < aux2) {
        contadorIteraciones++;
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
        contadorIteraciones++;
        a[k] = mitadIzquierda[i];
        i++;
        k++;
    }
    // Copia los elementos restantes de la mitad derecha, si los hay
    while (j < aux2) {
        contadorIteraciones++;
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

    int medio = izquierda + (derecha - izquierda) / 2;

    mergeSort(a, izquierda, medio);

    mergeSort(a, medio + 1, derecha);

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
    int a[tamano] = {}; 

    srand(time(0));  // Inicializa la semilla del generador de números aleatorios

    // Llena el arreglo con números aleatorios entre 1 y 500
    for (int i = 0; i < tamano; i++) {
        a[i] = generarNumeroAleatorio(1, 500);
    }

    cout << "Arreglo inicial: ";
    imprimirArreglo(a);  

    mergeSort(a, 0, tamano - 1); 

    cout << "Arreglo ordenado con mergeSort: ";
    imprimirArreglo(a);  

    cout << "Numero de iteraciones realizadas: " << contadorIteraciones << endl;

    return 0;
}
