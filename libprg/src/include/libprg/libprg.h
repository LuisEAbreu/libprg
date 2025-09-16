#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

/*--PILHA--*/
typedef struct pilha pilha_t;

pilha_t *criar_pilha(int capacidade);
int empilhar(pilha_t *p, int valor);
int desempilhar(pilha_t *p);
int topo(pilha_t *p);
int tamanho(pilha_t *p);
int vazia(pilha_t *p);
int destruir_pilha(pilha_t *p);

/*--FILA--*/
typedef struct fila fila_t;

fila_t *criar_fila(int capacidade);
void enfileirar(fila_t *fila, int valor);
bool cheia(fila_t *fila);
bool fila_vazia(fila_t *fila);
int desenfileirar(fila_t *fila);
int inicio(fila_t *fila);
int fim(fila_t *fila);
int tamanho(fila_t *fila);
void destruir_fila(fila_t *fila);

/*--LISTA--*/

#endif
