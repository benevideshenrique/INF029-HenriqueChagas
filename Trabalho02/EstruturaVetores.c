
#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#include "EstruturaVetores.h"

Principal vetorPrincipal[TAM];

void inicializar() {
  int i;
  for (i = 0; i < TAM; i++) {
    vetorPrincipal[i].pont = NULL;
    vetorPrincipal[i].qtd = 0;
    vetorPrincipal[i].tam = 0;
  }
}

int criarEstruturaAuxiliar(int posicao, int tamanho) {
  if (vetorPrincipal[posicao].pont != NULL) {
    return JA_TEM_ESTRUTURA_AUXILIAR;
  }
  else if (posicao > 10 || posicao < 1) {
    return POSICAO_INVALIDA;
  } else if (tamanho < 1) {
    return TAMANHO_INVALIDO;
  } else {
    vetorPrincipal[posicao].pont = (int *)malloc(tamanho * sizeof(int));
    vetorPrincipal[posicao].tam = tamanho;
    vetorPrincipal[posicao].qtd = 0;
    return SUCESSO;
  }
}

int inserirNumeroEmEstrutura(int posicao, int valor) {
  int i, j, retorno = 0;
  if (posicao > 10 || posicao < 1) {
    retorno = POSICAO_INVALIDA;
  } else {
    if (vetorPrincipal[posicao].pont != NULL) {
      if (vetorPrincipal[posicao].qtd < vetorPrincipal[posicao].tam)
            {
              vetorPrincipal[posicao].pont[vetorPrincipal[posicao].qtd] = valor;
              vetorPrincipal[posicao].qtd ++;    
              retorno = SUCESSO;
            }
    } else {
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
  }
  return retorno;
}

int excluirNumeroDoFinaldaEstrutura(int posicao) {
  int retorno;
  if (posicao > 10 || posicao < 1)
    retorno = POSICAO_INVALIDA;
  else {
    if (vetorPrincipal[posicao].pont != NULL) {
      if (vetorPrincipal[posicao].qtd > 0) {
        vetorPrincipal[posicao].qtd--;
        retorno = SUCESSO;
      } else
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    } else
      retorno = SEM_ESTRUTURA_AUXILIAR;
  }
  return retorno;
}

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
    int i, retorno, achei;
    if (posicao > 10 || posicao < 1)
      retorno = POSICAO_INVALIDA;
    else {
      if (vetorPrincipal[posicao].pont != NULL) {
        if (vetorPrincipal[posicao].qtd > 0) {
          for (i = 0, achei = 0; i < vetorPrincipal[posicao].qtd && achei == 0;i++){
            if (valor == vetorPrincipal[posicao].pont[i])
              achei = 1;
          }
          if (achei == 1) {
            for (i = i - 1; i < vetorPrincipal[posicao].qtd;i++){
              vetorPrincipal[posicao].pont[i] =
                  vetorPrincipal[posicao].pont[i + 1];
            }
            vetorPrincipal[posicao].qtd--;
            retorno = SUCESSO;
          } else
            retorno = NUMERO_INEXISTENTE;
        } else {
          retorno = ESTRUTURA_AUXILIAR_VAZIA;
        }
      } else {
        retorno = SEM_ESTRUTURA_AUXILIAR;
      }
    }
    return retorno;
  }

  int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    int i, retorno;
    if (posicao > 10 || posicao < 1)
      retorno = POSICAO_INVALIDA;
    else {
      if (vetorPrincipal[posicao].pont != NULL) {
        if (vetorPrincipal[posicao].qtd > 0) {
          for (i = 0; i < vetorPrincipal[posicao].qtd; i++) {
            vetorAux[i] = vetorPrincipal[posicao].pont[i];
          }
          retorno = SUCESSO;
        }
      } else {
        retorno = SEM_ESTRUTURA_AUXILIAR;
      }
    }
    return retorno;
  }

  int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    int i, j, retorno, auxiliar;
    if (posicao > 10 || posicao < 1)
      retorno = POSICAO_INVALIDA;
    else {
      if (vetorPrincipal[posicao].pont != NULL) {
        if (vetorPrincipal[posicao].qtd > 0) {
          for (i = 0; i < vetorPrincipal[posicao].qtd; i++)
            vetorAux[i] = vetorPrincipal[posicao].pont[i];
          for (i = 0; i < vetorPrincipal[posicao].qtd; i++) {
            for (j = i + 1; j < vetorPrincipal[posicao].qtd;
                 j++) {
              if (vetorAux[i] > vetorAux[j]) {
                auxiliar = vetorAux[i];
                vetorAux[i] = vetorAux[j];
                vetorAux[j] = auxiliar;
              }
            }
          }
          retorno = SUCESSO;
        }
      } else {
        retorno = SEM_ESTRUTURA_AUXILIAR;
      }
    }

    return retorno;
  }

  int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int i, contador = 0;
    int j, retorno;
    for (i = 0; i < TAM; i++) {
      if (vetorPrincipal[i].pont != NULL) {
        if (vetorPrincipal[i].qtd > 0) {
          for (j = 0; j < vetorPrincipal[i].qtd; j++) {
            vetorAux[contador] = vetorPrincipal[i].pont[j];
            contador++;
          }
        }
      }
    }

    if (contador > 0)
      retorno = SUCESSO;
    else
      retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    return retorno;
  }

  int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {

    int i, auxiliar, contador = 0;
    int j, retorno = 0;

    for (i = 0; i < TAM; i++) {

      if (vetorPrincipal[i].pont != NULL) {

        if (vetorPrincipal[i].qtd > 0) {
          for (j = 0; j < vetorPrincipal[i].qtd; j++) {
            vetorAux[contador] = vetorPrincipal[i].pont[j];
            contador++;
          }
        }
      }
    }

    if (contador > 0) {
      for (i = 0; i < contador; i++) {
        for (j = i + 1; j < contador; j++) {
          if (vetorAux[i] > vetorAux[j]) {
            auxiliar = vetorAux[i];
            vetorAux[i] = vetorAux[j];
            vetorAux[j] = auxiliar;
          }
        }
      }
    }

    if (contador > 0)
      retorno = SUCESSO;
    else
      retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    return retorno;
  }

 int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
    int retorno = 0;
    novoTamanho = novoTamanho + vetorPrincipal[posicao].tam;
    if (posicao > 10 || posicao < 1)
      retorno = POSICAO_INVALIDA;
    else {
      if (novoTamanho < 1) {
        retorno = NOVO_TAMANHO_INVALIDO;
        return retorno;
      }
      if (vetorPrincipal[posicao].pont != NULL) {
        vetorPrincipal[posicao].pont = realloc(
            vetorPrincipal[posicao].pont, (novoTamanho * sizeof(int)));
        if (!vetorPrincipal[posicao].pont)
          retorno = SEM_ESPACO_DE_MEMORIA;
        else {
          vetorPrincipal[posicao].tam = novoTamanho;
          if (vetorPrincipal[posicao].tam < vetorPrincipal[posicao].qtd)
            vetorPrincipal[posicao].qtd = vetorPrincipal[posicao].tam;
          retorno = SUCESSO;
        }
      } else
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }

    return retorno;
  }


  int getQuantidadeElementosEstruturaAuxiliar(int posicao) {
    int retorno = 0;
    if (posicao > 10 || posicao < 1)
      retorno = POSICAO_INVALIDA;
    else {
      if (vetorPrincipal[posicao].pont != NULL) {
        if (vetorPrincipal[posicao].qtd > 0) {
          if (vetorPrincipal[posicao].tam < vetorPrincipal[posicao].qtd)
            vetorPrincipal[posicao].qtd = vetorPrincipal[posicao].tam;
          retorno = vetorPrincipal[posicao].qtd;
        } else
          retorno = ESTRUTURA_AUXILIAR_VAZIA;
      } else
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    return retorno;
  }

void inserirNoFinal(No *inicio, int val){
  //cria-se um ponteiro do tipo No que será responsável por implementar os dados no final da lista
		No* novo = (No*)malloc(sizeof(No));
  //atribui-se a ele o valor informado pelo usuário/teste
  	novo->conteudo = val;
  //o ponteiro da estrutura apontará para NULL por ser o último elemento da lista
  	novo->prox = NULL;
  //verifica-se se inicio está apontando para nulo (provavelmente sim,porém pode ter acontecido manipulação da estrutura)
  	  if(inicio->prox == NULL){
  //caso esteja apontando para NULL, significa que ele é o fim da lista, assim, devemos fazer inicio apontar para o novo fim, que é novo
  		inicio->prox = novo;
  	}else{
  //caso a lista não esteja vazia, deve-se atribuir o valor de novo 
		while(inicio->prox != NULL)
			inicio = inicio->prox;
		  inicio->prox = novo;
	}
}

No *montarListaEncadeadaComCabecote()
{
  int i, j, retorno=0, aux=0;
    //criando cabeçote
  No *cabecote = (No*) malloc(sizeof(No));  
  //varrendo principal em busca de estrutura auxiliar
  for (i = 0; i < TAM; i++){
    //verificando se a lista está vazia
    if (vetorPrincipal[i].pont != NULL){ 
      //caso a lista não esteja vazia verifica-se no vetor principal a quantidade de elementos 
      if (vetorPrincipal[i].qtd > 0){
        aux++;
       //varre-se a estrutura chamando a função de inserir no final para acrescentar o elemento
        for (j = 0; j < vetorPrincipal[i].qtd; j++)
        {
          inserirNoFinal(cabecote, vetorPrincipal[i].pont[j]); 
        }
      }
    }
  }
  //caso tenha sido acrescentado algum elemento, retorna o cabeçote, caso contrário, retorna NULL indicando que nada foi feito
  if (aux > 0)
    return cabecote;
  else
    return NULL;
}

void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
  {
    //para achar os dados da lista encadeada é necessário fazer uma leitura da estrutura. Para isso, se cria um vetor auxiliar que irá armazenar os valores dos próximos elementos até a chegada no final da lista, quando o ponteiro irá apontar para NULL
  No *leitor;
  int i = 0;
  for (leitor = inicio->prox; leitor != NULL; leitor = leitor->prox){
    //o vetor auxiliar irá receber os dados. Cada vez que essa operação seja realizada, incrementa-se o contador i, de modo que o vetor auxiliar seja percorrido
    vetorAux[i] = leitor->conteudo;
    i++;
    }
}

void destruirListaEncadeadaComCabecote(No **inicio)
{
  No* atual = *inicio;
	No* tmp;

	while(atual != NULL){
		tmp = atual->prox;
		free(atual);
		atual = tmp;
	}

  *inicio = NULL;
}

void finalizar()
{
  int i;
  for (i = 0; i < TAM; i++){
    if (vetorPrincipal[i].pont != NULL)
        free (vetorPrincipal[i].pont);
    }
}