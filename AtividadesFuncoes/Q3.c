#include<stdio.h>
#include<stdlib.h>

int fatorial (int n1){
int resultado,i;
    if (n1==1||n1==0){
        resultado=1;
        return(resultado);
    }

    resultado=n1;
    for(i=n1-1;i>1;i--){
        resultado*=i;
        }
return (resultado);
}

int main(){
    int num,resultado;
    printf("Favor digitar o numero inteiro que gostaria de saber o valor fatorial:\n");
    scanf("%d",&num);
    if(num<0){
             do{
                printf("O numero informado nao possui fatorial.\n");
                printf("Favor informar um novo numero.\n");
                scanf("%d",&num);
            }while(num<0);
        }
    resultado=fatorial(num);
    printf("O resultado e:%d\n\n",resultado); 
    return 0;
}