#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct fila {
    int *elementos;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
} fila_t;


fila_t *criar_fila(int capacidade) {
    fila_t *fila = malloc(sizeof(fila_t));
    fila->elementos = malloc(sizeof(int) * capacidade);
    fila->capacidade = capacidade;
    fila->tamanho = 0;
    fila->inicio = 0;
    fila->fim = 0;

    return fila;
}
// enfileirar
// desenfileirar
// inicio_fila
// fim_fila
// fila_vazia
// fila_cheia

int destruir_fila(fila_t *fila) {
    free(fila->elementos);
    free(fila);

    return 0;
}