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

int Cadastrar_aluno (Aluno alunos[], int qt_alunos);
int Alterar_aluno (Aluno alunos[], int qt_alunos);
void Listar_aluno (Aluno alunos[], int qt_alunos);
void Listar_aluno_sexo(Aluno alunos[], int qt_alunos);
