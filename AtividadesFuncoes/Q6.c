#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char l1;
    char l2;
    char l3;
}Letras;

Letras ler3letras();

int main ()
{
Letras letrasimpressas;
    letrasimpressas = ler3letras();
    printf("\nAs três letras digitadas foram: \n");
    printf(" %c\n", letrasimpressas.l1);
    printf(" %c\n", letrasimpressas.l2);
    printf(" %c\n", letrasimpressas.l3);
    return 0;
}

Letras ler3letras()
{
    Letras let;
    printf("\nInforme a primeira letra: ");
    scanf(" %c", &let.l1);
    printf("\nInforme a segunda letra: ");
    scanf(" %c", &let.l2);
    printf("\nInforme a terceira letra: ");
    scanf(" %c", &let.l3);
    return let;
}