#include <stdio.h>
#include <stdlib.h>

float subtrai (float N1, float N2, float N3){
  float resultado;
  resultado = N1-N2-N3;
  return(resultado);
}

int main(){
  float valor1,valor2,valor3,resultado;
    printf ("Olá, favor digitar o primeiro valor a ser subtraido:\n");
    scanf("%f",&valor1);
    printf("Favor digitar o segundo valor a ser subtraido:\n");
    scanf("%f",&valor2);
    printf("Favor digitar o terceiro valor a ser subtraido:\n");
    scanf("%f",&valor3);
    resultado=subtrai(valor1,valor2,valor3);
    printf("O resultado é: %.2f\n", resultado);
  return 0;
}
