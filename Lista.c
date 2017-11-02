#include "Lista.h"

void inicializa(tipoLista *lista) {

    lista->tamanho = 0;
    lista->ultimo = (apontador) malloc(sizeof (celula));
    lista->primeiro = lista->ultimo;
    lista->ultimo->prox = lista->ultimo->anterior = NULL;

}

int vazia(tipoLista lista) {

    return (lista.primeiro == lista.ultimo);
}

apontador buscaLocalin(tipoItem x, tipoLista* lista) {
    int cont = 0;
    apontador aux;

    if (vazia(*lista)) {
        aux = lista->primeiro;
        return aux;
    }
    else {

        aux = lista->primeiro->prox;

        while (aux != NULL) {

            if (strcmp(aux->item.nome, x.nome) == 1) {

                cont++;
                return aux;
            }

            aux = aux->prox;
        }

        if (cont == 0) {
            aux = NULL;
            return aux;
        }
    }

}

void buscaSequencial(char* nome, tipoLista* lista) {
    apontador aux;
    int i, cont = 0;
    aux = lista->primeiro->prox;
    while (aux != NULL) {
        cont++;
        if ((strcmp(aux->item.nome, nome) == 0)) {
            system("cls");
            printf("PALAVRA ENCONTRADA!\n");
            printf("\n\nstring = %s\n", aux->item.nome);
            printf("linha(s) = ");
            for (i = 0; i < aux->item.qtd; i++) {
                printf("%d ", aux->item.linha[i] + 1);
            }
            printf("\npalavra repete %d vez(es)\n", aux->item.qtd);
            printf("\nForam feitas %i comparacoes\n", cont);
        }
        aux = aux->prox;
    }
    printf("Palavra nao encontrada! \n\n");
}

void buscaBinaria(char* nome, tipoItem *vetor, int tam) {
    int i;
    int inf = 0, sup = tam, x, comp = 0;
    char nome2[20];
    int a;

    while (inf <= sup) {
        comp++;
        x = (inf + sup) / 2;
        strcpy(nome2, vetor[x].nome);
        a = strcmp(nome2, nome);
        if (a == 0) {

            printf("PALAVRA ENCONTRADA!\n");
            printf("\n\nstring = %s\n", (vetor[x]).nome);
            printf("linha(s) = ");
            for (i = 0; i < vetor[x].qtd; i++) {
                printf("%d ", vetor[x].linha[i] + 1);
            }
            printf("\npalavra repete %d vez(es)\n", vetor[x].qtd);
            printf("\nForam feitas %i comparacoes\n", comp);
            break;
        } else if (strcmp((vetor[x]).nome, nome) < 0) {
            inf = x + 1;
        } else {
            sup = x - 1;
        }
    }

    printf("Palavra nao encontrada! \n\n");
}

tipoItem* listaParaVetorLista(tipoLista *lista) {
    int i, n;

    tipoItem *item;
    apontador aux;
    n = lista->tamanho;
    tipoItem *elementos;

    elementos = (tipoItem*) malloc(sizeof (tipoItem) * n);
    aux = lista->primeiro->prox;
    for (i = 0; i < n; i++) {
        elementos[i] = aux->item;
        aux = aux->prox;
    }
    return elementos;
}

void insere(apontador local, tipoItem item, tipoLista* lista) {

        if (vazia(*lista)) {
            apontador aux = (apontador) malloc(sizeof (celula));
            aux->item = item;
            lista->primeiro->prox = aux;
            aux->anterior = lista->primeiro;
            lista->ultimo = aux;
            aux->prox = NULL;
        }

        else if (local == NULL) {
            apontador aux = (apontador) malloc(sizeof (celula));
            aux->item = item;
            aux->anterior = lista->ultimo;
            lista->ultimo->prox = aux;
            lista->ultimo = aux;
            aux->prox = NULL;
        }

        else {
            apontador aux = (apontador) malloc(sizeof (celula));
            aux->item = item;
            aux->prox = local;
            local->anterior->prox = aux;
            aux->anterior = local->anterior;
            local->anterior = aux;
        }
        lista->tamanho++;


}

int ConferePalavraIgual(char* nome, tipoLista *lista, int lin) {
    apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL) {
        if ((strcmp(aux->item.nome, nome) == 0)) {
            aux->item.linha[aux->item.qtd] = lin;
            aux->item.qtd++;
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

void imprimeLista(tipoLista *lista) {
    int i;
    apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL) {
        printf("\n\nstring = %s\n", aux->item.nome);
        printf("linha(s) = ");
        for (i = 0; i < aux->item.qtd; i++) {
            printf("%d ", aux->item.linha[i] + 1);
        }
        printf("\npalavra repete %d vez(es)\n", aux->item.qtd);
        aux = aux->prox;
    }
    printf("\nTamanho da lista: %d\n", lista->tamanho);
}

