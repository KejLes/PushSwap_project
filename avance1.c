
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 

int ft_atoi(char* listaString);
void swapElementsList(int argc, char **listaString, int** listaNumbersA);

/* Voy a haver que al pasar al array de int, se guarden los numeros en un int y comprobar que 
no pase el int_max, si pasa, devolver error */

/* Tengo que comprobar si se puden introducir el 0 y números negativos para usarlos en códigos de errores*/
int main(int argc, char **listaString)
{
    int i = 1;
    while (i != argc) 
    {
        printf("String: %s\n", listaString[i]);
        i++; 
    }
    int *listaNumbersA;     // Creamos la lista de enteros A con malloc
    if (!(listaNumbersA = (int *)malloc(2 * (argc - 1) * sizeof(int))))
    {
        printf("Lista no creada");
        return(0);
    }
    swapElementsList(argc, listaString, &listaNumbersA);
    for (int j = 0; j < argc - 1; j++)
    {
        printf("ListaNumerosA[%d]: %d\n", j, listaNumbersA[j]);
    }
    int *listaNumbersB;     // Creamos la lista de enteros B con malloc
    if (!(listaNumbersB = (int *)malloc(2 * (argc - 1) * sizeof(int))))
    {
        printf("Lista no creada");
        return(0);
    }
    free(listaNumbersB);
    free(listaNumbersA);
    return(0); 
}
int ft_atoi(char* listaString)
{
    int number;
    int i;

    number = 0;
    i = 0;
    while (listaString[i])
    {
        if (listaString[i] >= '0' && listaString[i] <= '9')
        {
            number = number * 10 + listaString[i] - '0';
        }
        else
            return (-1);            // Hay que comprobar que no se puedan introducir números negativos.
        i++;
    }
    return(number);
}

void swapElementsList(int argc, char **listaString, int** listaNumbersA)
{
    while(argc - 1)
    {
        (*listaNumbersA)[argc - 2] = ft_atoi(listaString[argc - 1]);
        argc--;
    }
}

// Se pasa el primer elemento de
void swap_a_to_b(int **listaNumbersA, int **listaNumbersB, int size)
{
    
}
/*
int create_elements_in_list(char **listaString, char *lista2) 
{

} 

void    swap_list(char **listaString, char *lista2) 
{

}
*/