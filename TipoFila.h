/*
 * TipoFila.h
 *
 *  Created on: 25 de abr de 2017
 *      Author: junio
 */

#ifndef TIPOFILA_H_
#define TIPOFILA_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "TipoItem.h"

/*-----------------------------------------------------------------------------
 * Estrutura básica da fila
 *
 *
 * -----------------------------------------------------------------------------*/
typedef struct  TipoFila{
 Apontador inicio;
 Apontador fim;

}TipoFila;

/*-----------------------------------------------------------------------------
 * Prototipo: CriarFila( TipoFila *f)
 * Irá criar uma fila vazia
 *
 *
 * */
void CriarFila( TipoFila *f);

/*-----------------------------------------------------------------------------
 * Prototipo: Enfileira(TipoFila *f, TipoItem x)
 * Irá inserir na fila
 *
 *
 * */
void Enfileira(TipoFila *f, TipoItem x);

/*-----------------------------------------------------------------------------
 * Prototipo:
 * Irá verificar se a fila está vazia
 *
 *
 * */
int VerificaFila(TipoFila f);

/*-----------------------------------------------------------------------------
 * Prototipo: ImprimiFila(TipoItem Item)
 * Irá imprimir a fila
 *
 *
 * */
void ImprimiFila(TipoItem Item);

/*-----------------------------------------------------------------------------
 * Prototipo: Desenfileira(TipoFila *f)
 * Irá retirar da fila
 *
 *
 * */
void Desenfileira(TipoFila *f);

#endif /* TIPOFILA_H_ */
