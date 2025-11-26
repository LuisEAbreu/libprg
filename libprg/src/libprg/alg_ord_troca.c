#include "libprg/libprg.h"

void bubble_sort(int vetor[], int n) {
	for (int i=0; i < n; i++) {
		for (int j=0; j < n-1-i; j++) {
			if (vetor[j] < vetor[j+1]) {
				int aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
		}
	}
}

void insertion_sort(int vetor[], int n) {
	for (int i=1; i < n; i++) {
		int chave = vetor[i],
			j = i-1;

		while (j>=0 && vetor[j] > chave) {
			vetor[j+1] = vetor[j];
			j = j-1;
		}
		vetor[j+1] = chave;
	}
}

void selection_sort(int vetor[], int n) {
	for (int i=0; i < n-1; i++) {
		int minimo = i;

		for (int j=i+1; j < n; j++) {
			if (vetor[j] < vetor[minimo])
				minimo = j;
		}
		if (i!=minimo) {
			int aux = vetor[i];
			vetor[i] = vetor[minimo];
			vetor[minimo] = aux;
		}
	}
}