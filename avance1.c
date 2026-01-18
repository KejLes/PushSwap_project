
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <stdbool.h>

int ft_atoi(char* listaString); 
bool swapElementsList(int argc, char **listaString, int** listaNumbersA);

/* Voy a haver que al pasar al array de int, se guarden los numeros en un int y comprobar que 
no pase el int_max, si pasa, devolver error */

/* Tengo que comprobar si se puden introducir el 0 y números negativos para usarlos en códigos de errores*/
/* Quiero saber si al hacer malloc, en este caso con int, los elemntos se guardan en orden por la memoria,
o aleatorio*/
int main(int argc, char **listaString)
{
    int i;

    i = 1;
    int *listaNumbersA;     // Creamos la lista de enteros A con malloc
    if (!(listaNumbersA = (int *)malloc((argc - 1) * sizeof(int))))
    {
        printf("Lista no creada");
        return(0);
    }
    swapElementsList(argc, listaString, &listaNumbersA);
    for (int j = 0; j < argc - 1; j++)
    {
        printf("ListaNumerosA[%d]: %d\n", j, listaNumbersA[j]);
    }
    free(listaNumbersA);
    return(0); 
}

// Para avisar de algún error se devuelve MAX_INT + 1
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
            return (-1); // Devolver MAX_INT + 1 si el número está repetido o si está fuera de rango (<MIN_INT o >MAX_INT)
        i++;
    }
    return(number);
}

bool swapElementsList(int argc, char **listaString, int** listaNumbersA)
{
    while(argc - 1)
    {
        (*listaNumbersA)[argc - 2] = ft_atoi(listaString[argc - 1]);
        argc--;
        
    }
    return (true);
}

double enterElementsInList_check(int size, char **listaString, int **stackA)
{
    int i;
    double number;

    number = 0;
    while (size - 1)
    {
        i = 0;
        while (listaString[size - 1][i])
        {
            if (listaString[size - 1][i] >= '0' && listaString[size - 1][i] <= '9')
                number = number * 10 + listaString[size - 1][i] - '0';
            else
                return (INT_MAX + 1); // Devolver MAX_INT + 1 si el número está rep etido o si está fuera de rango (<MIN_INT o >MAX_INT)
            i++;
        }
        if (number > INT_MAX || number < INT_MIN)
            return (INT_MAX + 1);
        else
        {
            while((int)number != listaString[size - 1][i])
            {
                i++;
            } 
        }
        (*stackA)[size - 2] = (int)number;
        number = 0;
        i = 0;
    }
}

// Se pasa el primer elemento de
void swap_a(int **listaNumbersA, int **listaNumbersB, int size)
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