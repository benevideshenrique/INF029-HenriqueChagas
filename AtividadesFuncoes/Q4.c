#include <stdio.h>
#include <stdlib.h>

void ler3numeros(int vet[3]);

int main()
{
    int numerosimpressos[3];
    ler3numeros(numerosimpressos);
    printf("\n\nOs números digitados são:\n");
    printf("%d\n", numerosimpressos[0]);
    printf("%d\n", numerosimpressos[1]);
    printf("%d\n", numerosimpressos[2]);
    return 0;
}

void ler3numeros(int vetornumeros[3]){
   int i=0;
   for(i=0;i<3;i++){
       printf ("Digitar o %dº numero:\n",i+1);
       scanf(" %d",&vetornumeros[i]);
}
}