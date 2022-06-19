#include <stdio.h>

/*Os números tribonacci são definidos pela seguinte recursão
Faça uma função recursiva que receba um número N e retorne o N-ésimo termo da
sequência de tribonacci. */

int trib (int n);

int main(){
  int num = 0;
  printf("Informe um número:\n");
  scanf("%d", &num);
  printf("O termo na posição %d da sequência de Tribonacci é:", num);
  printf(" %d", trib(num));
}

int trib (int n){
  int tribo;
  if (n == 0 || n == 1 ){
    return 0;
  }else if (n == 2){
    return 1;
  }else
    return trib(n-1) + trib(n-2) + trib(n-3);
}

/*The sequence begins 0, 0, 1, 2, 4, 7, 13, 24, 44, 81, 149, ...*/