#include <stdio.h>

int maxdiv(int a, int b);

int main(){
    int num1=0, num2=0, resultado=0;
    printf("Favor inserir o primeiro valor\n");
    scanf("%d", &num1);
    printf("Favor inserir o segundo valor\n");
    scanf("%d", &num2);

    printf("O máximo divisor comum entre os números %d e %d é: %d\n",num1, num2, maxdiv(num1, num2));

    return 0;
}


int maxdiv(int n1, int n2) {
	if( n2 == 0) {
		return n1;
	}
	maxDiv(n2, n1%n2);
}