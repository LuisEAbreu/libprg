#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct lista {
    int *elementos;
    int capacidade;
    int tamanho;
    int ordenada;
} lista_linear_t;

lista_linear_t *criar_lista_linear(int capacidade, int ordenada) {
    lista_linear_t *lista = malloc(sizeof(lista_linear_t));

    lista->elementos = malloc(sizeof(int) * capacidade);
    lista->capacidade = capacidade;
    lista->tamanho = 0;
    lista->ordenada = ordenada;

    return lista;
}

int lista_linear_cheia(lista_linear_t *lista) {
    if (lista->tamanho >= lista->capacidade) {
        return 1;
    }
    return 0;
}

int lista_linear_vazia(lista_linear_t *lista) {
    if (lista->tamanho <= 0) {
        return 1;
    }
    return 0;
}

int inserir_nao_ordenada(lista_linear_t *lista, int elemento) {
    return 0;
}

int inserir_ordenada(lista_linear_t *lista, int elemento) {
    return 0;
}

int inserir_lista_linear(lista_linear_t *lista, int elemento, int ordenada) {
    if (lista_linear_cheia(lista) == 1)
        return -1;

    if (ordenada == 0)
        inserir_nao_ordenada(lista, elemento);
    else
        inserir_ordenada(lista, elemento);

    return 0;
}

// remover_lista_linear
// buscar_lista_linear
// alterar_lista_linear
// ordenar_lista_linear
// combinar_lista_linear
// destruir_lista_linear