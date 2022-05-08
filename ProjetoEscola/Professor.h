/*typedef struct Data
{
    int dia, mes, ano;
}Data;*/

typedef struct Professor{
  int matricula;
  char nome[50];
  char sexo; 
  Data data_nasc;
  char cpf[16];
}Professor;

int Cadastrar_professor(Professor professor[], int qt_professor);
