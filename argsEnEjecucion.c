/**
 * Quería saber si al hacer: ./.out "23 12 45 67" son cuatro argumentos o uno solo
 * Respuesta: Es un solo argumento, entonces hay espacios dentro del string
 */
#include <stdio.h> 
#include <unistd.h>

int main(int argc, char **argv)
{
    printf("%s", argv[1]);
}