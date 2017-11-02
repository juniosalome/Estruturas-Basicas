#include "TipoLista.h"
//https://gilsonguimaraes.wordpress.com/2011/07/03/codigo-lista-duplamente-encadeada-circular/

//Cria uma nova lista encadeada;
TipoLista *criarTipoLista()
{
    TipoLista *l = (TipoLista*) malloc (sizeof(TipoLista));
    l->cabeca = NULL;
    l->cauda = NULL;
    l->tamanho = 0;
    return l;
}

//Insere um nó no começo da lista l
void inserirInicio(int valor, TipoLista *l)
{
    if (l != NULL)
    {
        TipoCelula *no = (TipoCelula*) malloc (sizeof(TipoCelula));
        no->item->id = valor;
        if (l->tamanho == 0)
        {
            l->cabeca = no;
            l->cauda = no;
            no->anterior = no;
            no->proximo = no;
            l->tamanho++;
            return;
        }
        if (l->tamanho == 1)
        {
            l->cabeca->anterior = no;
            l->cabeca->proximo = no;
            no->proximo = l->cabeca;
            no->anterior = l->cauda;
            l->cabeca = no;
            l->tamanho++;
            return;
        }
        l->cabeca->anterior = no;
        l->cauda->proximo = no;
        no->anterior = l->cauda;
        no->proximo = l->cabeca;
        l->cabeca = no;
        l->tamanho++;
    }
}

//Imprime todos os valores dos nós da lista
void imprimirLista(TipoLista *l)
{
    if ((l->tamanho == 0) || (l == NULL))
        return;
    TipoCelula *no = l->cabeca;
    //imprime o primeiro
    printf("%d ", no->item->id);
    no = no->proximo;
    while (no != l->cabeca)
    {
        printf("%d ", no->item->id);
        no = no->proximo;
    }
}

//Remove todos os nós da lista e depois a deleta;
void deletarLista(TipoLista **l)
{
    if (((*l)->tamanho == 0) || (*l) == NULL)
        return;
    if ((*l)->tamanho == 1)
    {
        TipoCelula *no = (*l)->cabeca;
        free (no);
        free ((*l));
        (*l) = NULL;
        return;
    }
    while ((*l)->tamanho > 0)
        removerPrimeiro((*l));
    free ((*l));
    (*l) = NULL;
}

//Remove o primeiro nó da lista
void removerPrimeiro(TipoLista *l)
{
   if ((l->tamanho == 0) || (l == NULL))
        return;
    if (l->tamanho == 1)
    {
        free (l->cabeca);
        l->cabeca = NULL;
        l->cauda = NULL;
        l->tamanho = 0;
        return;
    }
    TipoCelula *no = l->cabeca->proximo;
    no->anterior = l->cauda;
    l->cauda->proximo = no;
    free(l->cabeca);
    l->cabeca = no;
    l->tamanho--;
}

//Insere um nó no final da lista l
void inserirFinal(int valor, TipoLista *l)
{
    if (l == NULL)
        return;
    if (l->tamanho == 0)
    {
        inserirInicio(valor,l);
        return;
    }
    TipoCelula *no = l->cabeca, *novo;
    while (no->proximo != l->cabeca)
    {
        no = no->proximo;
    }
    novo = (TipoCelula*) malloc (sizeof(TipoCelula));
    novo->item->id = valor;
    no->proximo = novo;
    novo->anterior = no;
    novo->proximo = l->cabeca;
    l->cauda = novo;
    l->tamanho++;
}

//Insere um nó em determinada posicao da lista l
void inserirPosicao(int valor, int posicao, TipoLista *l)
{
    if ((l == NULL) || (posicao > l->tamanho))
        return;
    int i;
    TipoCelula *no = l->cabeca, *novo;
    for (i = 1; i < posicao; i++)//i inicializa em 1 para parar na posicao correta         no = no->proximo;
    novo = (TipoCelula*) malloc(sizeof(TipoCelula));
    novo->item->id = valor;
    no->proximo->anterior = novo;
    novo->proximo = no->proximo;
    no->proximo = novo;
    novo->anterior = no;
    l->tamanho++;
}

//Remove os nós que contém determinado valor da lista l
void removerValor(int valor, TipoLista *l)
{
   if ((l->tamanho == 0) || (l == NULL))
        return;
    TipoCelula *no = l->cabeca, *aux;
    while (no->proximo != l->cabeca)
    {
        if (no == l->cabeca)
        {
            if (no->item->id == valor)
            {
                l->cabeca = no->proximo;
                l->cauda->proximo = l->cabeca;
                free (no);
                l->tamanho--;
                no = l->cabeca;
            }
        }
        else
        {
            if (no->item->id == valor)
            {
                no->anterior->proximo = no->proximo;
                no->proximo->anterior = no->anterior;
                aux = no;
                no = no->anterior;
                free(aux);
                l->tamanho--;
            }
        }
        no = no->proximo;
    }
    //condicao para o ultimo
    if (no->item->id == valor)
    {
        l->cauda = no->anterior;
        l->cauda->proximo = l->cabeca;
        l->cabeca->anterior = l->cauda;
        free(no);
        l->tamanho--;
    }
}

//Remove o ultimo nó da Lista
void removerUltimo(TipoLista *l)
{
    if ((l->tamanho == 0) || (l == NULL))
        return;
    if (l->tamanho == 1)
    {
        removerPrimeiro(l);
        return;
    }
    TipoCelula *no = l->cauda;
    l->cauda = no->anterior;
    l->cauda->proximo = l->cabeca;
    l->cabeca->anterior = l->cauda;
    free (no);
    l->tamanho--;
}

//Remove o nó de determinada posição da lista
void removerPosicao(int posicao, TipoLista *l)
{
    if ((l->tamanho == 0) || (l == NULL))
        return;
    if (l->tamanho == 1)
    {
        removerPrimeiro(l);
        return;
    }
    if (posicao == l->tamanho-1)
    {
        removerUltimo(l);
        return;
    }
    int i;
    TipoCelula *no = l->cabeca;
    for (i = 0; i < posicao; i++)     {         no = no->proximo;
    }
    no->anterior->proximo = no->proximo;
    no->proximo->anterior = no->anterior;
    free(no);
}

//Retorna quantos nós da lista são multiplos de determinado valor
int multiplos(int valor, TipoLista *l)
{
    if ((l->tamanho == 0) || (l == NULL))
        return 0;
    if (l->tamanho == 1)
    {
        if ((l->cabeca->item->id % valor) == 0)
            return 1;
        return 0;
    }
    int cont = 0;
    TipoCelula *no = l->cabeca;
    while (no->proximo != l->cabeca)
    {
        if ((no->item->id % valor) == 0)
            cont++;
        no = no->proximo;
    }
    //verifica o último
    if ((no->item->id % valor) == 0)
        cont++;
    return cont;
}

//Retorna true se a lista estiver crescentemente ordenada e false caso contrário
bool estaOrdenada(TipoLista *l)
{
    if ((l->tamanho == 0) || (l->tamanho == 1) || (l == NULL))
        return true;
    TipoCelula *no = l->cabeca;
    while (no->proximo != l->cabeca)
    {
        if (no->item->id > no->proximo->item->id)
            return false;
        no = no->proximo;
    }
    return true;
}
