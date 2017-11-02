#include "arvbb.h"

Arv* arvore_cria(void) {
    return NULL;
}

Arv* arvore_insere(Arv* a, tipoItem v) {

    if (arvore_busca(a, v) == 1)
        return a;

    if (a == NULL) {
        a = (Arv*) malloc(sizeof (Arv));
        strcpy(a->palavra.nome, v.nome);
        a->esq = a->dir = NULL;
    } else if (strcmp(v.nome, a->palavra.nome) < 0)
        a->esq = arvore_insere(a->esq, v);
    else /* v < a->chave*/
        a-> dir = arvore_insere(a->dir, v);
    return a;
}

void arvore_imprimePreEsq(Arv* a) {
    if (a != NULL) {
        printf("%s ", a->palavra.nome);
        arvore_imprimePreEsq(a->esq);
        arvore_imprimePreEsq(a->dir);
    }
}

void arvore_imprimePreDir(Arv* a) {
    if (a != NULL) {
        printf("%s ", a->palavra.nome);
        arvore_imprimePreDir(a->dir);
        arvore_imprimePreDir(a->esq);
    }
}

void arvore_imprimeCentEsq(Arv* a) {
    if (a != NULL) {
        arvore_imprimeCentEsq(a->esq);
        printf("%s ", a->palavra.nome);
        arvore_imprimeCentEsq(a->dir);
    }
}

void arvore_imprimeCentDir(Arv* a) {
    if (a != NULL) {
        arvore_imprimeCentDir(a->dir);
        printf("%s ", a->palavra.nome);
        arvore_imprimeCentDir(a->esq);
    }
}

void arvore_imprimePosEsq(Arv* a) {
    if (a != NULL) {
        arvore_imprimePosEsq(a->esq);
        arvore_imprimePosEsq(a->dir);
        printf("%s ", a->palavra.nome);
    }
}

void arvore_imprimePosDir(Arv* a) {
    if (a != NULL) {
        arvore_imprimePosDir(a->dir);
        arvore_imprimePosDir(a->esq);
        printf("%s ", a->palavra.nome);
    }
}

int arvore_busca(Arv* r, tipoItem v) {
    if (r == NULL)
        return 0;

    else if (strcmp(r->palavra.nome, v.nome) > 0)
        return arvore_busca(r->esq, v);

    else if (strcmp(r->palavra.nome, v.nome) < 0)
        return arvore_busca(r->dir, v);

    else
        return 1;
}

int buscabb(Arv* r, char *nome) {
    printf("entrou na funcao de busca\n\n");
    if (r == NULL)
        return 0;

    else if (strcmp(r->palavra.nome, nome) > 0)
        return buscabb(r->esq, nome);

    else if (strcmp(r->palavra.nome, nome) < 0)
        return buscabb(r->dir, nome);

    else
        return 1;
}
