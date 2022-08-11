#include <stdio.h>
#include "printhello/printhello.h"

int main() 
{
    print_hello("This is a test executable for \"printhello\" lib");

    printf("\nPress any key to exit...");
    getchar();

    return 0;
}