/*14) Faça uma função recursiva que receba um número inteiro positivo par N e imprima
todos os números pares de 0 até N em ordem crescente.*/

#include <stdio.h>


void seqNum(int n);

int main(void){
    int num = 0;

    printf("Informe um número que deseja obter a sequência:");
    scanf("%d", &num);
    seqNum(num);
}

void seqNum(int n){

    if(n >= 0){
    	seqNum(n - 1)
    	if(n % 2 == 0)
    		printf("%d ", n);
    }
}
