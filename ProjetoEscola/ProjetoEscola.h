#define TAM 5
#define SUCESSO -1
#define ERRO_MATRICULA -2
#define ERRO_NOME -3
#define ERRO_SEXO -4
#define ERRO_NASCIMENTO -5
#define ERRO_CPF -6
#define TAM_ALUNO_DISC 5


typedef struct Data
{
    int dia, mes, ano;
}Data;

typedef struct Aluno
{
int matricula;
char nome[50];
char sexo;
Data data_nasc;
char cpf[16];
}Aluno;

typedef struct Professor
{
    int matricula;
    char nome[50];
    char sexo; 
    Data data_nasc;
    char cpf[16];
}Professor;

typedef struct Disciplinas
{
  char nome[50]; 
  int codigo; 
  int semestre;
  int n_professor;
  int n_aluno[TAM_ALUNO_DISC]; 
  int qtd_alunos_disc;

}Disciplinas;