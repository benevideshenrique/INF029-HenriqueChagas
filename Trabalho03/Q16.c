#include <stdio.h>

int fatd(int n) ;

int main(){
  int num = 0;
    printf("Favor digitar o número que deseja obter o fatorial:\n");
    scanf("%d", &num);
    printf("%d ", fatd(num));

    return 0;
}

int fatd(int n) {
	if(n == 1) {
		return 1;
	}
	if(n % 2 == 0) {
		return 0;
	}
	return n * fatd(n - 2);
}
