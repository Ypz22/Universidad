#include <stdio.h>
#include <omp.h>
#define N 10

int main()
{
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }
    int producto = 1;

#pragma omp parallel for reduction(* : producto)
    for (int i = 0; i < N; i++)
    {
        producto *= arr[i];
    }

    printf("Producto total: %d\n", producto);
    return 0;
}
