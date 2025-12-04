#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordena.h"

void embaralharVetor(int *dados,int tam){
    int i, j, temp;
    for(i = 0; i < tam; i++){
        j = rand() % (i + 1);
        temp = dados[i]; // temp armazena um valor
        dados[i] = dados[j]; // copia um valor de outra posição
        dados[j] = temp; // salva o tempo na posição usada para a capia
    }
}

int inserirVetor(int *dados, int tam){
    int i;
    for(i = 0; i < tam; i++) dados[i] = i + 1;  // Gera um velor com valores entre 0 a tam N
    embaralharVetor(dados, tam); // chama a função para aleatorizar
    return *(dados);
}

void listarVetor(int *dados, int tam){
    int i;
    printf("+====VETOR====\n");
    for(i =0; i < tam; i++){
        printf("[%d] ", dados[i]);
    }
}

int main(){
    int i, tam;
    
    /* Variaveis de tempo */
    clock_t inicio, fim;
    double tempo;
    
    srand(time(NULL)); // Semente

    printf("====COMPARAÇÃO DE ORDENAÇÕES====\n");
    printf("|= Informe o tamanho do vetor(max 1M): ");
    scanf("%d", &tam);
    int dados[tam], vetMerge[tam], aux[tam], vetQuick[tam], vetBubble[tam];

    *dados = inserirVetor(dados, tam);
    
    listarVetor(dados, tam);

    for(i = 0; i <  tam; i++){
        vetBubble[i] = dados[i];
        vetMerge[i] = dados[i];
        vetQuick[i] = dados[i];
    }
        
    inicio = clock();
    mergeSort(vetMerge, aux, 0, tam - 1);
    fim = clock();
    tempo= ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nTempo do Merge: %f segundos\n", tempo);

    inicio = clock();
    quicksort(vetQuick, 0, tam - 1);
    fim = clock();
    tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nTempo do Quick: %f segundos\n", tempo);

    inicio = clock();
    bubbleSort(vetBubble, tam -1 );
    fim = clock();
    tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nTempo do Bubble: %f segundos\n", tempo);
    
	return 0;
}