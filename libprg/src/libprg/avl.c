#include "libprg/libprg.h"

typedef struct noavl {
    int dado;
    noavl_t *esquerda;
    noavl_t *direita;
    int altura;
} noavl_t;