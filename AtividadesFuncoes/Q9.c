#include <stdio.h>
#include <string.h>

typedef struct nascimento{
	
	int dia;
	int mes;
	int ano;

}nascimento;

typedef struct cad_cliente{
    
	char nome [20];
	char cpf [20];
	char sexo;
	nascimento dataNascimento;
  int id;
  int nomevalidado;
  int cpfvalidado;
  int sexovalidado;
  int nascimentovalidado;

}cad_cliente;

cad_cliente cadastrarCliente ();
int validarNome(char string[]);
int validarSexo(char c);
int validarCPF();
int validarNascimento();
int ehBissexto(int anoBissexto);

int main() {	
	
	cad_cliente cadastro;
	cadastro = cadastrarCliente ();


  if (cadastro.id <= 0){ 
        
        if (cadastro.id == -1){
            printf("ERRO no cadastro do nome");    
        }else if (cadastro.id == -2){
            printf("ERRO no cadastro do cpf");    
        }

      }else{
        printf("\n\n*************************************\n\n");
        printf("Cliente cadastrado com sucesso:\n");
        printf("Nome: %s",cadastro.nome);
        printf("Gênero: %c\n",cadastro.sexo);
        printf("CPF: %s",cadastro.cpf);
        printf("Nascimento: %d/%d/%d",       cadastro.dataNascimento.dia,cadastro.dataNascimento.mes,cadastro.dataNascimento.ano);
    }
  }
cad_cliente cadastrarCliente (){

	cad_cliente inserirDados;
  inserirDados.id = -1;
  
    printf("Insira o nome do cliente:\n");
    fgets(inserirDados.nome, 50, stdin);
  
    int erro = validarNome(inserirDados.nome);
    
    if (erro == 1){
          inserirDados.id = -1;
          return inserirDados;
      }else{
          printf("Insira o CPF do cliente, de forma completa com pontos e hífen: \n");
          fgets(inserirDados.cpf, 20, stdin);
        
          erro = validarCPF(inserirDados.cpf);
            if (erro == 1){
            inserirDados.id = -2;
            return inserirDados;
            }else{
            printf("Insira o sexo do cliente. Utilize M para masculino, F para feminino e O para outro\n");
            scanf ("%c", &inserirDados.sexo);

          inserirDados.sexovalidado=validarSexo(inserirDados.sexo);
            
            printf("Insira o dia de nascimento do cliente:\n");
            scanf("%d",&inserirDados.dataNascimento.dia);
            
            printf("Insira o mês de nascimento do cliente:\n");
            scanf("%d",&inserirDados.dataNascimento.mes);
            
            printf("Insira o ano de nascimento do cliente:\n");
            scanf("%d",&inserirDados.dataNascimento.ano);    
        }

         
    }
    inserirDados.id = 1;
    return inserirDados;
   
}
  
  int validarNome(char string[]){
    
    int numerocaracteres = 0;
    int erro = 0;
    while(string[numerocaracteres] != '\0'){
        numerocaracteres++;
    }
    if(numerocaracteres > 20){
        erro = 1;
    }

    return erro;
}

int validarSexo(char c){
    
    int sexovalidado=0;
    
    if(c == 'f' || c == 'F' || c == 'm' || c == 'M' || c == 'o' || c == 'O'){
        return 1;
    }
    else{
        return 0;
    }
}

int validarCPF(char string[]){
   
    int numeroscpf = 0;
    
    while(string[numeroscpf] != '\0'){
        numeroscpf++;
    }
    if(numeroscpf > 11){
        numeroscpf = 0;
    }
    else{
        numeroscpf = 1;
    }
    return numeroscpf;
}

int validarNascimento(nascimento data){
    
    if (data.dia < 1 || data.dia > 31)
        return 0;
    if (data.mes < 1 || data.mes > 12)
        return 0;
    if (data.ano > 2021)
        return 0;

    // meses de 30 dias
    if ((data.mes == 4 ||
        data.mes == 6 ||
        data.mes == 9 ||
        data.mes == 11) && data.dia > 30){

        return 0;
    } if (data.mes == 2){
        if (ehBissexto(data.ano) && data.dia > 29){
            return 0;
        }else if (data.dia > 28){
            return 0;
        }

    }

    return 1;
  }

int ehBissexto(int anoBissexto){

  nascimento data;
  
    if (data.dia == 29 && (data.ano % 400 == 0 || (data.ano % 4 == 0 && data.ano % 100 != 0)))
        return 1;
      else
        return 0;
}