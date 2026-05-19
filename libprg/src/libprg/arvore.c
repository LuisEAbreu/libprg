#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct noa {
    int dado;
    noa_t *esquerda;
    noa_t *direita;
} noa_t;

noa_t *criar_no(int dado) {
    noa_t *no = malloc(sizeof(noa_t));
    no->dado = dado;
    no->esquerda = NULL;
    no->direita = NULL;

    return no;
}

// adicionar
// remover
// destruir