#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct noavl {
    int dado;
    noavl_t *esquerda;
    noavl_t *direita;
    int altura;
} noavl_t;

noavl_t *criar_noavl(int dado) {
    noavl_t *no = malloc(sizeof(noavl_t));
    no->dado = dado;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 0;

    return no;
}