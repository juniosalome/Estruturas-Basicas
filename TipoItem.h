/*
 * TipoItem.h
 *
 *  Created on: 25 de abr de 2017
 *      Author: junio
 */

#ifndef TIPOITEM_H_
#define TIPOITEM_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef unsigned int TipoChave;

typedef struct TipoItem{
	TipoChave chave;
}TipoItem;

typedef struct TipoCelula * Apontador;

typedef struct TipoCelula{
	TipoItem Item;
	Apontador prox;
}TipoCelula;

#endif /* TIPOITEM_H_ */
