/*12) Faça uma função recursiva que receba um número inteiro positivo N e imprima
todos os números naturais de 0 até N em ordem crescente.*/

#include <stdio.h>

int PrintNum (int n, int aux);

int main(){
  int num=0;
  printf("Favor digitar o número que deseja ver a sequência:\n");
  scanf("%d\an", &num);
  int aux= num;
  num=0;
  printf("A sequência solicitada é:\n");
  PrintNum(num, aux);

}  

int PrintNum(int n, int aux){
    if (n<=aux){
      printf ("%d\n", n);
      n++;
      PrintNum(n,aux);
    }
      else {
          return 0;
        }
  }