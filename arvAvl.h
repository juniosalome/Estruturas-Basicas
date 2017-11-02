#ifndef ARVAVL_H
#define ARVAVL_H
#include <stdio.h>
#include <string.h>
#include "Lista.h"

typedef struct nodo {
    tipoItem palavra;
    int fatbal;
    struct nodo *esq, *dir;
} arvoreAVL;

/*-----------------------------------------------------------------------------
 * Prototipo: LeArv(arvoreAVL **eainicio)
 * Função: Le a arvore criada
 * Entrada: ponteiro indicando a arvore
 * Saida: Não tem retorno.
 *----------------------------------------------------------------------------*/
void LeArv(arvoreAVL **eainicio);

/*-----------------------------------------------------------------------------
 * Prototipo: InicializaAVL(arvoreAVL **eainicio)
 * Função: Ira armazenar espaco na memoria para  a arvore
 * Entrada: ponteiro indicando a arvore
 * Saida: Não tem retorno.
 *----------------------------------------------------------------------------*/
void InicializaAVL(arvoreAVL **eainicio);

/*-----------------------------------------------------------------------------
 * Prototipo: InsereAVL(arvoreAVL *adesc, tipoItem dadonovo)
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: ponteiro indicando a arvore e o novo elemento a ser inserido 
 * Saida: Não tem retorno.
 *----------------------------------------------------------------------------*/
void InsereAVL(arvoreAVL *adesc, tipoItem dadonovo);

/*-----------------------------------------------------------------------------
 * Prototipo: RotacaoSimples()
 * Função: Roda a arvore em uma so posicao
 * Entrada: Void
 * Saida: Não tem retorno.
 *----------------------------------------------------------------------------*/
void RotacaoSimples();

/*-----------------------------------------------------------------------------
 * Prototipo: RotacaoDupla()
 * Função: Rota a arvore tanto para direita quanto para esquerda
 * Entrada: Void
 * Saida: Não tem retorno.
 *----------------------------------------------------------------------------*/
void RotacaoDupla();

/*-----------------------------------------------------------------------------
 * Prototipo: AjustaFatoresAVL()
 * Função: Ajusta os fatores da arvore
 * Entrada: Void
 * Saida: Não tem retorno.
 *----------------------------------------------------------------------------*/
void AjustaFatoresAVL();

/*-----------------------------------------------------------------------------
 * Prototipo: BalanceiaAVL()
 * Função: Ira balancear a arvore
 * Entrada: Void
 * Saida: Não tem retorno.
 *----------------------------------------------------------------------------*/
void BalanceiaAVL();

/*-----------------------------------------------------------------------------
 * Prototipo: buscaArv(arvoreAVL **arv, char *nome)
 * Função: Buscar o nome na arvore
 * Entrada: ponteiro indicando a arvore e o nome para procurar
 * Saida: Não tem retorno.
 *----------------------------------------------------------------------------*/
void buscaArv(arvoreAVL **arv, char *nome);

#endif // ARVAVL_H
