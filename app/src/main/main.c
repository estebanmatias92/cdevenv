#include <stdio.h>
#include "printhello/printhello.h"

int main() 
{
    //print_hello("This is the src/main executable");

    char name[20];

    printf("Ingresa tu nombre: ");
    fflush(stdin);
    scanf(" %s", name);

    printf("\nTu nombre es %s\n", name);

    return 0;
}
