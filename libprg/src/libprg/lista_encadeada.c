#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct no {
    int valor;
    struct no *proximo;
}no_t;

no_t *criar_lista_encadeada(int valor) {
    no_t *no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = NULL;

    return no;
}

void adicionar_no(no_t **inicio, int valor) {
    no_t *novo_no = criar_lista_encadeada(valor);
    novo_no->proximo = *inicio;
    *inicio = novo_no;
}

no_t *buscar_lista_encadeada(no_t **inicio, int valor) {
    no_t *atual = *inicio;

    while (atual) {     // dentro dos parênteses é o equivalente a (atual != NULL)
        if (atual->valor == valor)
            return atual;

        atual = atual->proximo;
    }

    return NULL;
}