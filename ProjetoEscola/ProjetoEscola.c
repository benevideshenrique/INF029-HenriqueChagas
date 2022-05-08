#include <stdio.h>
#include <stdlib.h>
#define TAM 5
#include "Aluno.h"
#include "Professor.h"
#include "Disciplinas.h"


int menu_principal ();
int menu_cadastro ();
int menu_exclusao ();
int menu_alteracao ();
int menu_relatorio ();

  int main(){
    Aluno alunos[TAM];
    Professor professor[TAM];
    Disciplinas disciplinas[TAM], n_aluno, n_professor;
    int inteiro;
    int op_principal=0, op_cadastro=0,op_exclusao=0,op_alteracao=0, op_relatorio=0,sair=0, retorno_func=0, qt_alunos = 0, qt_professor = 0, qt_disciplinas=0, i=0;
    
    
    while(!sair){
      if(qt_alunos == -1){
            qt_alunos = 0;
        }
        if (qt_professor == -1){
            qt_professor = 0;
        }
        if (qt_disciplinas == -1){
            qt_disciplinas = 0;
        }
      
      op_principal = menu_principal();
      switch(op_principal){
        //caso a opção no menu principal tenha sido sair
        case 0:
          printf("Encerrando o programa...\n");
          sair = 1;
          break;
        //Caso a opção no menu principal tenha sido cadastrar aluno
        case 1:
            op_cadastro = menu_cadastro();
            switch(op_cadastro){
              case 0:
                printf("Encerrando o programa...\n");
                sair = 1;
                break;
              case 1:
              retorno_func = Cadastrar_aluno(alunos, qt_alunos);
              if (retorno_func == -1){
                printf("Cadastro realizado com sucesso.\n");
                qt_alunos++;
                getchar();
              }else if (retorno_func == -2){
                printf("Cadastro não realizado. A matrícula inserida não é válida.\n");
                getchar();
              }else if (retorno_func == -3){
                printf("Cadastro não realizado. O nome inserido não é válido.\n");
                getchar();
              }else if (retorno_func == -4){
                printf("Cadastro não realizado. O sexo inserido não é valido.\n");
                getchar();
              }else if (retorno_func == -5){
                printf("Cadastro não realizado. A data inserida não é válida.\n");
                getchar();
              }else if (retorno_func == -6){
                printf("Cadastro não realizado. O CPF não é válido\n");
                getchar();
              }
              break;

    //Caso a opção no menu principal tenha sido cadastrar professor          
            case 2:
            retorno_func = Cadastrar_professor(professor, qt_professor);
              if (retorno_func == -1){
                printf("Cadastro realizado com sucesso.\n");
                qt_professor++;
              }else if (retorno_func == -2){
                printf("Cadastro não realizado. A matrícula inserida não é válida.");
                getchar();
              }else if (retorno_func == -3){
                printf("Cadastro não realizado. O nome inserido não é válido.");
                getchar();
              }else if (retorno_func == -4){
                printf("Cadastro não realizado. O sexo inserido não é valido.");
                getchar();
              }else if (retorno_func == -5){
                printf("Cadastro não realizado. A data inserida não é válida.");
                getchar();
              }else if (retorno_func == -6){
                printf("Cadastro não realizado. O CPF não é válido");
                getchar();
              }
              break;

              //Caso a opção no menu principal tenha sido cadastrar disciplina
            case 3:
              retorno_func = Cadastrar_disciplinas(disciplinas, qt_disciplinas, professor, qt_professor);
              if (retorno_func == -1){
                printf("Cadastro realizado com sucesso.\n");
                qt_professor++;
                getchar();
              }else if (retorno_func == -2){
                printf("Cadastro não realizado. A matrícula inserida não é válida.");
                getchar();
              }else if (retorno_func == -7){
                printf("Cadastro não realizado. O Código da disciplina não é válido.");
                getchar();
              }else if (retorno_func == -8){
                printf("Cadastro não realizado. O Semestre inserido para a disciplina não é válido");
                getchar();
              }
              break;
            default:
            printf("Opção inválida");
            getchar();
            break;
            }
        break;
        case 2:
          op_exclusao = menu_exclusao();
            switch (op_exclusao){
              case 0:
                printf("Encerrando o programa...\n");
                sair = 1;
              break;
              case 1:
                printf("b");//exclusão aluno
              break;
              case 2:
                printf("c");//exclusão professor
              break;
              case 3:
               retorno_func = Remover_disciplinas (disciplinas, qt_disciplinas);
                if (retorno_func == -1){
                printf("Exclusão realizada com sucesso.\n");
                getchar();
              }else if (retorno_func == -2){
                printf("Cadastro não realizado. O código inserido não é válido.");
                getchar();
              }
              break;
              }
        case 3:
          op_alteracao = menu_alteracao();
            switch (op_alteracao){
              case 0:
                printf("Encerrando o programa...\n");
                sair = 1;
              break;
              case 1:
                retorno_func = Alterar_aluno(alunos, qt_alunos);
              if (retorno_func == -1){
                printf("Cadastro alterado com sucesso.\n");
                qt_alunos++;
                getchar();
              }else if (retorno_func == -2){
                printf("Cadastro não realizado. A matrícula modificada não é válida.\n");
                getchar();
              }else if (retorno_func == -3){
                printf("Cadastro não realizado. O nome modificado não é válido.\n");
                getchar();
              }else if (retorno_func == -4){
                printf("Cadastro não realizado. O sexo modificado não é valido.\n");
                getchar();
              }else if (retorno_func == -5){
                printf("Cadastro não realizado. A data modificada não é válida.\n");
                getchar();
              }else if (retorno_func == -6){
                printf("Cadastro não realizado. O CPF modificado não é válido\n");
                getchar();
              }
              break;
              case 2:
                printf("g");//alteração professor
                break;
              case 3: 
                printf("h");//alteração disciplina
                break;
            }
        break;
        case 4:
          retorno_func = cadastrarAluno_disciplinas(disciplinas, qt_disciplinas, alunos, qt_alunos);
          if (retorno_func == -1){
                printf("Cadastro realizado com sucesso.\n");
                getchar();
              }
 //         else if (retorno_func == -7){
 //               printf("Cadastro não realizado. O código inserido não é válido.");
                getchar();
        break;
        case 5:
         retorno_func = excluirAluno_disciplinas(disciplinas, qt_disciplinas, alunos, qt_alunos);
          if (retorno_func == -1){
                printf("Exclusão realizada com sucesso.\n");
                getchar();
              }
          else if (retorno_func == -7){
                printf("Cadastro não realizado. O código inserido não é válido.");
                getchar();
              }
          else if (retorno_func == -2){
                printf("Cadastro não realizado. A matrícula inserida não é válida.");
                getchar();
              }
          break;
        case 6:
          op_relatorio = menu_relatorio();
          switch(op_relatorio){
            case 0:
              printf("Encerrando o programa...\n");
              sair = 1;
            break;
            case 1:
              Listar_aluno (alunos, qt_alunos);
              getchar();
            break;
            case 2:
            printf("a");
            break;
            case 3:
            Listar_disciplinas(disciplinas, qt_disciplinas, professor ,qt_professor);
            getchar();
            break;
            case 4:
            printf("a");
            break;
            case 5:
              Listar_aluno_sexo(alunos, qt_alunos);
              fflush(stdin);
              getchar();
            break ;
            case 6:
            printf("a");
            break;
            case 7:
            printf("a");
            break;
            case 8:
            printf("a");
            break;
            case 9:
            printf("a");
            break;
            case 10:
            printf("a");
            break;
            case 11:
            printf("a");
            break;
            case 12:
            printf("a");
            break;
            case 13:
            printf("a");
            break;
            case 14:
            printf("a");
            break;
          }
          break;
     }
    }
    return 0;
  }




    
