/*23) A sequência de Padovan é uma sequência de naturais P(n) definida pelos valores
iniciais
P(0) = P(1) = p(2) = 1
e a seguinte relação recursiva
P(n) = P(n - 2) + P(n - 3) se n > 2
Alguns valores da sequência são: 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28...
Faça uma função recursiva q*/
#include <stdio.h>


int pad(int n);

int main(){
  int pos;
  printf("Favor informar a posição para qual deseja obter o valor na sequência de Padovan:\n");
  scanf("%d", &pos);
  printf("O número na posição %d na sequência de Padovan é: %d", pos, pad(pos));
  
}

int pad(int n){
  int valor = 0;
  if (n==0 || n==1 || n==2){
    return 1;
  }else
  valor = pad(n-2) + pad(n-3);
  return valor;
}