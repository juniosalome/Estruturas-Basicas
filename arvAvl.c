#include "arvAvl.h"


//-------------------------------------------

void LeArv(arvoreAVL **eainicio) {
    if (*eainicio == NULL)
        printf("\n");
    else {
        printf("%s\n", (*eainicio)->palavra.nome);
        LeArv(&((*eainicio)->esq));
        LeArv(&((*eainicio)->dir));
    }
}

void buscaArv(arvoreAVL **arv, char* nome) {
    if (*arv != NULL) {
        if (strcmp((*arv)->palavra.nome, nome) == 0) {
            printf("achou a palavra\n");
        } else if (strcmp((*arv)->palavra.nome, nome) > 0) {
            buscaArv(&((*arv)->esq), nome);
        } else if (strcmp((*arv)->palavra.nome, nome) < 0) {
            buscaArv(&((*arv)->dir), nome);
        }
    } else
        printf("\n\n!!Palavra nao encontrada!!");
}

//-------------------------------------------

void InicializaAVL(arvoreAVL **eainicio) {
    *eainicio = malloc(sizeof (arvoreAVL));
    (*eainicio)->esq = NULL;
    (*eainicio)->dir = NULL;
}

//-------------------------------------------

void InsereAVL(arvoreAVL *adesc, tipoItem newpalavra) {
    arvoreAVL *paux, *pant, *pP, *pQ, *pantP, *pnovo;
    int poschave;
    int achou;

    //-------rota��o simples---------------------

    void RotacaoSimples() {
        if (pP->fatbal == 1) {
            pP->dir = pQ->esq;
            pQ->esq = pP;
        } else {
            pP->esq = pQ->dir;
            pQ->dir = pP;
        }
        paux = pQ;
        pP->fatbal = 0;
        pQ->fatbal = 0;
    }
    //-------fim do rota��o simples-------------

    //-------rota��o dupla ---------------------

    void RotacaoDupla() {
        if (pP->fatbal == 1) {
            paux = pQ->esq;
            pQ->esq = paux->dir;
            paux->dir = pQ;
            pP->dir = paux->esq;
            paux->esq = pP;
        } else {
            paux = pQ->dir;
            pQ->dir = paux->esq;
            paux->esq = pQ;
            pP->esq = paux->dir;
            paux->dir = pP;
        }
        if (paux->fatbal == -poschave) {
            pP->fatbal = 0;
            pQ->fatbal = poschave;
        } else
            if (paux->fatbal == 0) {
            pP->fatbal = 0;
            pQ->fatbal = 0;
        } else {
            pP->fatbal = -poschave;
            pQ->fatbal = 0;
        }
        paux->fatbal = 0;
    }
    //-------fim do rota��o dupla -------------

    //-------ajustfatores---------------------

    void AjustaFatoresAVL() {
        //if (newpalavra < pP->palavra.nome){
        if (strcmp(newpalavra.nome, pP->palavra.nome) < 0) {
            pQ = pP->esq;
            paux = pP->esq;
        } else {
            pQ = pP->dir;
            paux = pP->dir;
        }
        while (strcmp(paux->palavra.nome, newpalavra.nome) != 0)
            if (strcmp(newpalavra.nome, paux->palavra.nome) < 0) {
                paux->fatbal = paux->fatbal - 1;
                paux = paux->esq;
            } else {
                paux->fatbal = paux->fatbal + 1;
                paux = paux->dir;
            }
    }
    //-------fim do ajusta fatores-------------

    //-------balanceia-------------------------

    void BalanceiaAVL() {
        if (strcmp(newpalavra.nome, pP->palavra.nome) < 0)
            poschave = -1;
        else
            poschave = 1;
        if (pP->fatbal == 0)
            pP->fatbal = poschave;
        else
            if (pP->fatbal == -poschave)
            pP->fatbal = 0;
        else {
            if (pQ->fatbal * poschave > 0)
                RotacaoSimples();
            else
                RotacaoDupla();
            if (pantP->dir == pP)
                pantP->dir = paux;
            else
                pantP->esq = paux;
        }
    }
    //-------fim do balanceia------------------

    //---- corpo do InsereAVL -----------------
    paux = adesc->dir;
    pP = paux;
    pant = adesc;
    pantP = adesc;
    achou = 0;
    while ((!achou) && (paux != NULL)) {
        if (paux->fatbal != 0) {
            pP = paux;
            pantP = pant;
        }
        pant = paux;
        if (strcmp(newpalavra.nome, paux->palavra.nome) == 0)
            achou = 1;
        else
            if (strcmp(newpalavra.nome, paux->palavra.nome) < 0)
            paux = paux->esq;
        else
            paux = paux->dir;
    }
    if (achou)
        printf("este palavra.nome ja esta presente na arvore\n");
    else {
        pnovo = malloc(sizeof (arvoreAVL));
        strcpy(pnovo->palavra.nome, newpalavra.nome);
        pnovo->esq = NULL;
        pnovo->dir = NULL;
        pnovo->fatbal = 0;
        if (adesc->dir == NULL)
            adesc->dir = pnovo;
        else {
            if (strcmp(newpalavra.nome, pant->palavra.nome) < 0)
                pant->esq = pnovo;
            else
                pant->dir = pnovo;
            AjustaFatoresAVL();
            BalanceiaAVL();
        }
    }
}
