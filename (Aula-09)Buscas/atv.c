#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int inserirVetor(int *dados, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("Informe o %dº elemento: ", i+1);
        scanf("%d", &dados[i]);
    }
    printf("\n=====SEU VETOR=====\n");
    for(i = 0; i < tam; i++){
        printf("[%d] ", i+1);
    }
    printf("\n");
    return *(dados);
}

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

int menu(){
    int opc;
    do{
        printf("\n+----------MENU----------\n");
        printf("| [1] Inserir novo Vetor\n");
        printf("| [2] Busca Squencial\n");
        printf("| [3] Busca Binaria\n");
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
    int i, opc, dados[TAM], valor, pos;
    printf("====BUSCAS EM VETORES====\n");
    *dados = inserirVetor(dados, TAM);
    do{
        opc = menu();
        system("clear");
        switch(opc){
            case 1: 
            *dados = inserirVetor(dados, TAM);
            break;
            case 2: 
                printf("+===SEQUENCIAL===\n");
                printf("| Informe o valor buscado: ");
                scanf("%d", &valor);
                pos = buscaSeq(dados, TAM, valor);
                printf("RESULTADO:\n");
                if(pos != 1) printf("Elemento encontrado na posição: %d", pos+1);
                else printf("Elemento não encontrado!!\n");
            break;
            case 3: 
		printf("+===BINARIA===\n");
                printf("| Informe o valor buscado: ");
                scanf("%d", &valor);
                pos = buscaBin(dados, 0, TAM, valor);
                printf("RESULTADO:\n");
                if(pos != 1) printf("Elemento encontrado na posição: %d", pos+1);
                else printf("Elemento não encontrado ou vetor não ordenado!!");
            break;
            default: printf("SAINDO...");
            break;
        }
    }while(opc != 0);
    return 0;
}
