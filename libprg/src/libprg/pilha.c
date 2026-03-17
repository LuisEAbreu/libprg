#include <stdlib.h>

typedef struct pilha {
    int *elementos;
    int capacidade;
    int topo;
} pilha_t;