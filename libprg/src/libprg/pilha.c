//
// Created by luise on 02/09/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *elementos,
        topo,
        capacidade;
} pilha_t;

pilha_t *criar_pilha(int capacidade) {
    pilha_t *p = malloc(sizeof(pilha_t));
    p->elementos = malloc(capacidade*sizeof(int));
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

int empilhar(pilha_t *p, int valor) {
    if (p->topo == p->capacidade-1) {
        printf("Erro: A pilha está cheia (Overflow).\n");
        return -1;
    }
    p->topo++;
    p->elementos[p->topo] = valor;
    return 0;
}

int desempilhar(pilha_t *p) {
    if (p->topo == -1) {
        printf("Erro: A pilha está vazia (Underflow).\n");
        return -1;
    }
    int valor = p->elementos[p->topo];
    p->topo--;
    return valor;
}

int tamanho(pilha_t *p) {
    return p->topo + 1;
}

int vazia(pilha_t *p) {
    if (p->topo == -1)
        return 0;
    return -1;
}