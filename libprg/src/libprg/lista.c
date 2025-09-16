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
// inserir
// buscar
// remover
// vazia
// cheia
// destruir