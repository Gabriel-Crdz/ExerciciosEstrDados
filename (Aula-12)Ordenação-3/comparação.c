#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define troca(A, B){int t = A; A = B; B = t; }
#define TAM_VET 100000000

// Função para verificar se um número já existe no vetor
int existeNoVetor(int dados[], int tamAtual, int novo) {
    for (int i = 0; i < tamAtual; i++) {
        if(dados[i] == novo) {
            return 0; // Número encontrado, é repetido
        }
    }
    return 1; // Número não encontrado, é único
}

int inserirVetor(int *dados, int tam){
    int i, num, tamAtual = 0;
    for(i = 0; i < tam; i++){
        num = rand() % tam;
        if(!existeNoVetor(dados, tamAtual, num)) dados[i] = num;
        tamAtual++;
    }
    printf("\n");
    return *(dados);
}

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