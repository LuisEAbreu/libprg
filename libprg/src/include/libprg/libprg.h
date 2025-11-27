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
int enfileirar(fila_t *fila, int valor);
bool fila_cheia(fila_t *fila);
bool fila_vazia(fila_t *fila);
int desenfileirar(fila_t *fila);
int inicio_da_fila(fila_t *fila);
int fim_da_fila(fila_t *fila);
int tamanho_da_fila(fila_t *fila);
void destruir_fila(fila_t *fila);

/*--LISTA LINEAR--*/
typedef struct lista_linear lista_linear_t;

lista_linear_t *criar_lista_linear(int capacidade, bool ordenada);
bool lista_linear_cheia(lista_linear_t *lista);
int inserir(lista_linear_t *lista, int valor);
bool lista_linear_vazia(lista_linear_t *lista);
int buscar_na_lista(lista_linear_t *lista, int valor);
int remover_da_lista(lista_linear_t *lista, int valor);
int limitar_posicao(lista_linear_t *lista, int indice);
int remover_na_posicao_da_lista(lista_linear_t *lista, int indice);
void destruir_lista(lista_linear_t *lista);
int elemento_da_lista(lista_linear_t *lista, int indice);
int inserir_na_posicao_da_lista(lista_linear_t *lista, int valor, int indice);
int tamanho_da_lista(lista_linear_t *lista);

/*--LISTA ENCADEADA--*/
typedef struct lista_encadeada lista_encadeada_t;

lista_encadeada_t *criar_lista_encadeada(int valor);
void adicionar_lista_encadeada(lista_encadeada_t **inicio, int valor);
lista_encadeada_t *buscar_lista_encadeada(lista_encadeada_t **inicio, int valor);
void remover_lista_encadeada(lista_encadeada_t **inicio, int valor);
void destruir_lista_encadeada(lista_encadeada_t **inicio);
int elemento_da_lista_encadeada(lista_encadeada_t **inicio, int indice);
int tamanho_da_lista_encadeada(lista_encadeada_t **inicio);

/*--LISTA ENCADEADA CIRCULAR--*/

lista_encadeada_t *criar_lista_encadeada_circular(int valor);
void adicionar_lista_encadeada_circular(lista_encadeada_t **inicio, int valor);
void destruir_lista_encadeada_circular(lista_encadeada_t **inicio);

/*--LISTA ENCADEADA DUPLA--*/
typedef struct lista_encadeada_dupla lista_encadeada_dupla_t;

lista_encadeada_dupla_t *criar_lista_encadeada_dupla(int valor);
void adicionar_lista_encadeada_dupla(lista_encadeada_dupla_t **inicio, int valor);
lista_encadeada_dupla_t *buscar_lista_encadeada_dupla(lista_encadeada_dupla_t **inicio, int valor);
void remover_lista_encadeada_dupla(lista_encadeada_dupla_t **inicio, int valor);

/*--ALGORITMOS DE ORDENAÇÃO (TROCA E SELEÇÃO)--*/

void bubble_sort(int vetor[], int n);
void insertion_sort(int vetor[], int n);
void selection_sort(int vetor[], int n);

/*--ALGORITMOS DE ORDENAÇÃO (DIVISÃO E CONQUISTA)--*/


/*--ÁRVORE DE BUSCA BINÁRIA--*/
typedef struct no no_t;

no_t *criar_no(int valor);
void destruir_no(no_t *no);
no_t *inserir_valor(no_t *raiz, int valor);
bool buscar_no(no_t *raiz, int valor);
no_t *remover_valor(no_t *raiz, int valor);

/*--ÁRVORE DE BUSCA BINÁRIA BALANCEADA--*/
typedef struct no_avl no_avl_t;
int altura_avl(no_avl_t *v);
int fator_balanceamento_avl(no_avl_t *v);

#endif