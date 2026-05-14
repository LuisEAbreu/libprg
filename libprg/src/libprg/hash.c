#include "libprg/libprg.h"

typedef struct noh {
    char *chave;
    int valor;
    noh_t *proximo;
} noh_t;