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
    for (int i = lista->tamanho - 1; i >= 0; i--) {
        if (lista->elementos[i]<valor) {
            lista->elementos[i + 1] = valor;
            break;
        }
        lista->elementos[i + 1] = lista->elementos[i];
    }
    lista->tamanho++;
}

void inserir_nao_ordenada(lista_linear_t *lista, int valor) {
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}

void inserir(lista_linear_t *lista, int valor) {
    if (lista_linear_cheia(lista))
        exit(EXIT_FAILURE);
    if (lista->ordenada)
        inserir_ordenada(lista, valor);
    else
        inserir_nao_ordenada(lista, valor);
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
            fim = meio - 1;
        else
            inicio = meio + 1;
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
        exit(EXIT_FAILURE);

    if (lista->ordenada)
        return busca_binaria(lista, valor);

    return busca_linear(lista, valor);
}

int remover_da_lista(lista_linear_t *lista, int valor) {
    if (lista_linear_vazia(lista))
        exit(EXIT_FAILURE);

    int indice = buscar_na_lista(lista, valor);

    if (indice!=-1) {
        lista->elementos[indice] = lista->elementos[lista->tamanho - 1];
        lista->tamanho--;
        return 0;
    }
    return -1;
}

void destruir_lista(lista_linear_t *lista){
    free(lista->elementos);
    free(lista);
}