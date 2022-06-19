#include <stdio.h>

int soma(int a);

int main(){
  int resultado, numero = 0;
    while(numero<=0){
    printf ("Favor inserir o valor que gostaria de calcular a soma:\n");
    scanf ("%d", &numero);
    }
      printf("A soma entre 1 e o número %d é: %d\n", numero, soma(numero));
  }

int soma (int a){
  int somatorio = 0;
  
  if (a == 1){
    return 1;
  }else{
    somatorio = a + soma(a-1);
  }
  return somatorio;
  
}