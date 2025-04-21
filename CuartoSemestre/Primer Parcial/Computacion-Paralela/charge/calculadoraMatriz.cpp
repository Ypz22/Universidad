#include <iostream>
#include <omp.h>
#include <vector>
#include <cstdlib>
#include <ctime>

#define N 1000000 // Tamaño de la matriz

// Función para sumar una matriz con balanceo de carga estático
void suma_estatica(const std::vector<int> &matriz, int &resultado)
{
    int suma = 0;
#pragma omp parallel for schedule(static) reduction(+ : suma)
    for (int i = 0; i < N; i++)
    {
        suma += matriz[i];
    }
    resultado = suma;
}

// Función para sumar una matriz con balanceo de carga dinámico
void suma_dinamica(const std::vector<int> &matriz, int &resultado)
{
    int suma = 0;
#pragma omp parallel for schedule(dynamic) reduction(+ : suma)
    for (int i = 0; i < N; i++)
    {
        suma += matriz[i];
    }
    resultado = suma;
}

int main()
{
    // Inicialización de la matriz con valores aleatorios
    std::vector<int> matriz(N);
    std::srand(std::time(0));
    for (int i = 0; i < N; i++)
    {
        matriz[i] = std::rand() % 10; // Números aleatorios entre 0 y 9
    }

    int resultado_estatico, resultado_dinamico;

    // Medir tiempo para balanceo estático
    double inicio_estatico = omp_get_wtime();
    suma_estatica(matriz, resultado_estatico);
    double fin_estatico = omp_get_wtime();
    std::cout << "Suma estática: " << resultado_estatico << std::endl;
    std::cout << "Tiempo de ejecución (balanceo estático): " << fin_estatico - inicio_estatico << " segundos" << std::endl;

    // Medir tiempo para balanceo dinámico
    double inicio_dinamico = omp_get_wtime();
    suma_dinamica(matriz, resultado_dinamico);
    double fin_dinamico = omp_get_wtime();
    std::cout << "Suma dinámica: " << resultado_dinamico << std::endl;
    std::cout << "Tiempo de ejecución (balanceo dinámico): " << fin_dinamico - inicio_dinamico << " segundos" << std::endl;

    return 0;
}
