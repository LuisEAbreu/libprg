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
    if (fila_cheia(fila)) {
        exit(EXIT_FAILURE);
    }
    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

bool fila_cheia(fila_t *fila) {
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

int inicio_da_fila(fila_t *fila){
    return fila->elementos[fila->inicio];
}

int fim_da_fila(fila_t *fila){
    return fila->elementos[fila->fim];
}

int tamanho_da_fila(fila_t *fila){
    return fila->tamanho;
}

void destruir_fila(fila_t *fila){
    free(fila->elementos);
    free(fila);
}