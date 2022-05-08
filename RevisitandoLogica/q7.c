#include <stdio.h>


int main (){
  int n1, ver=0, i=0;
  printf ("Favor informar um número para a verificação:\n");
  scanf("%d",&n1);

  for (i=2;i<=n1;i++){
    if(n1 % i == 0){
      ver++;

    }
  }

  if (ver >= 2){
    printf ("O número não é primo.\n");

  }
  else{
    printf("O número é primo.\n");

  }

}