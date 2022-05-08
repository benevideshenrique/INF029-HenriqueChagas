#include <stdio.h>

int main (){
  int v1,v2,aux;
  printf("Digitar o primeiro valor:\n");
  scanf("%d",&v1);
  printf("Digitar o segundo valor:\n");
  scanf("%d",&v2);
  aux=v2;
  v2=v1;
  v1=aux;
  
  printf ("O valor invertido da primeira variável é: %d. O valor da segunda variável é %d", v1,v2);
}