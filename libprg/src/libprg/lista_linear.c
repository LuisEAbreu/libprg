#include <stdbool.h>
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct lista_linear {
    int *elementos,
        tamanho,
        capacidade;
    bool ordenada;
}lista_linear_t;

lista_linear_t *criar_lista_linear(int capacidade, bool ordenada) {
    lista_linear_t *lista = malloc(sizeof(lista_linear_t));
    lista->elementos = malloc(sizeof(int)*capacidade);
    lista->tamanho = 0;
    lista->capacidade = capacidade;
    lista->ordenada = ordenada;

    return lista;
}

bool lista_linear_cheia(lista_linear_t *lista) {
    return lista->tamanho >= lista->capacidade;
}

void inserir_ordenada(lista_linear_t *lista, int valor) {
    int i;
    for (i = lista->tamanho - 1; i >= 0; i--) {
        if (lista->elementos[i] < valor) {
            lista->elementos[i + 1] = valor;
            break;
        }
        lista->elementos[i + 1] = lista->elementos[i];
    }
    if (i < 0)
        lista->elementos[0] = valor;

    lista->tamanho++;
}

void inserir_nao_ordenada(lista_linear_t *lista, int valor) {
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}

int inserir(lista_linear_t *lista, int valor) {
    if (lista_linear_cheia(lista))
        return -1;
    if (lista->ordenada)
        inserir_ordenada(lista, valor);
    else
        inserir_nao_ordenada(lista, valor);
    return 0;
}

bool lista_linear_vazia(lista_linear_t *lista) {
    return lista->tamanho <= 0;
}

int busca_binaria(lista_linear_t *lista, int valor) {
    int inicio = 0,
        fim = lista->tamanho - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (lista->elementos[meio] == valor)
            return meio;
        else if (lista->elementos[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

int busca_linear(lista_linear_t *lista, int valor) {
    int indice=0;

    while (indice < lista->tamanho) {
        if (lista->elementos[indice] == valor)
            return indice;
        indice++;
    }
    return -1;
}

int buscar_na_lista(lista_linear_t *lista, int valor) {
    if (lista_linear_vazia(lista))
        return -1;

    if (lista->ordenada)
        return busca_binaria(lista, valor);

    return busca_linear(lista, valor);
}

int remover_nao_ordenada(lista_linear_t *lista, int valor) {
    int indice = buscar_na_lista(lista, valor);

    if (indice!=-1) {
        lista->elementos[indice] = lista->elementos[lista->tamanho - 1];
        lista->tamanho--;
        return 0;
    }
    return -1;
}

int remover_ordenada(lista_linear_t *lista, int valor) {
    int indice = buscar_na_lista(lista, valor);

    if (indice!=-1) {
        for (int i=indice; i<lista->tamanho-1; i++)
            lista->elementos[i] = lista->elementos[i+1];

        lista->tamanho--;
        return 0;
    }
    return -1;
}

int remover_da_lista(lista_linear_t *lista, int valor) {
    if (lista_linear_vazia(lista))
        return -1;

    if (lista->ordenada)
        return remover_ordenada(lista, valor);

    return remover_nao_ordenada(lista, valor);
}

void destruir_lista(lista_linear_t *lista){
    free(lista->elementos);
    free(lista);
}

int elemento_da_lista(lista_linear_t *lista, int indice) {
    return lista->elementos[indice];
}

int inserir_na_posicao_da_lista(lista_linear_t *lista, int valor, int indice) {
    if (indice > lista->tamanho)
        indice = lista->tamanho;

    inserir(lista, valor);
    lista->elementos[indice] = valor;

    return 0;
}

int tamanho_da_lista(lista_linear_t *lista) {
    return lista->tamanho;
}