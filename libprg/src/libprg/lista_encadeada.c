#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"

typedef struct no {
    int valor;
    struct no *proximo;
}no_t;

no_t *criar_lista_encadeada(int valor) {
    no_t *no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = NULL;

    return no;
}

no_t *criar_lista_encadeada_circular(int valor) {
    no_t *no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = no;

    return no;
}

void adicionar_lista_encadeada(no_t **inicio, int valor) {
    no_t *novo_no = criar_lista_encadeada(valor);
    novo_no->proximo = *inicio;
    *inicio = novo_no;
}

void adicionar_lista_encadeada_circular(no_t **inicio, int valor) {
    no_t *novo_no = criar_lista_encadeada_circular(valor);
    novo_no->proximo = *inicio;

    no_t *ultimo = *inicio;

    while (ultimo->proximo != *inicio)
        ultimo = ultimo->proximo;

    ultimo->proximo = novo_no;
}

no_t *buscar_lista_encadeada(no_t **inicio, int valor) {
    no_t *atual = *inicio;

    while (atual) {     // dentro dos parênteses é o equivalente a (atual != NULL)
        if (atual->valor == valor)
            return atual;

        atual = atual->proximo;
    }

    return NULL;
}

void remover_lista_encadeada(no_t **inicio, int valor) {
    no_t *atual = *inicio;
    no_t *anterior = NULL;

    while (atual) {
        if (atual->valor == valor) {
            if (anterior)   // (anterior != NULL)
                anterior->proximo = atual->proximo;
            else
                *inicio = atual->proximo;

            free(atual);
            break;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void destruir_lista_encadeada(no_t **inicio) {
    no_t *atual = *inicio;

    while (atual) {
        no_t *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

void destruir_lista_encadeada_circular(no_t **inicio) {
    no_t *atual = *inicio;

    while (atual) {
        no_t *proximo = atual->proximo;
        free(atual);
        if (proximo==*inicio)
            break;
        atual = proximo;
    }
}

int elemento_da_lista_encadeada(no_t **inicio, int indice) {
    no_t *atual = *inicio;
    int contador = 0;

    while (atual) {
        if (contador == indice)
            return atual->valor;

        atual = atual->proximo;
        contador++;
    }
    return -1;
}

int tamanho_da_lista_encadeada(no_t **inicio) {
    no_t *atual = *inicio;
    int contador = 0;

    while (atual) {
        atual = atual->proximo;
        contador++;
    }
    return contador;
}

int limitar_posicao_encadeada(no_t **inicio, int indice) {
    int tamanho = tamanho_da_lista_encadeada(inicio);

    if (indice < 0)
        return 0;

    if (indice > tamanho)
        return tamanho;

    return indice;
}

void inserir_na_posicao_da_lista_encadeada(no_t **inicio, int valor, int indice) {
    int posicao = limitar_posicao_encadeada(inicio, indice);

    if (posicao==0) {
        adicionar_lista_encadeada(inicio,valor);
        return;
    }
    no_t *atual = *inicio;

    for (int i = 0; i < posicao-1; i++)
        atual = atual->proximo;

    no_t *novo_no = criar_lista_encadeada(valor);
    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
}

int remover_na_posicao_da_lista_encadeada(no_t **inicio, int indice) {
    int posicao = limitar_posicao_encadeada(inicio, indice);

    if (*inicio == NULL)
        return -1;

    no_t *atual = *inicio;

    for (int i = 0; i < posicao; i++)
        atual = atual->proximo;

    if (atual != NULL) {
        int valor = atual->valor;
        remover_lista_encadeada(inicio, valor);
        return valor;
    }

    return -1;
}