#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ProjetoEscola.h"
#define TAM 5
#define SUCESSO -1
#define ERRO_MATRICULA -2
#define ERRO_NOME -3
#define ERRO_SEXO -4
#define ERRO_NASCIMENTO -5
#define ERRO_CPF -6

int Cadastrar_professor(Professor professor[], int qt_professor){
int validar_cpf=0;
  system ("clear");
  printf("-- Inserção de professores --\n\n" );
  
  printf("Digite a matricula do professor:\n");
  scanf("%d",&professor[qt_professor].matricula);
  setbuf(stdin, 0);

  if(professor[qt_professor].matricula <= 0){
    return ERRO_MATRICULA;
  }
  
  printf("Digite o nome do professor:\n");
  fgets(professor[qt_professor].nome, 50, stdin); 
  size_t ln = strlen(professor[qt_professor].nome) - 1; 
  if (professor[qt_professor].nome[ln] == '\n'){
    professor[qt_professor].nome[ln] = '\0';
  }
    
  printf("Digite o sexo do professor:\n");
  scanf ("%c", &professor[qt_professor].sexo); 
  if (professor[qt_professor].sexo != 'M'  && professor[qt_professor].sexo != 'F' && professor[qt_professor].sexo != 'f' && professor[qt_professor].sexo != 'm'){
    return ERRO_SEXO;
  }

  printf("Digite a data de nascimento do professor:\n");
  scanf ("%d", &professor[qt_professor].data_nasc.dia);
  if (professor[qt_professor].data_nasc.dia < 1 || professor[qt_professor].data_nasc.dia >31){
    return ERRO_NASCIMENTO;
  }

  printf("Digite o mês de nascimento do professor:\n");
  scanf ("%d", &professor[qt_professor].data_nasc.mes);
  if (professor[qt_professor].data_nasc.mes < 1 || professor[qt_professor].data_nasc.mes >12){
    return ERRO_NASCIMENTO;
  }
  else if (professor[qt_professor].data_nasc.mes == 2 && professor[qt_professor].data_nasc.dia>29){
    return ERRO_NASCIMENTO;
  }
  printf("Digite o ano de nascimento do professor:\n");
  scanf ("%d", &professor[qt_professor].data_nasc.ano);
  if (professor[qt_professor].data_nasc.ano < 1900 || professor[qt_professor].data_nasc.ano >2022){
    return ERRO_NASCIMENTO;
  };
  printf("\nDigite o CPF do professor, utilizar apenas números:\n ");
  fgets(professor[qt_professor].cpf, 11, stdin);
  printf("%s", professor[qt_professor].cpf);
  
  getchar();
  return SUCESSO;
}

