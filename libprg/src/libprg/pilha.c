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

// empilhar
// desempilhar
// tamanho
// vazia