#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "pilha.h"

TipoPilha* FPVazia(){
    TipoPilha *Pilha = (TipoPilha*)malloc(sizeof(TipoPilha));
    Pilha->Topo = (PtrCel) malloc(sizeof(Celula));
    
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;

    return Pilha;
}

int Vazia(TipoPilha *Pilha){
    return (Pilha->Topo == Pilha->Fundo);
}

void Empilha(TipoPilha *Pilha, ElementPilhaT elem){
    PtrCel Aux = (PtrCel)malloc(sizeof(Celula));
    Pilha->Topo->elem = elem;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux; 
    Pilha->Tamanho++;
}

ElementPilhaT Desempilha(TipoPilha *Pilha){
    PtrCel q;
    
    if (Vazia(Pilha)) {
        printf("Erro: pilha vazia\n");
        ElementPilhaT elem;
        // retorna elemento simbólico
        return elem;
    }

    q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    free(q);

    Pilha->Tamanho--;
    return Pilha->Topo->elem;
}

void DestroiPilha(TipoPilha *Pilha){
    // Desempilha todos os elementos da pilha
    while(!Vazia(Pilha)){
        Desempilha(Pilha);
    }

    // desaloca o topo
    if(Pilha->Topo != NULL)
        free(Pilha->Topo);

    free(Pilha);
}
