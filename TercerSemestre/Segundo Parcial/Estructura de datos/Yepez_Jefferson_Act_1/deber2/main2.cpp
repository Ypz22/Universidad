#include <iostream>
#include <stdlib.h>
#include <string>
#include "ListHandler.h"

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR "cls"
    #define PAUSE "pause"
#else
    #include <unistd.h>
    #define CLEAR "clear"
    #define PAUSE "read -p 'Presione Enter para continuar...' var"
#endif

using namespace std;

int main() {
    int opciones; // Variable para almacenar la opción seleccionada por el usuario.

    lista listas; // Se crea una instancia de la clase 'lista'.

    // Se insertan algunos premios en la ruleta.
    listas.insertarPremios("Balon");
    listas.insertarPremios("rompecabezas");
    listas.insertarPremios("mouse");
    listas.insertarPremios("teclado");

    // Bucle principal del programa.
    do {
        system(CLEAR); // Limpia la pantalla.
        printf("**********************************************************\n");
        printf("*              Bienvenido a la Ruleta                    *\n");
        printf("**********************************************************\n");
        printf("\nPremios de la ruleta: \n");
        listas.imprimirLista(); // Imprime los premios disponibles en la ruleta.
        printf("\n1.- Girar la ruleta\n");
        printf("2.- Salir de la ruleta\n");
        cout << "\nIngrese la opcion que desea realizar: ";
        cin >> opciones; // Lee la opción ingresada por el usuario.
        cout << endl;

        // Control de flujo basado en la opción seleccionada por el usuario.
        if (opciones == 1) {
            listas.girarRuleta(); // "Gira" la ruleta y muestra el premio ganado.
            system(PAUSE); // Pausa la ejecución hasta que el usuario presione una tecla.
        } else if (opciones == 2) {
            cout << "Gracias por jugar a la ruleta!"; // Mensaje de despedida.
            break; // Sale del bucle.
        } else {
            printf("Opcion no valida, intente nuevamente!\n"); // Mensaje de opción inválida.
            system(PAUSE); // Pausa la ejecución hasta que el usuario presione una tecla.
        }

    } while (opciones != 2); // El bucle se ejecuta hasta que el usuario elija salir de la ruleta.

    return 0;
}

