#include <stdio.h>
#include <stdlib.h>

int soma (int N1, int N2){
  int resultado;
  resultado = N1+N2;
  return(resultado);
}

int main(){
  int valor1,valor2,resultado;
    printf ("Olá, favor digitar o primeiro valor a ser somado:\n");
    scanf("%d",&valor1);
    printf("Favor digitar o segundo valor a ser somado:\n");
    scanf("%d",&valor2);
    resultado=soma(valor1,valor2);
    printf("O resultado é: %d\n", resultado);
  return 0;
}