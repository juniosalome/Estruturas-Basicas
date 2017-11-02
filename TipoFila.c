/*
 * TipoFila.c
 *
 *  Created on: 25 de abr de 2017
 *      Author: junio
 */
#include"TipoFila.h"

void CriarFila(TipoFila *f) {
	f->inicio = malloc(sizeof(TipoCelula));
	f->fim = f->inicio;
	f->inicio->prox = NULL;
}

void Enfileira(TipoFila *f, TipoItem x) {
	f->fim->prox = malloc(sizeof(TipoCelula));
	f->fim = f->fim->prox;
	f->fim->Item = x;
	f->fim->prox = NULL;
}

int VerificaFila(TipoFila f) {
	return (f.inicio == f.fim);
}

void ImprimiFila(TipoItem Item) {

	printf("%d", Item);

}

void Desenfileira(TipoFila *f) {

	Apontador q;
	TipoItem Item;
	if (VerificaFila(*f)) {
		printf("Erro: fila vazia\n");
		return;
	}
	while (1) {
		q = f->inicio;
		f->inicio = f->inicio->prox;
		if(f->inicio == NULL){
					break;
				}
		Item = f->inicio->Item;
		free(q);
		ImprimiFila(Item);

	}
}
