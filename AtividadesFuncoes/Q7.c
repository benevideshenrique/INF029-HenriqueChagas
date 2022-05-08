#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char palavra1[10];
    char palavra2[10]; 
    char palavra3[10];  
}palavras;
    

palavras ler3palavras (void);

int main(){
    palavras palavrasimpressas;
    palavrasimpressas = ler3palavras();
    printf("\n*******************\n");
    printf("\nAs palavras inseridas foram:\n");
    printf("%s", palavrasimpressas.palavra1);
    printf("%s", palavrasimpressas.palavra2);
    printf("%s", palavrasimpressas.palavra3);
    return 0;
}

palavras ler3palavras () {
    palavras inserirpalavras;
    printf("Favor inserir o 1ª palavra:\n");
    fgets(inserirpalavras.palavra1,10,stdin);
    printf("Favor inserir o 2ª palavra:\n");
    fgets(inserirpalavras.palavra2,10,stdin);
    printf("Favor inserir o 3ª palavra:\n");
    fgets(inserirpalavras.palavra3,10,stdin);
    return inserirpalavras;
    }