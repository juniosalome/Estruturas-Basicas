#ifndef TipoLista_include
#define TipoLista_include
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
//https://gilsonguimaraes.wordpress.com/2011/07/03/codigo-lista-duplamente-encadeada-circular/

typedef struct TipoItem {
  unsigned id;
}TipoItem;

typedef struct TipoCelula TipoCelula;
struct TipoCelula {
  TipoCelula* anterior;
  TipoCelula* proximo;
  TipoItem* item;
};

typedef struct TipoLista {
  unsigned tamanho;
  TipoCelula* cabeca;
  TipoCelula* cauda;
}TipoLista;


enum boolean{
    true = 1, false = 0
};
typedef enum boolean bool;

/* Prototipo: criarTipoLista()
 * Funcao: Cria uma nova lista encadeada
 * Entrada: void
 * Retorno: a lista  encadeada
 * */
TipoLista *criarTipoLista();

/* Prototipo: inserirInicio(int valor, TipoLista *l)
 * Funcao: Insere um nó no começo da lista
 * Entrada: l - lista circular duplamente encadeada
 *          valor - valor que sera inserido na lista
 * Retorno: void
 * */
void inserirInicio(int valor, TipoLista *l);

/* Prototipo: inserirFinal(int valor, TipoLista *l)
 * Funcao: Insere um nó no final da lista
 * Entrada: l - lista circular duplamente encadeada
 * 			valor - valor que sera inserido na lista
 * Retorno: void
 * */
void inserirFinal(int valor, TipoLista *l);

/* Prototipo: inserirPosicao(int valor, int posicao, TipoLista *l)
 * Funcao: Insere um nó em determinada posicao da lista
 * Entrada: l - lista circular duplamente encadeada
 * 			valor - valor que sera inserido na lista
 * 			posicao - posicao para inserir na lista
 * Retorno: void
 * */
void inserirPosicao(int valor, int posicao, TipoLista *l);

/* Prototipo: removerPrimeiro(TipoLista *l)
 * Funcao: Remove o primeiro nó da lista
 * Entrada: l - lista circular duplamente encadeada
 * Retorno: void
 * */
void removerPrimeiro(TipoLista *l);

/* Prototipo: removerUltimo(TipoLista *l)
 * Funcao: Remove o ultimo nó da Lista
 * Entrada: l - lista circular duplamente encadeada
 * Retorno: void
 * */
void removerUltimo(TipoLista *l);

/* Prototipo: removerValor(int valor, TipoLista *l)
 * Funcao: Remove os nós que contém determinado valor da lista
 * Entrada: l - lista circular duplamente encadeada
 * 			valor - valor que sera removido na lista
 * Retorno: void
 * */
void removerValor(int valor, TipoLista *l);

/* Prototipo: removerPosicao(int posicao, TipoLista *l)
 * Funcao: Remove o nó de determinada posição da lista
 * Entrada: l - lista circular duplamente encadeada
 * 			posicao - posicao que sera removido na lista
 * Retorno: void
 * */
void removerPosicao(int posicao, TipoLista *l);

/* Prototipo: imprimirLista(TipoLista *l)
 * Funcao: Imprime todos os valores dos nós da lista
 * Entrada: l - lista circular duplamente encadeada
 * Retorno: void
 * */
void imprimirLista(TipoLista *l);

/* Prototipo: deletarLista(TipoLista **l)
 * Funcao: Remove todos os nós da lista e depois a deleta
 * Entrada: l - lista circular duplamente encadeada
 * Retorno: void
 * */
void deletarLista(TipoLista **l);

/* Prototipo: multiplos(int valor, TipoLista *l)
 * Funcao: Retorna quantos nós da lista são multiplos de determinado valor
 * Entrada: l - lista circular duplamente encadeada
 * Retorno:
 * */
int multiplos(int valor, TipoLista *l);

/* Prototipo: estaOrdenada(TipoLista *l)
 * Funcao: Verifica se a lista esta ordenada
 * Entrada: l - lista circular duplamente encadeada
 * Retorno: true - se a lista estiver crescentemente ordenada
 * 			false - caso contrário
 * */
bool estaOrdenada(TipoLista *l);

#endif
