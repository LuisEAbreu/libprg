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

int fila_cheia(fila_t *fila) {
    if (fila->tamanho >= fila->capacidade)
        return 1;
    return 0;
}

int enfileirar(fila_t *fila, int valor) {
    if (fila_cheia(fila) == 1)
        return -1;

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;

    return 0;
}

int fila_vazia(fila_t *fila) {
    if (fila->tamanho <= 0)
        return 1;
    return 0;
}

int desenfileirar(fila_t *fila) {
    if (fila_vazia(fila) == 1)
        return -1;

    int valor = fila->elementos[fila->fim];
    fila->fim = (fila->fim - 1) % fila->capacidade;
    fila->tamanho--;

    return valor;
}

int inicio_fila(fila_t *fila) {
    return fila->elementos[fila->inicio];
}

int fim_fila(fila_t *fila) {
    return fila->elementos[fila->fim];
}

int tamanho_fila(fila_t *fila) {
    return fila->tamanho;
}

int valor_indice_fila(fila_t *fila, int indice) {
    if (indice > fila->tamanho)
        return -1;
    return fila->elementos[indice];
}

int destruir_fila(fila_t *fila) {
    free(fila->elementos);
    free(fila);

    return 0;
}