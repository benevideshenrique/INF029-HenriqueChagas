#include <stdio.h>

  int main (){
  int i=0;
  int num=0, fat=0;

  printf("Favor inserir o número do qual deseja o fatorial:\n");
  scanf("%d", &num);
    fat=num;
    if (num<1){
      fat=1;
    }
    else
      for (i=1;i<num;i++){
      
        fat= fat*i;       
  }
  printf ("\nO fatorial do número é: %d", fat);

}