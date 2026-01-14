
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 

int ft_atoi(char* listaString);
void swapElementsList(int argc, char **listaString, int** listaNumbersA);

int main(int argc, char **listaString)
{
    int i = 1;
    while (i != argc) 
    {
        printf("%s\n", listaString[i]);
        i++; 
    }
    int *listaNumbersA;
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
    int i;

    i = 0;
    while(argc - 1)
    {
        *listaNumbersA[argc - 2] = ft_atoi(listaString[argc - 2]);
        argc--;
        printf("%d\n", *listaNumbersA[argc - 2]);
    }
}

int create_elements_in_list(char **listaString, char *lista2) 
{

} 

void    swap_list(char **listaString, char *lista2) 
{

}
