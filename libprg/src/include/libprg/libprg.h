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
int valor_indice_pilha(pilha_t *pilha, int indice);

/*===== FILA =====*/
typedef struct fila fila_t;
fila_t *criar_fila(int capacidade);
int destruir_fila(fila_t *fila);
int fila_cheia(fila_t *fila);

#endif
