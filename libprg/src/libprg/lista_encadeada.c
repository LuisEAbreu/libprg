#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"

typedef struct lista_encadeada {
    int valor;
    struct lista_encadeada *proximo;
}lista_encadeada_t;

lista_encadeada_t *criar_lista_encadeada(int valor) {
    lista_encadeada_t *no = malloc(sizeof(lista_encadeada_t));
    no->valor = valor;
    no->proximo = NULL;

    return no;
}

lista_encadeada_t *criar_lista_encadeada_circular(int valor) {
    lista_encadeada_t *no = malloc(sizeof(lista_encadeada_t));
    no->valor = valor;
    no->proximo = no;

    return no;
}

void adicionar_lista_encadeada(lista_encadeada_t **inicio, int valor) {
    lista_encadeada_t *novo_no = criar_lista_encadeada(valor);
    novo_no->proximo = *inicio;
    *inicio = novo_no;
}

void adicionar_lista_encadeada_circular(lista_encadeada_t **inicio, int valor) {
    lista_encadeada_t *novo_no = criar_lista_encadeada_circular(valor);
    novo_no->proximo = *inicio;

    lista_encadeada_t *ultimo = *inicio;

    while (ultimo->proximo != *inicio)
        ultimo = ultimo->proximo;

    ultimo->proximo = novo_no;
}

lista_encadeada_t *buscar_lista_encadeada(lista_encadeada_t **inicio, int valor) {
    lista_encadeada_t *atual = *inicio;

    while (atual) {     // dentro dos parênteses é o equivalente a (atual != NULL)
        if (atual->valor == valor)
            return atual;

        atual = atual->proximo;
    }

    return NULL;
}

void remover_lista_encadeada(lista_encadeada_t **inicio, int valor) {
    lista_encadeada_t *atual = *inicio;
    lista_encadeada_t *anterior = NULL;

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

void destruir_lista_encadeada(lista_encadeada_t **inicio) {
    lista_encadeada_t *atual = *inicio;

    while (atual) {
        lista_encadeada_t *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

void destruir_lista_encadeada_circular(lista_encadeada_t **inicio) {
    lista_encadeada_t *atual = *inicio;

    while (atual) {
        lista_encadeada_t *proximo = atual->proximo;
        free(atual);
        if (proximo==*inicio)
            break;
        atual = proximo;
    }
}

int elemento_da_lista_encadeada(lista_encadeada_t **inicio, int indice) {
    lista_encadeada_t *atual = *inicio;
    int contador = 0;

    while (atual) {
        if (contador == indice)
            return atual->valor;

        atual = atual->proximo;
        contador++;
    }
    return -1;
}

int tamanho_da_lista_encadeada(lista_encadeada_t **inicio) {
    lista_encadeada_t *atual = *inicio;
    int contador = 0;

    while (atual) {
        atual = atual->proximo;
        contador++;
    }
    return contador;
}

int limitar_posicao_encadeada(lista_encadeada_t **inicio, int indice) {
    int tamanho = tamanho_da_lista_encadeada(inicio);

    if (indice < 0)
        return 0;

    if (indice > tamanho)
        return tamanho;

    return indice;
}

void inserir_na_posicao_da_lista_encadeada(lista_encadeada_t **inicio, int valor, int indice) {
    int posicao = limitar_posicao_encadeada(inicio, indice);

    if (posicao==0) {
        adicionar_lista_encadeada(inicio,valor);
        return;
    }
    lista_encadeada_t *atual = *inicio;

    for (int i = 0; i < posicao-1; i++)
        atual = atual->proximo;

    lista_encadeada_t *novo_no = criar_lista_encadeada(valor);
    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
}

int remover_na_posicao_da_lista_encadeada(lista_encadeada_t **inicio, int indice) {
    int posicao = limitar_posicao_encadeada(inicio, indice);

    if (*inicio == NULL)
        return -1;

    lista_encadeada_t *atual = *inicio;

    for (int i = 0; i < posicao; i++)
        atual = atual->proximo;

    if (atual != NULL) {
        int valor = atual->valor;
        remover_lista_encadeada(inicio, valor);
        return valor;
    }

    return -1;
}

int tamanho_da_lista_circular(lista_encadeada_t **inicio) {
    if (*inicio == NULL)
        return 0;

    int contador = 1;
    lista_encadeada_t *atual = (*inicio)->proximo;

    while (atual != *inicio) {
        contador++;
        atual = atual->proximo;
    }

    return contador;
}

int limitar_posicao_circular(lista_encadeada_t **inicio, int indice) {
    int tamanho = tamanho_da_lista_circular(inicio);

    if (indice < 0)
        return 0;

    if (indice > tamanho)
        return tamanho;

    return indice;
}

void inserir_na_posicao_lista_encadeada_circular(lista_encadeada_t **inicio, int valor, int indice) {
    int posicao = limitar_posicao_circular(inicio, indice);

    if (*inicio == NULL) {
        *inicio = criar_lista_encadeada_circular(valor);
        return;
    }

    lista_encadeada_t *aux = criar_lista_encadeada(valor);

    if (posicao == 0) {
        lista_encadeada_t *ultimo = *inicio;

        while (ultimo->proximo != *inicio)
            ultimo = ultimo->proximo;

        aux->proximo = *inicio;
        *inicio = aux;
        ultimo->proximo = aux;
        return;
    }
    lista_encadeada_t *atual = *inicio;

    for (int i = 0; i < posicao - 1; i++)
        atual = atual->proximo;

    aux->proximo = atual->proximo;
    atual->proximo = aux;
}