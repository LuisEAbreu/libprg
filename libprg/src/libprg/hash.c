#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct noh {
    char *chave;
    int valor;
    noh_t *proximo;
} noh_t;

typedef struct dicionario {
    int tamanho;
    noh_t **vetor;
} dicionario_t;

dicionario_t *criar_dicionario(int m) {
    dicionario_t *dicionario;

    if (m < 1)
        return NULL;

    dicionario = malloc(sizeof(dicionario_t));
    dicionario->vetor = malloc(m * sizeof(noh_t*));
    dicionario->tamanho = m;

    return dicionario;
}