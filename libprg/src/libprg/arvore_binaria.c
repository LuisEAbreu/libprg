#include <stdbool.h>
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct no {
    int valor;
    struct no *esquerda;
    struct no *direita;
} no_t;

typedef struct no_avl {
    int valor;
    int altura; // altura da subárvore
    struct no *esquerda;
    struct no *direita;
} no_avl_t;

no_t *criar_no(int valor){
    no_t *no = (no_t *) malloc(sizeof(no_t));
    no->valor = valor;
    no->esquerda = no->direita = NULL;
    return no;
}

void destruir_no(no_t *no) {
    if (no != NULL) {
        destruir_no(no->esquerda);
        destruir_no(no->direita);
        free(no);
    }
}

no_t *inserir_valor(no_t *raiz, int valor){
    if (raiz == NULL)
        return criar_no(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir_valor(raiz->esquerda, valor);

    else if (valor > raiz->valor)
        raiz->direita = inserir_valor(raiz->direita, valor);

    return raiz;
}
bool busca(no_t *raiz, int valor){
    if (raiz == NULL)
        return false;

    if (valor == raiz->valor)
        return true;

    if (valor < raiz->valor)
        return busca(raiz->esquerda, valor);

    return busca(raiz->direita, valor);
}

no_t *remover_valor(no_t *raiz, int valor){
    if (raiz == NULL)
        return raiz;

    if (valor < raiz->valor)
        raiz->esquerda = remover_valor(raiz->esquerda, valor);

    else if (valor > raiz->valor)
        raiz->direita = remover_valor(raiz->direita, valor);

    else {
        if (raiz->esquerda == NULL) {
            no_t *aux = raiz->direita;
            free(raiz);
            return aux;
        }
        if (raiz->direita == NULL) {
            no_t *aux = raiz->esquerda;
            free(raiz);
            return aux;
        }
        no_t *aux = raiz->direita;
        while (aux->esquerda != NULL)
            aux = aux->esquerda;

        raiz->valor = aux->valor;
        raiz->direita = remover_valor(raiz->direita, aux->valor);
    }
    return raiz;
}