//Área das funcões menus:  
int menu_principal (){
  system ("clear");
  int opcao;
  printf("Favor inserir a opção desejada:\n");
  printf("Digite 1 para cadastros;\n");
  printf("Digite 2 para exclusões;\n");
  printf("Digite 3 para alteração;\n");
  printf("Digite 4 para inserção de aluno em uma disciplina;\n");
  printf("Digite 5 para exclusão de aluno em uma disciplina;\n");
  printf("Digite 6 para relatórios;\n");
  printf("Digite 0 para sair;\n");
  scanf("%d",&opcao);
  return opcao;
}
  
int menu_cadastro (){
  system ("clear");
  int opcao=0;
  printf("Digite 1 para cadastro de aluno;\n");
  printf("Digite 2 para cadastro de professor;\n");
  printf("Digite 3 para cadastro de disciplina;\n");
  printf("Digite 0 para sair;\n");
  scanf("%d",&opcao);
  return opcao;
}
  
int menu_exclusao (){
  system ("clear");
  int opcao=0;
  printf("Digite 1 para exclusão de aluno;\n");
  printf("Digite 2 para exclusão de professor;\n");
  printf("Digite 3 para exclusão de disciplina;\n");
  printf("Digite 0 para sair;\n");
  scanf("%d",&opcao);
  return opcao;
}
  
int menu_alteracao (){
  system ("clear");
  int opcao=0;
  printf("Digite 1 para alteração de aluno;\n");
  printf("Digite 2 para alteração de professor;\n");
  printf("Digite 3 para alteração de disciplina;\n");
  printf("Digite 0 para sair;\n");
  scanf("%d",&opcao);
  return opcao;
}
  
int menu_relatorio (){
  system ("clear");
  int opcao=0;
  printf("Digite 1 para listar alunos;\n");
  printf("Digite 2 para listar professores;\n");
  printf("Digite 3 para listar disciplinas (dados da disciplina sem alunos matriculados);\n");
  printf("Digite 4 para listar disciplinas (dados da disciplina e os alunos matriculados;\n");
  printf("Digite 5 para listar alunos por sexo;\n");
  printf("Digite 6 para listar alunos ordenados por nome;\n");
  printf("Digite 7 para listar alunos por nascimento;\n");
  printf("Digite 8 para listar professores por sexo;\n");
  printf("Digite 9 para listar professores por nome;\n");
  printf("Digite 10 para listar professores por nascimento;\n");
  printf("Digite 11 para listar aniversariantes do mês;\n");
  printf("Digite 12 para listar professores ou alunos a partir de uma busca específica;\n");
  printf("Digite 13 para listar alunos matriculados em ao menos três disciplinas, digite 13;\n");
  printf("Digite 14 para listar disciplinas que extrapolam 40 vagas, com nome dos professores;\n");
  printf("Digite 0 para sair;\n");
  scanf("%d",&opcao);
  return opcao;
}
