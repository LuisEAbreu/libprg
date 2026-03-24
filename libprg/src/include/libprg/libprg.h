#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

/*===== PILHA =====*/
typedef struct pilha pilha_t;

pilha_t *criar_pilha(int capacidade);
int pilha_cheia(pilha_t *pilha);

#endif
