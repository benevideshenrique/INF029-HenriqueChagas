/*13) Faça uma função recursiva que receba um número inteiro positivo N e imprima
todos os números naturais de 0 até N em ordem decrescente.*/

#include <stdio.h>

int PrintNum (int n);

int main (){
  int numero = 0;
  printf("Favor informar o número que deseja verificar\n");
  scanf("%d", &numero);
  printf("A sequência numérica é:\n");
  PrintNum(numero);  
}

int PrintNum(int n){
      if (n>=0){
      printf ("%d\n", n);
      n--;
      PrintNum(n);
    }else {
        return 0;
        }
}