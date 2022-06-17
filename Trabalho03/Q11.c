/*11) A multiplicação de dois números inteiros pode ser feita através de somas
sucessivas. Proponha um algoritmo recursivo Multip_Rec(n1,n2) que calcule a
multiplicação de dois inteiros.
*/

#include <stdio.h>

int Multip_Rec (int a, int b);

int main(){
    int resultado = 0, num1, num2;
    printf("Favor informar o valor do primeiro número:\n");
    scanf ("%d", &num1);
    printf("Favor informar o valor do segundo número:\n");
    scanf ("%d", &num2);
    resultado = Multip_Rec(num1, num2);
    printf("O valor da multiplicação %d por %d é: %d\n", num1, num2, resultado);
}

int Multip_Rec (int a, int b){
    if(b==1){
      return a;
    }else{
      int resultado = 0;
      resultado = a + Multip_Rec(a, b-1);
      return resultado;
    }
}