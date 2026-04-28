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

void inserir_encadeada(no_t **inicio, int valor) {
    no_t *novo_no = criar_lista_encadeada(valor);
    novo_no->proximo = *inicio;
    *inicio = novo_no;
}

// remover
// buscar
// destruir