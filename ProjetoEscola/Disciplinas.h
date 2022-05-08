#define TAM_ALUNO_DISC 5






typedef struct Disciplinas
{
  char nome[50]; 
  int codigo; 
  int semestre;
  int n_professor;
  int n_aluno[TAM_ALUNO_DISC]; 
  int qtd_alunos_disc;

}Disciplinas;


int Cadastrar_disciplinas (Disciplinas disciplinas[], int qt_disciplinas, Professor professores[], int qt_professor);

void Listar_disciplinas(Disciplinas disciplinas[], int qt_disciplinas, Professor professor[], int qt_professor);

int Remover_disciplinas (Disciplinas disciplinas[], int qt_disciplinas);

int cadastrarAluno_disciplinas(Disciplinas disciplinas[], int qt_disciplina, Aluno alunos[], int qt_alunos);

int excluirAluno_disciplinas(Disciplinas disciplinas[], int qt_disciplina, Aluno alunos[], int qt_alunos);