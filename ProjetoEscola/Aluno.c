#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "ProjetoEscola.h"
#define TAM 5
#define SUCESSO -1
#define ERRO_MATRICULA -2
#define ERRO_NOME -3
#define ERRO_SEXO -4
#define ERRO_NASCIMENTO -5
#define ERRO_CPF -6


int Cadastrar_aluno (Aluno alunos[], int qt_alunos){
  int validar_cpf=0, i=0, totChar=0;
  system ("clear");
  printf("-- Inserção de alunos --\n\n" );
  
  printf("Digite a matricula do aluno:\n");
  scanf("%d",&alunos[qt_alunos].matricula);
  setbuf(stdin, 0);

  if(alunos[qt_alunos].matricula <= 0){
    return ERRO_MATRICULA;
  }
  
  printf("Digite o nome do aluno:\n");
  fgets(alunos[qt_alunos].nome, 50, stdin); 
  size_t ln = strlen(alunos[qt_alunos].nome) - 1; 
  if (alunos[qt_alunos].nome[ln] == '\n'){
    alunos[qt_alunos].nome[ln] = '\0';
  }
    
  printf("Digite o sexo do aluno:\n");
  scanf ("%c", &alunos[qt_alunos].sexo); 
  if (alunos[qt_alunos].sexo != 'M'  && alunos[qt_alunos].sexo != 'F' && alunos[qt_alunos].sexo != 'f' && alunos[qt_alunos].sexo != 'm'){
    return ERRO_SEXO;
  }

  printf("Digite a data de nascimento do aluno:\n");
  scanf ("%d", &alunos[qt_alunos].data_nasc.dia);
  if (alunos[qt_alunos].data_nasc.dia < 1 || alunos[qt_alunos].data_nasc.dia >31){
    return ERRO_NASCIMENTO;
  }

  printf("Digite o mês de nascimento do aluno:\n");
  scanf ("%d", &alunos[qt_alunos].data_nasc.mes);
  if (alunos[qt_alunos].data_nasc.mes < 1 || alunos[qt_alunos].data_nasc.mes >12){
    return ERRO_NASCIMENTO;
  }
  else if (alunos[qt_alunos].data_nasc.mes == 2 && alunos[qt_alunos].data_nasc.dia>29){
    return ERRO_NASCIMENTO;
  }

  printf("Digite o ano de nascimento do aluno:\n");
  scanf ("%d", &alunos[qt_alunos].data_nasc.ano);
  if (alunos[qt_alunos].data_nasc.ano < 1900 || alunos[qt_alunos].data_nasc.ano >2022){
    return ERRO_NASCIMENTO;
  };
  getchar();
  printf("Digite o CPF do aluno:\n");
    fgets(alunos[qt_alunos].cpf, 12, stdin); 

  getchar();
  return SUCESSO;
}

void Listar_aluno(Aluno alunos[], int qt_alunos){
    setbuf(stdin,0);
    if(qt_alunos<=0){
        printf("\nNão existem alunos cadastrados.\n");
    }else{
        printf("\n------------ Listagem de alunos -------------\n");
        int i;

        for(i=0;i<qt_alunos;i++){
            printf("\n");
            printf("Matrícula:  %05d\n",alunos[i].matricula);
            printf("Nome:  %s\n",alunos[i].nome);
            printf("Sexo:  %c\n",alunos[i].sexo);
            printf("Data de nascimento:  %02d/%02d/%d\n",alunos[i].data_nasc.dia, alunos[i].data_nasc.mes, alunos[i].data_nasc.ano);
            printf("CPF:  %s\n",alunos[i].cpf);
        }
    }   
}

int Alterar_aluno (Aluno alunos[], int qt_alunos){
  int i = 0, matricula = 0;
  setbuf(stdin, 0);
  system ("clear");
    if (qt_alunos<0){
      printf("O número de alunos cadastrado é inválido.\n");
    }
    printf("-- Alteração de alunos --\n\n" );
    printf ("Favor inserir o número de matrícula do aluno a ser alterado:\n");
    scanf("%d",&matricula);
    int erro = 0;
    for(i=0; i<qt_alunos;i++){
      if (matricula == alunos[i].matricula){
        Aluno alunoTemp;
        printf("Digite a matricula do aluno:\n");
        scanf("%d", &alunoTemp.matricula);
        setbuf(stdin, 0);
      if(alunos[qt_alunos].matricula <= 0){
        erro = ERRO_MATRICULA;
      }
  
      printf("Digite o nome do aluno:\n");
      fgets(alunos[i].nome, 50, stdin); 
      size_t ln = strlen(alunos[i].nome) - 1; 
      if (alunos[i].nome[ln] == '\n'){
        alunos[i].nome[ln] = '\0';
      }
    
      printf("Digite o sexo do aluno:\n");
      scanf ("%c", &alunos[i].sexo); 
      if (alunos[i].sexo != 'M'  && alunos[i].sexo != 'F' && alunos[i].sexo != 'f' && alunos[i].sexo != 'm'){
        return ERRO_SEXO;
      }

      printf("Digite a data de nascimento do aluno:\n");
      scanf ("%d", &alunos[i].data_nasc.dia);
      if (alunos[i].data_nasc.dia < 1 || alunos[i].data_nasc.dia >31){
        return ERRO_NASCIMENTO;
      }

      printf("Digite o mês de nascimento do aluno:\n");
      scanf ("%d", &alunos[i].data_nasc.mes);
      if (alunos[i].data_nasc.mes < 1 || alunos[i].data_nasc.mes >12){
        return ERRO_NASCIMENTO;
      }
      else if (alunos[i].data_nasc.mes == 2 && alunos[i].data_nasc.dia>29){
        return ERRO_NASCIMENTO;
      }
    
      printf("Digite o ano de nascimento do aluno:\n");
      scanf ("%d", &alunos[i].data_nasc.ano);
      if (alunos[i].data_nasc.ano < 1900 || alunos[i].data_nasc.ano >2022){
        return ERRO_NASCIMENTO;
      };
      getchar();
      printf("Digite o CPF do aluno:\n");
        fgets(alunos[i].cpf, 12, stdin); 
    
      if (erro == 0){
        alunos[i].matricula = alunoTemp.matricula;
        strcpy(alunos[i].cpf, alunoTemp.cpf);
        
      }
      return SUCESSO;
      getchar();
        
      }
    }
  }


void Listar_aluno_sexo(Aluno alunos[], int qt_alunos){
    char sexo_busca;
    int i=0, achou=0, aux=0;
    setbuf(stdin,0);
    if(qt_alunos<=0){
        printf("Não existem alunos cadastrados.\n");
    }else{
        printf ("Favor digitar o sexo que deseja buscar\n");
        scanf ("%c", &sexo_busca);
        
        for(i=0;i<qt_alunos;i++){    
          printf("\n------------ Alunos do sexo masculino: -------------\n");
          for (i=0; i<qt_alunos;i++){
            if (alunos[i].sexo == 'm' || alunos[i].sexo == 'M' ){
              printf ("Matrícula: %d\n", alunos[i].matricula);
              printf ("Nome: %s\n", alunos[i].nome);
              printf ("Sexo: %c\n", alunos[i].sexo);
              printf("Data de nascimento: %02d/%02d/%d\n", alunos[i].data_nasc.dia, alunos[i].data_nasc.mes, alunos[i].data_nasc.ano);
              printf ("CPF: %s\n", alunos[i].cpf);
              achou = 1;
          }else{
              aux = 1;
          }
            if (achou == 0 && aux == 1){
              printf ("Não existem registros de alunos do sexo masculino.\n");
            }
        }
      }
    }
  }