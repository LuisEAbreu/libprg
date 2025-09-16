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

bool lista_linear_vazia(lista_linear_t *lista) {
    return lista->tamanho <= 0;
}

int buscar_na_lista(lista_linear_t *lista, int valor) {
    if (lista_linear_vazia(lista))
        exit(EXIT_FAILURE);

    int indice=0;

    while (indice < lista->tamanho) {
        if (lista->elementos[indice] == valor)
            return indice;
        indice++;
    }
    return -1;
}

int remover_da_lista(lista_linear_t *lista, int valor) {
    if (lista_linear_vazia(lista))
        exit(EXIT_FAILURE);

    int indice = buscar_na_lista(lista, valor);

    if (indice!=-1) {
        lista->elementos[indice] = lista->elementos[lista->tamanho];
        lista->tamanho--;
        return 0;
    }
    return -1;
}

// destruir