#include <omp.h>
#include <iostream>

#define N 1000000

int main()
{
    long int array[N];
    long int sum_p = 0;
    long int sum_c = 0;

    // Inicializacion del arreglo
    for (int i = 0; i < N; i++)
    {
        array[i] = i + 1;
    }
    // OU YEAAAAAAAAAAAAAAAAA
    omp_set_num_threads(8);
    double t0 = omp_get_wtime();
#pragma omp parallel for reduction(+ : sum_p) schedule(dynamic, 10)
    for (int i = 0; i < N; i++)
    {
        sum_p += array[i];
    }
    double t1 = omp_get_wtime();

    double t2 = omp_get_wtime();
    for (int i = 0; i < N; i++)
    {
        sum_c += array[i];
    }
    double t3 = omp_get_wtime();

    std::cout << "Suma paralela: " << sum_p << " en " << t1 - t0 << " segundos" << std::endl;
    std::cout << "Suma secuencial: " << sum_c << " en " << t3 - t2 << " segundos" << std::endl;

    if ((t1 - t0) < (t3 - t2))
    {
        std::cout << "Imbecil" << std::endl;
    }
}