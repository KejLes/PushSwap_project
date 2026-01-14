
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 

void printIntPointerArray(int **arr, int size);

int main(void)
{
    int list[] = {1, 2, 3, 4, 5};
    int *ptr = list; // Pointer to the first element of the array
    printIntPointerArray(&ptr, 5);
    return 0;
}

void printIntPointerArray(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Element %d: %d\n", i, (*arr)[i]);
    }
}