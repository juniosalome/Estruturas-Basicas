#ifndef HASH_H
#define HASH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

// hash de tratamento de colis�o por endere�amento aberto

//definicao da estrutura que guarda o cadastro das palavras

typedef struct pal {
    tipoItem palavra;
    struct pal *prox;
} hPalavra;

//definicao da estrutura que representa uma posicao na tabela hash

typedef struct {
    int tam;
    hPalavra *cadPalavra;
} Thash;


/*-----------------------------------------------------------------------------
 * Prototipo: criaHash(int max, Thash **hash)
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
void criaHash(int max, Thash **hash);

/*-----------------------------------------------------------------------------
 * Prototipo: funcaoEspalhamento(int pos, int max)
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
int funcaoEspalhamento(int pos, int max);

/*-----------------------------------------------------------------------------
 * Prototipo: inserehPalavra(Thash **hash, tipoItem palavra, int max, int pos)
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
void inserehPalavra(Thash **hash, tipoItem palavra, int max, int pos);

/*-----------------------------------------------------------------------------
 * Prototipo: buscaPalavra(Thash *hash, char* palavra, int max)
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
hPalavra* buscaPalavra(Thash *hash, char* palavra, int max);

/*-----------------------------------------------------------------------------
 * Prototipo: imprimePalavrah(Thash *hash, hPalavra *a)
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
void imprimePalavrah(Thash *hash, hPalavra *a);

/*-----------------------------------------------------------------------------
 * Prototipo: imprimeHash(Thash *hash, int max)
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
void imprimeHash(Thash *hash, int max);

/*-----------------------------------------------------------------------------
 * Prototipo: liberaHash(Thash *hash, int max)
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
void liberaHash(Thash *hash, int max);

#endif // HASH_H
