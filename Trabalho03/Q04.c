#include <stdio.h>

int soma(int vetor[], int tam);

int main(){
  int n=0,vetor[n],i=0, atual=0, total=0;
  
  printf("Favor escolher a quantidade de posições do vetor:\n");
  scanf ("%d",&n);

  for (i=0;i<n;i++){
    printf("Favor informar o valor na posição %d do vetor:\n",i+1);
    scanf("%d", &vetor[i]);
  }
  total = soma (vetor, n);
  printf ("A soma dos valores do vetor de %d posições é: %d\n", n, total);
}

int soma(int vetor[], int tam){
  int sum;
  if(tam == 1){
    return vetor[tam-1];
  }else{
    return vetor[tam-1] + soma(vetor, tam-1);
  } 
}

/*[2][4][6][13][7]

soma = vetor[tam] + vetor [tam-1]
  soma = vetor[5] + vetor [4]
    soma = vetor




int somar (vetor[], int n){
if (n==1){
  return vetor [n-1]
}else{
return vetor[n-1] + somar (vetor[], n-1)
}

  */