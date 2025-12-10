#include "libprg/libprg.h"
#include <stdlib.h>

void merge(int vetor[], int esquerda, int meio, int direita) {
	int *aux = malloc((direita - esquerda + 1) * sizeof(int));

	int i = esquerda,
		j = meio + 1,
		k = 0;

	while (i <= meio && j <= direita) {
		if (vetor[i] <= vetor[j]) {
			aux[k] = vetor[i];
			i++;
		}
		else{
			aux[k] = vetor[j];
			j++;
		}
		k++;
	}

	while (i <= meio) {
		aux[k] = vetor[i];
		i++;
		k++;
	}

	while (j <= direita) {
		aux[k] = vetor[j];
		j++;
		k++;
	}

	for (i = esquerda; i <= direita; i++)
		vetor[i] = aux[i-esquerda];

	free(aux);
}

void merge_sort(int vetor[], int esquerda, int direita) {
	if (esquerda < direita) {
		int meio = esquerda + (direita - esquerda)/2;

		merge_sort(vetor, esquerda, meio);
		merge_sort(vetor, meio + 1, direita);

		merge(vetor, esquerda, meio, direita);
	}
}

void trocar_posicao(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

int particiona(int vetor[], int inicio, int fim) {
	int pivo = vetor[fim],
		i = inicio - 1;

	for (int j = inicio; j <= fim-1; j++) {
		if (vetor[j] <= pivo) {
			i++;
			trocar_posicao(&vetor[i],&vetor[j]);
		}
	}
	i++;
	trocar_posicao(&vetor[i],&vetor[fim]);
	return i;
}

void quicksort(int vetor[], int inicio, int fim) {
	if (inicio < fim) {
		int pivo = particiona(vetor,inicio,fim);

		quicksort(vetor,inicio,pivo-1);
		quicksort(vetor,pivo+1,fim);
	}
}
