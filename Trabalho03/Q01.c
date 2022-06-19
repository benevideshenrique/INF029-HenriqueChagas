#include <stdio.h>

long fat(int a);

int main(){
  int numero = 0;
  long fatorial = 0;
  
  printf ("Favor digitar o número do qual deseja obter o fatorial:\n");
  scanf ("%d", &numero);
  printf("Fatorial de %d é %ld",numero,fat(numero));
  
  return 0;
}

long fat (int a){
  int fatorial=0;
  if (a<=1){
    return 1;
  }else{
    fatorial = a * fat(a-1);
    return fatorial;
  }
}





