#include <stdio.h>
#include <omp.h>
#define N 100

int main()
{
    int arr[N], suma = 0;
    for (int i = 0; i < N; i++)
        arr[i] = i;
#pragma omp parallel for reduction(+ : suma)
    for (int i = 0; i < N; i++)
    {
        suma += arr[i];
    }
    printf("Suma total: %d\n", suma);
    return 0;
    // #pragma omp parallel
    //     {
    //         printf("Hola desde el hilo %d\n", omp_get_thread_num());
    //     }
    //     return 0;
}
