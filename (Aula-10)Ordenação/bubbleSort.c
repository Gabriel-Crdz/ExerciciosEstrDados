#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int inserirVetor(int *dados){
    int i;
    for(i = 0; i < TAM; i++){
        printf("Informe o %dº elemento: ", i+1);
        scanf("%d", &dados[i]);
    }
    printf("\n");
    return *(dados);
}

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

void listarVetor(int *dados){
    int i;
    printf("+====VETOR====\n");
    for(i =0; i < TAM; i++){
        printf("|= %i - [%d]\n", i+1, dados[i]);
    }
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
    int i, opc, dados[TAM], aux[TAM];
    printf("====ORDENAÇÃO BUBBLE SORT====\n");
    *dados = inserirVetor(dados);
    do{
        opc = menu();
        system("clear");
        switch(opc){
            case 1: *dados = inserirVetor(dados);
            break;
            case 2: bubbleSort(dados, TAM);
                printf("\n************************\n");
                printf("SUCESSO: vetor ordenado!\n");
                printf("************************\n");
            break;
            case 3: listarVetor(dados);
        }
    }while(opc != 0);
	return 0;
}