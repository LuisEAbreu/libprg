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