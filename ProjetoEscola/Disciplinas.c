#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "ProjetoEscola.h"
#define TAM_ALUNO_DISC 5
#define SUCESSO -1
#define ERRO_MATRICULA -2
#define ERRO_NOME -3
#define ERRO_COD_DISCIPLINA -7
#define ERRO_SEMESTRE_DISCIPLINA -8


int Cadastrar_disciplinas (Disciplinas disciplinas[], int qt_disciplinas, Professor professores[], int qt_professor)
{

  int i,j;
  //qtd_prof--;
  setbuf(stdin, 0);
  system ("clear");
  
  printf("-- Inserção de Discilinas --\n\n" );
  
  printf("Digite o código da disciplina:\n");
  scanf("%d",&disciplinas[qt_disciplinas].codigo);
  setbuf(stdin,0);
    if(disciplinas[qt_disciplinas].codigo <= 0){
    return ERRO_COD_DISCIPLINA;
  }
   
  getchar();
  printf("Digite o nome da disciplina:\n");
  fgets(disciplinas[qt_disciplinas].nome, 50, stdin); 
  size_t ln = strlen(disciplinas[qt_disciplinas].nome) - 1; 
  
  if (disciplinas[qt_disciplinas].nome[ln] == '\n'){
      disciplinas[qt_disciplinas].nome[ln] = '\0';
  }
  getchar();  
  printf("Digite o semestre da disciplina:\n");
  scanf ("%d", &disciplinas[qt_disciplinas].semestre); 
  if(disciplinas[qt_disciplinas].semestre <= 0){
    return ERRO_SEMESTRE_DISCIPLINA;
  }
  getchar();
  printf("Digite a matrícula do professor da disciplina:\n");
  scanf ("%d", &disciplinas[qt_disciplinas].n_professor);
  setbuf(stdin, 0);

  //Verificando se a matricula informada é válida e já foi cadastrada.
    for(i = 0; i <= qt_disciplinas; i++){
        for (j=0; j<=qt_professor; j++){
           if(disciplinas[i].n_professor == professores[j].matricula){
                return SUCESSO;
           }
        }
    }
return ERRO_MATRICULA;
}
  
void Listar_disciplinas(Disciplinas disciplinas[], int qt_disciplinas, Professor professor[], int qt_professor)
{
  system("clear");
  setbuf(stdin,0);
  int i,j;
  
  if (qt_disciplinas<=0){
    printf("Não existem disciplinas cadastradas no sistema.\n");
  }else{
    printf("-- Listagem de disciplinas --\n\n" );
        
    for(i=0;i<qt_disciplinas;i++){
      printf ("Codigo: %d\n", disciplinas[i].codigo);
      printf ("Nome: %s\n", disciplinas[i].nome);
      printf ("Semestre: %d\n", disciplinas[i].semestre);
      
      for(j=0;j<qt_professor;j++){
        if(disciplinas[i].n_professor == professor[j].matricula){
          printf("Professor.....:  %s\n", professor[j].nome);
                }
            }
            
        }
    }
}

int Remover_disciplinas (Disciplinas disciplinas[], int qt_disciplinas){

  int i, codigo;
  int posicao = -1;
      
  if (qt_disciplinas<0){
          return -2;
      }
      
  printf("-- Exclusão de disciplinas --");
  printf("\nInforme o código da disciplina a ser removida: ");
  scanf("%d",&codigo);

  for(i = 0;  i < qt_disciplinas; i++){
    if(codigo == disciplinas[i].codigo){
        posicao = i;
      }
    }
    if(posicao == -1){
      return 0;
    }else{
      for(i = posicao; i < qt_disciplinas; i++){
      disciplinas[i] = disciplinas[i + 1];
      }
      return SUCESSO;
  }
}

int cadastrarAluno_disciplinas(Disciplinas disciplinas[], int qt_disciplina, Aluno alunos[], int qt_alunos){
    
  int i, j, matricula, codigo, n_aluno;

  printf("-- Inserção de alunos nas disciplinas --\n\n");          printf("\nInforme a matrícula do aluno:");
  scanf("%d", &matricula);

  printf("\nInforme o código da disciplina:");
  scanf("%d", &codigo);

  for(i = 0; i < qt_disciplina; i++){
    if(codigo == disciplinas[i].codigo){
      disciplinas[i].n_aluno[disciplinas[i].qtd_alunos_disc] = matricula;
      disciplinas[i].qtd_alunos_disc++;
            return SUCESSO;
        }
    }
  }

int excluirAluno_disciplinas(Disciplinas disciplinas[], int qt_disciplina, Aluno alunos[], int qt_alunos){

    int i, j, matricula, codigo, posicao1 = -1, posicao2 = -1;

    printf("\nInforme a matricula do aluno que deseja excluir da disciplina: ");
    scanf("%d", &matricula);

    printf("\nInforme o código da disciplina: ");
    scanf("%d", &codigo);

    for(i = 0; i < qt_disciplina; i++){
        if(codigo == disciplinas[i].codigo){
            posicao1 = i;
            for(j = 0;  j < disciplinas[posicao1].qtd_alunos_disc; j++){
                if(matricula == disciplinas[posicao1].n_aluno[j]){
                    posicao2 = j;
                }
            }
         }
    }

    if(posicao1 == -1){
        return 7;
    }
    if(posicao2 == -1){
        return 2;
    }else{
        for(i = posicao2; i < disciplinas[posicao1].qtd_alunos_disc; i++){
            disciplinas[posicao1].n_aluno[i] = disciplinas[posicao1].n_aluno[i + 1];
            disciplinas[posicao1].qtd_alunos_disc--;
        }

        printf("\n");
        printf("Código .....:  %d\n", disciplinas[posicao1].codigo);
        printf("Nome .....:  %s\n", disciplinas[posicao1].nome);
        printf("Semestre .....:  %d\n", disciplinas[posicao1].semestre);
        printf("Número do professor.....:  %d\n", disciplinas[posicao1].n_professor);
        printf("Alunos na disciplina:\n");
        for(j=0; j < disciplinas[posicao1].qtd_alunos_disc; j++){
            printf("%d: %d\n", j+1, disciplinas[posicao1].n_aluno[j]);
        }
        printf("Quantidade de alunos matriculados: %d\n", disciplinas[posicao1].qtd_alunos_disc);

        return SUCESSO;
    }
}
