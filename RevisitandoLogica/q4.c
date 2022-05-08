#include <stdio.h>

int main (){
  int v1,v2;
  printf("Digitar o primeiro valor:\n");
  scanf("%d",&v1);
  printf("Digitar o segundo valor:\n");
  scanf("%d",&v2);
  v2 = v1+v2;
  v1 = v2-v1;
  v2 = v2-v1;
  printf ("O valor invertido da primeira variável é: %d. O valor da segunda variável é %d", v1,v2);
}