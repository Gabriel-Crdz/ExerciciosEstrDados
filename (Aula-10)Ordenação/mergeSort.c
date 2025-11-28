#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int inserirVetor(int *dados, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("Informe o %dº elemento: ", i+1);
        scanf("%d", &dados[i]);
    }
    printf("\n");
    return *(dados);
}
/* 
    Intercala dois subvetores do vetor vet no vetor aux.
    O primeiro subvetor inicia na posição esq, e vai até meio
    O segundo subvetor inicia na posição meio+1 e vai até dir 
*/
void merge(int *vet, int *aux, int esq, int meio, int dir) {
	int l1, l2, i;
	/* Percorre os dois subvetores, comparando os elementos.
 	Escolhe o menor elemento para mover para o vetor auxiliar, até acabar um dos vetores */
	for(l1 = esq, l2 = meio + 1, i = esq; l1 <= meio && l2 <= dir; i++) {
		if(vet[l1] <= vet[l2]) aux[i] = vet[l1++];
		else aux[i] = vet[l2++];
	}
	
	// Quando encerrou o for, é porque um dos subvetores a ou b chegou ao fim
	while(l1 <= meio) aux[i++] = vet[l1++]; // Se houver dados restantes no primeiro subvetor, copia

	while(l2 <= dir) aux[i++] = vet[l2++]; // Se houver dados restantes no segundo subvetor, copia
	
	for(i = esq; i <= dir; i++) vet[i] = aux[i]; // Move os dados do vetor auxiliar novamente para o vetor original
}

void mergeSort(int *vet, int *aux, int esq, int dir) {
	int meio;
	if(esq < dir) { // Só continua se o vetor tem pelo menos 2 elementos
		meio = (esq + dir) / 2; // Divide o vetor ao meio
		mergeSort(vet, aux, esq, meio); // Ordena por mergeSort a primeira metade
		mergeSort(vet, aux, meio + 1, dir); // Ordena por mergeSort a segunda metade
		merge(vet, aux, esq, meio, dir); // Intercala os dois subvetores
	} 
	else return;
}

int menu(){
    int opc;
    do{
        printf("\n+----------MENU----------\n");
        printf("| [1] Inserir novo Vetor\n");
        printf("| [2] Ordenar Vetor\n");
        printf("| [3] Listar vetor\n");
        printf("| [0] Sair\n");
        printf("|........................\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);
        getchar();
        
        if(opc < 0 || opc > 3){
            printf("\n************************\n");
            printf("ERRO: Entrada Invalida!!\n");
            printf("************************\n\n");
        }
    } while (opc < 0 || opc > 3);
    
    return opc;
}

int main(){
    int i, dados[TAM], aux[TAM];
    printf("====ORDENAÇÃO MERGE SORT====\n");
    *dados = inserirVetor(dados, TAM);
    do{
        opc = menu();
        system("clear");
        switch(opc){
            case 1: *dados = inserirVetor(dados, TAM);
            break;
            case 2: mergeSort(dados, aux, 0, TAM);
        }
    }while(opc != 0);
	return 0;
}
