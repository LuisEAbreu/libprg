#include "libprg/libprg.h"

int *bubble_sort(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho - i - 1 ; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int *insertion_sort(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int chave = vetor[i];
        int j = i + 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}