#include <stdlib.h>

typedef struct pilha {
    int *elementos;
    int capacidade;
    int topo;
} pilha_t;

pilha_t *criar_pilha(int capacidade) {
    pilha_t *pilha = malloc(sizeof(pilha_t));

    pilha->elementos = malloc(sizeof(int) * capacidade);
    pilha->capacidade = capacidade;
    pilha->topo = -1;

    return pilha;
}

int pilha_cheia(pilha_t *pilha) {
    if (pilha->capacidade >= pilha->topo)
        return 1;
    return 0;
}

int empilhar(pilha_t *pilha, int valor) {
    if (pilha_cheia(pilha) == 1) {
        pilha->capacidade *= 2;
        pilha->elementos = realloc(pilha->elementos,pilha->capacidade * sizeof(int));

        if (pilha->elementos == NULL)
            return -1;
    }
    pilha->topo++;
    pilha->elementos[pilha->topo] = valor;

    return 0;
}
// desempilhar
// tamanho
// vazia