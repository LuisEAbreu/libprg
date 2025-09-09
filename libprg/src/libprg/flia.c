#include <stdbool.h>
#include "libprg/libprg.h"
#include <stdlib.h>

typedef struct fila {
    int *elementos,
        tamanho,
        inicio,
        fim,
        capacidade;
}fila_t;

fila_t *criar_fila(int capacidade) {
    fila_t *f = malloc(sizeof(fila_t));
    f->elementos = malloc(capacidade*sizeof(int));
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    f->capacidade = capacidade;
    return f;
}
void enfileirar(fila_t *fila, int valor) {
    fila->elementos[fila->fim] = valor;
    fila->fim++;
}

bool cheia(fila_t *fila) {
    return fila->tamanho==fila->capacidade;
}
// desenfileirar
// inicio
// fim
// tamanho
// destruir_fila