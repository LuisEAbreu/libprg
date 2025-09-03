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

void desempilhar() {

}

void tamanho() {

}

void vazia() {

}
*/