#ifndef PILHA_H_
#define PILHA_H_

typedef struct {
	int x;
  	int y;
  	int prox;
} ElementPilhaT;

typedef struct Celula* PtrCel;

typedef struct Celula {
    ElementPilhaT elem;
    PtrCel Prox;
} Celula;

typedef struct {
    PtrCel Fundo, Topo;
    int Tamanho;
} TipoPilha;

/*-----------------------------------------------------------------------------
 * Prototipo: FPVazia()
 * Função: Criar uma pilha (faz a celula cabeca com apontadores)
 * Entrada: Void
 * Saida: Retorna um ponteiro do TipoPilha
 *----------------------------------------------------------------------------*/
TipoPilha* FPVazia();

/*-----------------------------------------------------------------------------
 * Prototipo: Vazia(const TipoPilha *Pilha)
 * Função: Verificar se a pilha esta vazia
 * Entrada: O ponteiro indicando a pilha
 * Saida: Retorna 1 se a pilha estiver vazia, e 0 caso contrário
 *----------------------------------------------------------------------------*/
int Vazia(TipoPilha *Pilha);

/*-----------------------------------------------------------------------------
 * Prototipo: Empilha(TipoPilha *Pilha, ElementPilhaT elem)
 * Função: Empilha um novo conjunto de pontos x,y na pilha indicada.
 * Entrada: As posições x e y, e um ponteiro indicando a pilha
 * Saida: Não tem retorno.
 *----------------------------------------------------------------------------*/
void Empilha(TipoPilha *Pilha, ElementPilhaT elem);

/*-----------------------------------------------------------------------------
 * Prototipo: Desempilha(TipoPilha *Pilha)
 * Função: Desempilha o ultimo elemento que entrou da pilha
 * Entrada: Um ponteiro indicando a pilha
 * Saida: Retorna o elemento desempilhado.
 *----------------------------------------------------------------------------*/
ElementPilhaT Desempilha(TipoPilha *Pilha);

#endif // PILHA_H_
