#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}datanascimento;

typedef struct {
    char nome[50];
    char cpf[20]; 
    char genero; 
    datanascimento datanasc;
}cadastroCliente;


cadastroCliente cadastrarcliente ();

int main(){
    cadastroCliente cadastroimpresso;
    cadastroimpresso = cadastrarcliente();
    printf("\n*************************************\n");
    printf("\nCliente cadastrado:\n");
    printf("Nome: %s",cadastroimpresso.nome);
    printf("Numero de CPF: %s",cadastroimpresso.cpf);
    printf("Genero: %c",cadastroimpresso.genero);
    printf("Data de nascimento: %d/%d/%d\n", cadastroimpresso.datanasc.dia,cadastroimpresso.datanasc.mes,cadastroimpresso.datanasc.ano);
    return 0;
}

cadastroCliente cadastrarcliente () {
    cadastroCliente entrada_dados;
    printf("Favor inserir o nome do cliente:\n");
    fgets(entrada_dados.nome,50,stdin);
    printf("Favor inserir o CPF do cliente.\n");
    fgets(entrada_dados.cpf,20,stdin);
    printf("Favor inserir o gênero do cliente. Utilize M para gênero masculino, F para feminino e O para outro\n");
    entrada_dados.genero=getchar();
    printf("Favor inserir o dia do nascimento do cliente:\n");
    scanf("%d",&entrada_dados.datanasc.dia);
    printf("Favor inserir o mês do nascimento do cliente:\n");
    scanf("%d",&entrada_dados.datanasc.mes);
    printf("Favor inserir o ano do nascimento do cliente:\n");
    scanf("%d",&entrada_dados.datanasc.ano);
    
    return entrada_dados;
}