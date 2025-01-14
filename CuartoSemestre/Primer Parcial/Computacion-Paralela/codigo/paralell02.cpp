#include <iostream>
#include "omp.h"

int main()
{
    int counter = 0;
#pragma omp parallel
    {
#pragma omp critical // directivas
        counter++;
    }
    printf("Counter: %d\n", counter);
    return 0;
}