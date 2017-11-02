#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct celula *apontador;
typedef int Chave;

typedef struct {
    //Chave chave;
    int qtd;
    char nome[20];
    int linha[50];
} tipoItem;

struct celula {
    tipoItem item;
    apontador prox, anterior;
} celula;

typedef struct {
    int tamanho;
    apontador primeiro, ultimo;
} tipoLista;


/*-----------------------------------------------------------------------------
 * Prototipo: inicializa(tipoLista*)
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
void inicializa(tipoLista*);

/*-----------------------------------------------------------------------------
 * Prototipo: vazia(tipoLista)
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
int vazia(tipoLista);

/*-----------------------------------------------------------------------------
 * Prototipo: insere(apontador, tipoItem, tipoLista*)
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
void insere(apontador, tipoItem, tipoLista*);

/*-----------------------------------------------------------------------------
 * Prototipo: buscaLocalin(tipoItem, tipoLista*)
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
apontador buscaLocalin(tipoItem, tipoLista*);

/*-----------------------------------------------------------------------------
 * Prototipo: retira(apontador, tipoItem*, tipoLista*)
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
void retira(apontador, tipoItem*, tipoLista*);

/*-----------------------------------------------------------------------------
 * Prototipo: buscaLocalre(tipoItem, tipoLista*)
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
apontador buscaLocalre(tipoItem, tipoLista*);

/*-----------------------------------------------------------------------------
 * Prototipo: imprimeLista(tipoLista*)
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
void imprimeLista(tipoLista*);

/*-----------------------------------------------------------------------------
 * Prototipo: imprimePosicao(int, int, tipoLista*)
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
int imprimePosicao(int, int, tipoLista*);

/*-----------------------------------------------------------------------------
 * Prototipo: ConferePalavraIgual(char* nome, tipoLista *lista, int lin)
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
int ConferePalavraIgual(char* nome, tipoLista *lista, int lin);

#endif // LISTA_H
