#include <stdio.h>
#define TAM 10

/*
* Busca sequencial de um valor inteiro em um vetor vet
* inicio é o índice de vet do inicio da busca
* fim é o índice de vet do final da busca
*/
int buscaBin(int *vet, int inicio, int fim, int valor){
    int meio;
    int pos = -1;

    if(inicio > fim) pos = -1; // Se o início passou do fim, não achou
    else{
        meio = (inicio + fim) / 2; // Calcula a posição do meio do vetor

        if (valor == vet[meio]) pos = meio; // Encontrou elemento, retorna posição
        else if (valor > vet[meio]) pos = buscaBin(vet, meio + 1, fim, valor); // Procura no segundo subvetor
        else pos = buscaBin(vet, inicio, meio - 1, valor); // Procura no primeiro subvetor
    }

    return (pos); // Retorna o índice de vet onde valor foi encontrado, ou -1 se não encontrado
}

int main(){
    int i, valor, dados[TAM], pos;

    for(i = 0; i < TAM; i++){
        printf("Informe o %dº elemento: ", i+1);
        scanf("%d", &dados[i]);
    }

    printf("\nInforme o valor buscado: ");
    scanf("%d", &valor);
    pos = buscaBin(dados, 0, TAM, valor);

    printf("RESULTADO:\n");
    if(pos == -1){ // Se o pos e -1, o valor nao foi encontrado
        printf("Valor não encontrado!!");
    }
    else{ // Se nao diz sua posição
        printf("Valor localizado na posição: %d\n", pos);
    }
    return 0;
}
