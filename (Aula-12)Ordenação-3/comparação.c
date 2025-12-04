#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordena.h"

void embaralharVetor(int *dados,int tam){
    int i, j, temp;
    for(i = 0; i < tam; i++){
        j = rand() % (i + 1);
        temp = dados[i];
        dados[i] = dados[j];
        dados[j] = temp;
    }
}

int inserirVetor(int *dados, int tam){
    int i;
    for(i = 0; i < tam; i++) dados[i] = i + 1; 
    embaralharVetor(dados, tam);
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
    srand(time(NULL));
    
    /* Variaveis de tempo */
    clock_t inicioMerge, inicioQuick, inicioBubble;
    clock_t fimMerge, fimQuick, fimBubble;

    double tempoMerge, tempoQuick, tempoBubble;

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
        
    inicioMerge = clock();
    mergeSort(vetMerge, aux, 0, tam - 1);
    fimMerge = clock();
    tempoMerge = ((double) (fimMerge - inicioMerge)) / CLOCKS_PER_SEC;
    printf("\nTempo do Merge: %f segundos\n", tempoMerge);

    inicioQuick = clock();
    quicksort(vetQuick, 0, tam - 1);
    fimQuick = clock();
    tempoQuick = ((double) (fimQuick - inicioQuick)) / CLOCKS_PER_SEC;
    printf("\nTempo do Quick: %f segundos\n", tempoQuick);

    inicioBubble = clock();
    bubbleSort(vetBubble, tam -1 );
    fimBubble = clock();
    tempoBubble = ((double) (fimBubble - inicioBubble)) / CLOCKS_PER_SEC;
    printf("\nTempo do Bubble: %f segundos\n", tempoBubble);
	return 0;
}