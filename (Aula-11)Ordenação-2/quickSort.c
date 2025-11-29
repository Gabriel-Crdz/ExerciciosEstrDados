#include <stdio.h>
#include <stdlib.h>
#define troca(A, B){int t = A; A = B; B = t; }
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

/* Recebe vetor a[p..r] com p < r. Rearranja os elementos do vetor 
e devolve i em p..r tal que a[p..i-1] <= a[i] <= a[i+1..r]. */
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

/* A função rearranja o vetor a[p..r], com p <= r+1,
de modo que ele fique em ordem crescente. */
void quicksort(int a[], int p, int r){
    int i;
    if (p < r){
        i = particione(a, p, r);
        quicksort(a, p, i - 1);
        quicksort(a, i + 1, r);
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
    printf("====ORDENAÇÃO QUICK SORT====\n");
    *dados = inserirVetor(dados);
    do{
        opc = menu();
        system("clear");
        switch(opc){
            case 1: *dados = inserirVetor(dados);
            break;
            case 2: quicksort(dados, 0, TAM - 1);
                printf("\n************************\n");
                printf("SUCESSO: vetor ordenado!\n");
                printf("************************\n");
            break;
            case 3: listarVetor(dados);
        }
    }while(opc != 0);
	return 0;
}