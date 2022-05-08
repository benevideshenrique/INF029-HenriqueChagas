#include <stdio.h>

int main (){
  int idade=0;

  do{
    printf("Favor inserir sua idade: \n");
    scanf("%d",&idade);

    if (idade>=0){
      if (idade>=18){
        printf("Você é maior de idade.\n\n");
      }
      else{
        printf ("Você é menor de idade\n\n");
      } 
    }
    else{
      printf("Idade não é válida (negativa). Finalizando o programa...\n\n");
    }
  } while (idade>=0);
}