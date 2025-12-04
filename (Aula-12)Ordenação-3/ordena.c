#include "ordena.h"

#define troca(A, B){int t = A; A = B; B = t; }

/* Ordenação por Bubble */
void bubbleSort(int *vet, int n){
    int i, j, trocou, aux;
    j = 1;
    trocou = 1;  // Sinalizador. Se houve trocas é porque há algo fora de ordem, e precisa continuar
    while ((j < n) && trocou){ // Continua enquanto houve trocas e não esgotou o vetor
        trocou = 0; // Nessa passada não houve trocas
        for (i = 0; i < (n - j); i++){
            if (vet[i] > vet[i + 1]){ // Se o elemento é maior que o próximo, troca
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
                trocou = 1; // Sinaliza que houve uma troca
            }
        }
        j++;
    }
}

/* Ordenação por merge */
void merge(int *dados, int *aux, int esq, int meio, int dir) {
	int l1, l2, i;
	for(l1 = esq, l2 = meio + 1, i = esq; l1 <= meio && l2 <= dir; i++) {
		if(dados[l1] <= dados[l2]) aux[i] = dados[l1++];
		else aux[i] = dados[l2++];
	}
	
	while(l1 <= meio) aux[i++] = dados[l1++]; 
	while(l2 <= dir) aux[i++] = dados[l2++]; 
	for(i = esq; i <= dir; i++) dados[i] = aux[i]; 
}

void mergeSort(int *vet, int *aux, int esq, int dir) {
	int meio;
	if(esq < dir) { 
		meio = (esq + dir) / 2; 
		mergeSort(vet, aux, esq, meio); 
		mergeSort(vet, aux, meio + 1, dir); 
		merge(vet, aux, esq, meio, dir);
	} 
	else return;
}

int particione(int a[], int p, int r){
    int i = p - 1, j = r;
    int v = a[r];
    for (;;){
        while (a[++i] < v);

        while (v < a[--j]) if (/*X*/ j == p) break;
        if (i >= j) break;

        troca(a[i], a[j]);
    }
    troca(a[i], a[r]);
    return i;
}

/* Ordenação por quick */
void quicksort(int a[], int p, int r){
    int i;
    if (p < r){
        i = particione(a, p, r);
        quicksort(a, p, i - 1);
        quicksort(a, i + 1, r);
    }
}