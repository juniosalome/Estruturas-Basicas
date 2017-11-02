/*
 * TipoPilha.h
 *
 *  Created on: 25 de abr de 2017
 *      Author: junio
 */

#ifndef TIPOPILHA_H_
#define TIPOPILHA_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "TipoItem.h"
#include "TipoFila.h"
/*
 * Estrutura básica da pilha
 *
 *
 * */
typedef struct TipoPilha {
	Apontador Topo;
} TipoPilha;

/*
 * Irá criar uma pilha vazia
 *
 *
 * */
void FazPilhaVazia(TipoPilha *Pilha);

/*
 * Irá verificar se pilha está vazia
 *
 *
 * */
int PilhaVazia(TipoPilha *Pilha);

/*
 * Irá colocar um item da pilha
 *
 *
 * */
void Empilha(TipoItem x, TipoPilha *Pilha);

/*
 * Irá retirar um item da pilha
 *
 *
 * */
void Desempilha(TipoPilha *Pilha);

// conjunto de operações que podem ser aplicadas sobre o modelo 'TipoPilha'

#endif /* TIPOPILHA_H_ */
