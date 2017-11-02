#include "hash.h"

/*Funcao que cria a estrutura para a tabela hash
    max: tamanho maximo do hash
 */
void criaHash(int max, Thash **hash) {
    int i;
    // Aloca tabela
    *hash = malloc(sizeof (Thash) * max);
    for (i = 0; i < max; i++) {
        // Limpa os ponteiros
        (*hash)[i].cadPalavra = NULL;
        (*hash)[i].tam = 0;
    }
}

/*Funcao que define em que posicao da hash q a palavra sera inserido
    retorna a posicao no hash que o hPalavra deve ser inserido
 */
int funcaoEspalhamento(int pos, int max) {
    return (pos % max);
}

//Funcao que insere um novo hPalavra no cadastro

void inserehPalavra(Thash **hash, tipoItem palavra, int max, int pos) {

    int posicao = funcaoEspalhamento(pos, max);
    // procura no Hash
    hPalavra *cadPalavra = (*hash)[posicao].cadPalavra;

    // aloca registro
    hPalavra *nova = malloc(sizeof (hPalavra));
    strcpy(nova->palavra.nome, palavra.nome);
    nova->palavra.qtd = palavra.qtd;
    nova->prox = NULL;

    // Procura onde colocar o registro alocado
    if (cadPalavra == NULL) {
        (*hash)[posicao].cadPalavra = nova;
    } else {
        // Procurar um local na lista
        while (cadPalavra->prox != NULL)
            cadPalavra = cadPalavra->prox;
        cadPalavra->prox = nova;
    }

    // Aumenta tamanho da lista
    (*hash)[posicao].tam++;
}

/*Funcao que pesquisa por um hPalavra na tabela hash
    retorna o endereco de onde esta o hPalavra no hash
 */
hPalavra *buscaPalavra(Thash *hash, char* palavra, int max) {
    int comparacoes = 0;
    hPalavra *cadPalavra;
    // procura no Hash
    cadPalavra = hash[funcaoEspalhamento(palavra, max)].cadPalavra;

    // esta na lista ou nao tem
    while (cadPalavra != NULL) {
        //ta dando erro aqui
        if (strcmp(cadPalavra->palavra.nome, palavra) == 0) {
            comparacoes++;
            printf("\n\n\nComparacoes da busca: %d \n", comparacoes);
            return cadPalavra;
        }
        comparacoes++;
        cadPalavra = cadPalavra->prox;
    }
    printf("\n\n\nComparacoes da busca: %d \n", comparacoes);
    return NULL;
}

/*Funcao que imprime os dados de um hPalavra
    a: endereco de memoria onde estao guardadas as informacoes do hPalavra
 */
void imprimePalavrah(Thash *hash, hPalavra *a) {
    printf("Palavra: %s\n", a->palavra.nome);
    //printf("Linha: %d\n",a->palavra.linha); nao ta pedindo
    printf("Quantidade: %d\n", a->palavra.qtd);
}

/*Funcao que imprime a estrutura da tabela hash
    Forma de impressao:
        printf("Posicao %d - tamanho %d: ",i,hash[i].tam);
        printf("  %d  ",ptr->RA);
 */
void imprimeHash(Thash *hash, int max) {
    int i;
    hPalavra *cadPalavra;
    for (i = 0; i < max; i++) {
        printf("Posicao %d - tamanho %d: ", i, hash[i].tam);
        cadPalavra = hash[i].cadPalavra;

        if (hash[i].tam > 0) {
            // Tive que fazer esta "gambiarra" pois os espacos nao estao bem documentados
            printf("Palavra: ");
            printf(" %s  ", cadPalavra->palavra.nome);
            cadPalavra = cadPalavra->prox;
        }
        while (cadPalavra != NULL) {
            printf("  %s  ", cadPalavra->palavra.nome);
            cadPalavra = cadPalavra->prox;
        }
        printf("\n");
    }
}

//Funcao que libera memoria alocada para a tabela

void liberaHash(Thash *hash, int max) {

    int i;
    hPalavra *cadPalavra;
    hPalavra *tmp;
    // Corre a tabela
    for (i = 0; i < max; i++) {
        cadPalavra = hash[i].cadPalavra;
        // Corre a lista excluindo
        while (cadPalavra != NULL) {
            tmp = cadPalavra->prox;
            free(cadPalavra);
            cadPalavra = tmp;
        }
    }
    // Desaloca tabela
    free(hash);
}

