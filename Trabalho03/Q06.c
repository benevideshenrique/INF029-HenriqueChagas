/*Crie um programa em C, que contenha uma função recursiva que receba dois
inteiros positivos k e n e calcule kn
. Utilize apenas multiplicações. O programa principal
deve solicitar ao usuário os valores de k e n e imprimir o resultado da chamada da
função.*/

#include <stdio.h>

long pot (int n, int k);

int main(){
    int num = 0, exp = 0;
    long res = 0;
  
    printf("Favor informar o valor da base: \n");
    scanf ("%d", &num);
    printf("Favor informar o valor do expoente: \n");
    scanf ("%d", &exp);
  
    res = pot(num, exp);
    printf ("O valor final é: %ld\n", res);
}

long pot (int k, int n){
    long resultado = 0;
  
      if(n == 0){
        return 1;
      }else{
        resultado = k * pot(k, n-1);
        return resultado;
      }
  }
