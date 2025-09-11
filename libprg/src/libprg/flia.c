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
    if (cheia(fila)) {
        exit(EXIT_FAILURE);
    }
    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

bool cheia(fila_t *fila) {
    return fila->tamanho>=fila->capacidade;
}

bool fila_vazia(fila_t *fila) {
    return fila->tamanho<=0;
}

int desenfileirar(fila_t *fila) {
    if (fila_vazia(fila)) {
        exit(EXIT_FAILURE);
    }
    int valor = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
    return valor;
}
// inicio
// fim
// tamanho
// destruir_fila