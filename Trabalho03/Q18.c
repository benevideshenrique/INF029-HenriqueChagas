/*18) O superfatorial de um número N é definida pelo produto dos N primeiros fatoriais
de N. Assim, o superfatorial de 4 é
sf(4) = 1! * 2! * 3! * 4! = 288
Faça uma função recursiva que receba um número inteiro positivo N e retorne o
superfatorial desse número.
*/
#include <stdio.h>

long superfat(int n);
long fat(int a);

int main(){
  int num=0;
  printf("Favor informar o número para qual deseja o superfatorial: \n");
  scanf("%d", &num);
  printf("O valor do superfatorial do número %d é: %ld", num, superfat(num));
}

long fat (int a){
  long fatorial=0;
  if (a<=1){
    return 1;
  }else{
    fatorial = a * fat(a-1);
    return fatorial;
  }
}

long superfat(int n){
  long res=0;
  if (n==0){
    return 1;
  }else{
    res = fat(n) * superfat(n-1);
    return res;
  }
}
