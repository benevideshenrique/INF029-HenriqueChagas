#include <stdio.h>
#include <locale.h>

typedef struct 
{
    int n1;
    int n2;
    int n3;
    int n4;
}Numeros;

Numeros ler4Numeros(void);

int main (){

Numeros numerosimpressos;

    numerosimpressos = ler4Numeros();

    printf("\nOs quatro números digitados foram: \n");
    printf("%d\n", numerosimpressos.n1);
    printf("%d\n", numerosimpressos.n2);
    printf("%d\n", numerosimpressos.n3);
    printf("%d\n", numerosimpressos.n4);
    return 0;
}

Numeros ler4Numeros(void)
{

    Numeros num;

    printf("\nInforme o primeiro número: ");
    scanf("%d", &num.n1);
    printf("\nInforme o segundo número: ");
    scanf("%d", &num.n2);
    printf("\nInforme o terceiro número: ");
    scanf("%d", &num.n3);
    printf("\nInforme o quarto número: ");
    scanf("%d", &num.n4);

    return num;
}