
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
          // for para fazer o vetor auxiliar assumir os valores
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
          // for para fazer o vetor auxiliar assumir os valores
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


No* criarElemento(int valor){
	No *novo = (No *)malloc(sizeof(No));
	if(novo == NULL){
        printf("Falta Memoria\n");
        exit(1);
	}
	novo->conteudo = valor;
	novo->prox = NULL;
	return novo;
}


void inserirNoFinalComCabecote(No *inicio, int val){

}

No *montarListaEncadeadaComCabecote()
{
}

void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
  {
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