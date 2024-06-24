#include <iostream>
#include <stdlib.h>
#include <string>
#include "ListHandler.h"

using namespace std;

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR "cls"
    #define PAUSE "pause"
#else
    #include <unistd.h>
    #define CLEAR "clear"
    #define PAUSE "read -p 'Presione Enter para continuar...' var"
#endif

int main() {
    lista listas; // Se crea una instancia de la clase 'lista'.
    int opciones; // Variable para almacenar la opción seleccionada por el usuario.

    // Se insertan algunos números en la lista.
    listas.insertarFinal(5);
    listas.insertarFinal(9);
    listas.insertarFinal(14);
    listas.insertarFinal(80);
    listas.insertarFinal(11);
    listas.insertarFinal(9);
    listas.insertarFinal(22);
    listas.insertarFinal(11);
    listas.insertarFinal(10);

    // Bucle principal del programa.
    do {
        system(CLEAR); // Limpia la pantalla.
        printf("**********************************************************\n");
        printf("*                 Operaciones con listas                 *\n");
        printf("**********************************************************\n");
        printf("\nLista original: \n");
        listas.imprimirLista(); // Imprime la lista original.
        printf("\nOpciones:\n");
        printf("\n1.- Eliminar los numeros repetidos de la lista\n");
        printf("2.- Sumatoria de los numeros de la lista\n");
        printf("3.- Cuadrados de la lista original\n");
        printf("4.- Salir del sistema\n");
        cout << "\nIngrese la opcion que desea realizar: ";
        cin >> opciones; // Lee la opción ingresada por el usuario.

        cout << endl;

        // Switch para ejecutar la opción seleccionada por el usuario.
        switch(opciones) {
            case 1:
                printf("Eliminar los numeros repetidos de la lista: \n");
                listas.eliminarNumeroRepetido(); // Elimina los números repetidos.
                listas.imprimirLista(); // Imprime la lista actualizada.
                system(PAUSE); // Pausa la ejecución hasta que el usuario presione una tecla.
                break;
            case 2:
                printf("Sumatoria de los numeros de la lista: \n");
                listas.calcularSumatoriaLista(); // Calcula la sumatoria de los números en la lista.
                system(PAUSE);
                break;
            case 3:
                printf("Cuadrados de la lista original:\n");
                listas.listaCuadradosOriginales().imprimirLista(); // Imprime los cuadrados de la lista original.
                system(PAUSE);
                break;
            case 4:
                printf("Gracias por usar el sistema!\n");
                break;
            default:
                printf("Opcion no valida, intente nuevamente\n");
                system(PAUSE);
                break;
        }

    } while(opciones != 4); // El bucle se ejecuta hasta que el usuario elija salir del sistema.

    return 0;
}

