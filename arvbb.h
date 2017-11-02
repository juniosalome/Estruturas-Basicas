#ifndef ARVBB_H
#define ARVBB_H
#include <stdio.h>
#include <string.h>
#include "Lista.h"

typedef struct arv {
    tipoItem palavra;
    struct arv* esq;
    struct arv* dir;
} Arv;

/*-----------------------------------------------------------------------------
 * Prototipo: FPVazia()
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
Arv* arvore_cria(void);

/*-----------------------------------------------------------------------------
 * Prototipo: FPVazia()
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
Arv* arvore_insere(Arv*, tipoItem);

/*-----------------------------------------------------------------------------
 * Prototipo: FPVazia()
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
void arvore_imprimePreEsq(Arv*);

/*-----------------------------------------------------------------------------
 * Prototipo: FPVazia()
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
void arvore_imprimePreDir(Arv*);

/*-----------------------------------------------------------------------------
 * Prototipo: FPVazia()
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
void arvore_imprimeCentEsq(Arv*);

/*-----------------------------------------------------------------------------
 * Prototipo: FPVazia()
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
void arvore_imprimeCentDir(Arv*);

/*-----------------------------------------------------------------------------
 * Prototipo: FPVazia()
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
void arvore_imprimePosEsq(Arv*);

/*-----------------------------------------------------------------------------
 * Prototipo: FPVazia()
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
void arvore_imprimePosDir(Arv*);

/*-----------------------------------------------------------------------------
 * Prototipo: FPVazia()
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
int arvore_busca(Arv*, tipoItem);

/*-----------------------------------------------------------------------------
 * Prototipo: FPVazia()
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
int buscabb(Arv* r, char *nome);

#endif // ARVBB_H
