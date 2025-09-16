#include <stdbool.h>
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct lista_linear {
    int *elementos,
        tamanho,
        capacidade;
}lista_linear_t;

lista_linear_t *criar_lista_linear(int capacidade) {
    lista_linear_t *lista = malloc(sizeof(lista_linear_t));
    lista->elementos = malloc(sizeof(int)*capacidade);
    lista->tamanho = 0;

    return lista;
}

bool lista_linear_cheia(lista_linear_t *lista) {
    return lista->tamanho >= lista->capacidade;
}

void inserir(lista_linear_t *lista, int valor) {
    if (lista_linear_cheia(lista))
        exit(EXIT_FAILURE);

    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}

// buscar
// remover
// vazia
// cheia
// destruir