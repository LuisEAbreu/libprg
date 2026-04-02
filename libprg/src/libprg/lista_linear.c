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

// inserir_lista_linear
// remover_lista_linear
// buscar_lista_linear
// alterar_lista_linear
// ordenar_lista_linear
// combinar_lista_linear
// destruir_lista_linear