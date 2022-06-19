#include <stdio.h>

int fib (int a);

int main(){
  int n=0;
  int vfib=0;
  
  printf("Digite o número que deseja obter o termo na sequencia de Fibonacci:\n");
  scanf ("%d", &n);
  vfib = fib(n);
  printf ("O valor na posição %d é %d\n",n,fib(n));
}

int fib (int a){
  int fibonacci=0;
  if (a==0){
    return 0;
  }else if (a==1 || a==2){
    return 1;
  }else{
    fibonacci = fib(a-1) + fib (a-2);
    return fibonacci;
  }
}


/*fibonacci: 
fib (0) = 0
  fib (1) = 1
    fib (2) = 1
      fib (3) = 2
        fib (4) = 3
          fib (5) = 5*/