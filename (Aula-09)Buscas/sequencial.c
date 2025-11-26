#include <stdio.h>
#define TAM 10

/* 
* Busca sequencial de um valor em um vetor
* vet é o vetor de inteiros
* tam é o tamanho do vetor
* valor é o número a ser buscado
*/
int buscaSeq(int *dados, int tam, int valor){
    int i= 0, pos = -1;

    /* Usando WHILE */
    // while ((i<tam) && (pos==-1)){
    //     if (valor == vet[i]) pos = i;
    //     i++;
    // }

    /* Usando FOR */
    for(i = 0; i < TAM; i++){
        if(valor == dados[i]){
            pos = i;
            break;
        }
    }
    
    return (pos); // Retorna o índice do vetor onde está o valor, ou -1 se não encontrado
}

int main(){
    int i, dados[TAM], valor, pos;

    for(i = 0; i < TAM; i++){
        printf("Informe o %dº elemento: ", i+1);
        scanf("%d", &dados[i]);
    }

    printf("\nInforme o valor buscado: ");
    scanf("%d", &valor);
    pos = buscaSeq(dados, TAM, valor);

    printf("RESULTADO:\n");
    if(pos == -1){ // Se o pos e -1, o valor nao foi encontrado
        printf("Valor não encontrado!!");
    }
    else{ // Se nao diz sua posição
        printf("Valor localizado na posição: %d\n", pos);
    }
    return 0;
}