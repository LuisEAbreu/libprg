#include <stdlib.h>

typedef struct lista_encadeada_dupla {
    struct lista_encadeada_dupla* anterior;
    int valor;
    struct lista_encadeada_dupla* proximo;
}lista_encadeada_dupla_t;

lista_encadeada_dupla_t *criar_lista_encadeada_dupla(int valor) {
    lista_encadeada_dupla_t *no_duplo = malloc(sizeof(lista_encadeada_dupla_t));
    no_duplo->valor = valor;
    no_duplo->proximo = NULL;
    no_duplo->anterior = NULL;

    return no_duplo;
}

void adicionar_lista_encadeada_dupla(lista_encadeada_dupla_t **inicio, int valor) {
    lista_encadeada_dupla_t *novo_no = criar_lista_encadeada_dupla(valor);
    novo_no->proximo = *inicio;
    (*inicio)->anterior = novo_no;
    *inicio = novo_no;

}

lista_encadeada_dupla_t *buscar_lista_encadeada_dupla(lista_encadeada_dupla_t **inicio, int valor) {
    lista_encadeada_dupla_t *atual = *inicio;

    while (atual) {     // dentro dos parênteses é o equivalente a (atual != NULL)
        if (atual->valor == valor)
            return atual;

        atual = atual->proximo;
    }

    return NULL;
}

void remover_lista_encadeada_dupla(lista_encadeada_dupla_t **inicio, int valor) {
    lista_encadeada_dupla_t *atual = *inicio;

    while (atual) {
        if (atual->valor == valor) {
            if (atual->anterior != NULL) {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
            }
            else {
                *inicio = atual->proximo;
                (*inicio)->anterior = NULL;
            }
            free(atual);
            break;
        }
        atual = atual->proximo;
    }
}

int tamanho_lista_encadeada_dupla(lista_encadeada_dupla_t **inicio) {
    int contador = 0;
    lista_encadeada_dupla_t *atual = *inicio;

    while (atual) {
        contador++;
        atual = atual->proximo;
    }

    return contador;
}

int limitar_posicao_dupla(lista_encadeada_dupla_t **inicio, int posicao) {
    int tamanho = tamanho_lista_encadeada_dupla(inicio);

    if (posicao < 0)
        return 0;

    if (posicao > tamanho)
        return tamanho;

    return posicao;
}

void adicionar_na_posicao_lista_encadeada_dupla(lista_encadeada_dupla_t **inicio, int valor, int posicao) {
    posicao = limitar_posicao_dupla(inicio, posicao);

    lista_encadeada_dupla_t *novo_no = criar_lista_encadeada_dupla(valor);

    if (posicao == 0) {
        if (*inicio != NULL) {
            novo_no->proximo = *inicio;
            (*inicio)->anterior = novo_no;
        }
        *inicio = novo_no;
        return;
    }

    lista_encadeada_dupla_t *atual = *inicio;

    for (int i = 0; i < posicao - 1; i++)
        atual = atual->proximo;

    novo_no->proximo = atual->proximo;
    novo_no->anterior = atual;

    if (atual->proximo)
        atual->proximo->anterior = novo_no;

    atual->proximo = novo_no;
}

void remover_na_posicao_lista_encadeada_dupla(lista_encadeada_dupla_t **inicio, int posicao) {
    int tamanho = tamanho_lista_encadeada_dupla(inicio);

    posicao = limitar_posicao_dupla(inicio, posicao);

    if (posicao == tamanho)
        return;

    lista_encadeada_dupla_t *atual = *inicio;

    if (posicao == 0) {
        *inicio = atual->proximo;
        if (*inicio)
            (*inicio)->anterior = NULL;

        free(atual);
        return;
    }

    for (int i = 0; i < posicao; i++)
        atual = atual->proximo;

    if (atual->anterior)
        atual->anterior->proximo = atual->proximo;

    if (atual->proximo)
        atual->proximo->anterior = atual->anterior;

    free(atual);
}