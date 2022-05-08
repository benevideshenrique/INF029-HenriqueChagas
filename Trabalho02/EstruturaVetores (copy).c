#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#include "EstruturaVetores.h"





/*  TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11
    NOVO_TAMANHO_INVALIDO = -10
    NUMERO_INEXISTENTE = -9
    ESTRUTURA_AUXILIAR_VAZIA  = -8
    TAMANHO_INVALIDO  = -7
    SEM_ESPACO_DE_MEMORIA  = -6
    POSICAO_INVALIDA  = -5
    JA_TEM_ESTRUTURA_AUXILIAR  = -4
    SEM_ESTRUTURA_AUXILIAR  = -3
    SEM_ESPACO  = -2
    SUCESSO  	= -1*/

int vetorPrincipal[TAM];

int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    int retorno = 0;
    // a posicao pode já existir estrutura auxiliar
    retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    if (Posicao_Valida != SUCESSO){
      return POSICAO_INVALIDA
    }
    // o tamanho ser muito grande
    retorno = SEM_ESPACO_DE_MEMORIA;
    // o tamanho nao pode ser menor que 1
    retorno = TAMANHO_INVALIDO;
    // deu tudo certo, crie
    retorno = SUCESSO;

    return retorno;
}

int inserirNumeroEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    if (posicao_invalida)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (existeEstruturaAuxiliar)
        {
            if (temEspaco)
            {
                //insere
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = SUCESSO;
    return retorno;
}

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = SUCESSO;
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;

    return retorno;
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;

    
    return retorno;
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;
    return retorno;
}

int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;

    return retorno;
}

No *montarListaEncadeadaComCabecote()
{

    return NULL;
}
 getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

void destruirListaEncadeadaComCabecote(No **inicio)
{
}

void inicializar()
{
}


void finalizar()
{
}

//FUNÇÕES AUXILIARES

int Posicao_Valida(posicao){
  if (posicao >= 1 && posicao <= TAM){
    return SUCESSO;
  }else {
    return POSICAO_INVALIDA;
  }
}