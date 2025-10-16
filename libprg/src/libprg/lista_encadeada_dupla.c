#include <stdlib.h>

typedef struct no_duplo {
    struct no_duplo* anterior;
    int valor;
    struct no_duplo* proximo;
}no_duplo_t;

no_duplo_t *criar_lista_encadeada_dupla(int valor) {
    no_duplo_t *no_duplo = malloc(sizeof(no_duplo_t));
    no_duplo->valor = valor;
    no_duplo->proximo = NULL;
    no_duplo->anterior = NULL;

    return no_duplo;
}

void adicionar_no_duplo(no_duplo_t **inicio, int valor) {
    no_duplo_t *novo_no = criar_lista_encadeada_dupla(valor);
    novo_no->proximo = *inicio;
    (*inicio)->anterior = novo_no;
    *inicio = novo_no;

}