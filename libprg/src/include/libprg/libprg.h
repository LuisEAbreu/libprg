#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

/*===== PILHA =====*/
typedef struct pilha pilha_t;

pilha_t *criar_pilha(int capacidade);
int pilha_cheia(pilha_t *pilha);
int empilhar(pilha_t *pilha, int valor);
int topo_pilha(pilha_t *pilha);
int tamanho_pilha(pilha_t *pilha);
int pilha_vazia(pilha_t *pilha);
int desempilhar(pilha_t *pilha);
int destruir_pilha(pilha_t *pilha);

#endif
