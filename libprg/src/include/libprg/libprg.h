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
int enfileirar(fila_t *fila, int valor);
int fila_vazia(fila_t *fila);
int desenfileirar(fila_t *fila);
int inicio_fila(fila_t *fila);
int fim_fila(fila_t *fila);
int tamanho_fila(fila_t *fila);
int valor_indice_fila(fila_t *fila, int indice);

/*===== LISTA =====*/
typedef struct lista lista_linear_t;

lista_linear_t *criar_lista_linear(int capacidade, int ordenada);
int lista_linear_cheia(lista_linear_t *lista);
int lista_linear_vazia(lista_linear_t *lista);
int buscar_lista_linear(lista_linear_t *lista, int elemento);
int inserir_lista_linear(lista_linear_t *lista, int elemento);
int remover_lista_linear(lista_linear_t *lista, int valor);
int valor_indice_lista_linear(lista_linear_t *lista, int indice);
int tamanho_lista_linear(lista_linear_t *lista);
int destruir_lista_linear(lista_linear_t *lista);

/*===== LISTA ENCADEADA =====*/
typedef struct no no_t;

no_t *criar_lista_encadeada(int valor);
void inserir_encadeada(no_t **inicio, int valor);
int remover_encadeada(no_t **inicio, int valor);
no_t *buscar_encadeada(no_t **inicio, int valor);
int valor_indice_encadeada(no_t **inicio, int indice);
int tamanho_encadeada(no_t **inicio);
void destruir_encadeada(no_t **inicio);

/*===== LISTA ENCADEADA DUPLA =====*/
typedef struct nod nod_t;

nod_t *criar_lista_encadeada_dupla(int valor);
void inserir_encadeada_dupla(nod_t **inicio, int valor);
nod_t *buscar_encadeada_dupla(nod_t **inicio, int valor);
int remover_encadeada_dupla(nod_t **inicio, int valor);
void destruir_encadeada_dupla(nod_t **inicio);

/*===== ALGORITMOS DE ORDENAÇÃO =====*/

void bubble_sort(int vetor[], int tamanho);
int *insertion_sort(int *vetor, int tamanho);
int *selection_sort(int *vetor, int tamanho);

#endif
