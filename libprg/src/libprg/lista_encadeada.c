#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct no {
    int dado;
    no_t *proximo;
} no_t;

no_t *criar_lista_encadeada(int valor) {
    no_t *no = malloc(sizeof(no_t));
    no->dado = valor;
    no->proximo = NULL;

    return no;
}

// inserir
// remover
// buscar
// destruir