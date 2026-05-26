#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct noavl {
    int dado;
    noavl_t *esquerda;
    noavl_t *direita;
    int altura;
} noavl_t;

noavl_t *criar_noavl(int dado) {
    noavl_t *no = malloc(sizeof(noavl_t));
    no->dado = dado;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 0;

    return no;
}

int altura_avl(noavl_t *raiz) {
    if (raiz == NULL)
        return 0;
    return raiz->altura;
}

int fator_balanceamento(noavl_t *raiz) {
    if (raiz == NULL)
        return 0;
    return altura_avl(raiz->esquerda) - altura_avl(raiz->direita);
}

noavl_t *adicionar_noavl(noavl_t *raiz, int dado) {
    if (raiz == NULL)
        return criar_noavl(dado);

    if (dado > raiz->dado)
        raiz->direita = adicionar_noavl(raiz->direita, dado);

    if (dado < raiz->dado)
        raiz->esquerda = adicionar_noavl(raiz->esquerda, dado);

    return raiz;
}