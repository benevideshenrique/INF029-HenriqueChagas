#include <stdio.h>

int main (){
  int idade1;
  int idade2;
  int soma;

  printf("Favor informar a primeira idade:\n");
  scanf ("%d", &idade1);
  printf("Favor informar a segunda idade:\n");
  scanf ("%d", &idade2);
  soma=idade1+idade2;
  printf("A soma das idades é igual a: %d\n", soma);
}