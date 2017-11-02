/*
 * TipoPilha.c
 *
 *  Created on: 25 de abr de 2017
 *      Author: junio
 */

#include"TipoPilha.h"

void FazPilhaVazia(TipoPilha *Pilha) {
	Pilha->Topo = (Apontador) malloc(sizeof(TipoCelula));
	Pilha->Topo->prox = NULL;
}

int PilhaVazia(TipoPilha *Pilha) {
	return (Pilha->Topo->prox == NULL);
}

void Empilha(TipoItem x, TipoPilha *Pilha) {
	Apontador p;
	p = (Apontador) malloc(sizeof(TipoCelula));
	Pilha->Topo->Item = x;
	p->prox = Pilha->Topo;
	Pilha->Topo = p;
}

void Desempilha(TipoPilha *Pilha) {

	TipoItem x;
	Apontador p;
	TipoFila Fila;
	if (PilhaVazia(Pilha)){
		return;
	}
	else {
		CriarFila(&Fila);
		while(1){
			p = Pilha->Topo;
			Pilha->Topo = p->prox;
			if(Pilha->Topo == NULL){
				break;
			}
			x = p->prox->Item;
			free(p);
			Enfileira(&Fila, x);

		}
		Desenfileira(&Fila);
	}
}
