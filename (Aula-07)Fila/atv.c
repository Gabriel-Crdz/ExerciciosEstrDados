#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct  elemento{
    int dado;
    struct elemento *prox;
};
typedef struct elemento *ApElemento;

typedef struct{
    ApElemento ini;
    ApElemento fim;
} Fila;
 
Fila criarFila(){
    Fila f;
    f.ini = NULL;
    f.fim = NULL;
    return f;
}

int filaVazia(Fila f){
    if(f.ini == NULL) return TRUE;
    else return FALSE;
}


Fila inserirFila(Fila f, int e){
    ApElemento novo;

    novo = malloc(sizeof(struct elemento));
    novo->dado = e;
    novo->prox = NULL;
    if(filaVazia(f)){
        f.ini = novo;
        f.fim = novo;
    }
    else{
        f.fim->prox = novo;
        f.fim = novo;
    }

    return f;
}

Fila retirarFila(Fila f, int *e){
    ApElemento ap;
    if(!filaVazia(f)){
        *e = f.ini->dado; // Retorna o valor do elemento no inicio da fila
        ap = f.ini; // Salva o endereço do inicio
        f.ini = f.ini->prox; // Faz o inicio apontar para o segundo
        free(ap); // Libera o espaço ocupado pelo elemento removido
        if(filaVazia(f)) f.fim = NULL; // Se retirou o elemento, atualiza o fim
    }
    else{
        *e = -1;
        printf("\n*******************\n");
        printf("AVISO: fila Vazia!!\n");
        printf("*******************\n");
    }
    return f;
}

void imprimirFila(Fila f){
    ApElemento ap;

    printf("+=====ITENS DA FILA=====\n");
    ap = f.ini;
    while(ap != NULL){
        printf("[%d] - ", ap->dado);
        ap = ap->prox;
    }
    if(filaVazia(f)){
		printf("\n*******************\n");
        printf("AVISO: fila Vazia!!\n");
        printf("*******************\n");
	}
    printf("\n");
}

int menu(){
    int opc;
    do{
        printf("+------------MENU------------\n");
        printf("| [1] Inserir na Fila\n");
        printf("| [2] Retirar da Fila\n");
        printf("| [3] Imprimir Fila\n");
        printf("| [0] Sair\n");
        printf("|............................\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);
        getchar();
        
        if(opc < 0 || opc > 3){
            printf("\n************************\n");
            printf("ERRO: Entrada Invalida!!\n");
            printf("************************\n\n");
        }
        
    }while(opc < 0 || opc > 3);
    return opc;
}

int main(){
    Fila f;
    int opc, valor;

    f = criarFila();
    
    printf("+=+=FILA DINAMICA=+=+\n");
    do{
        opc = menu();
        system("clear");
        switch (opc){
            case 1:
                printf("+======INSERINDO======\n");
                printf("|= Informe o item a ser inserido: ");
                scanf("%d", &valor);
                f =  inserirFila(f, valor);
            break;
            
            case 2:
                f = retirarFila(f, &valor);
                if(!filaVazia(f)){
                    printf("+==========================+\n");
                    printf("SUCESSO: Elemento removido!!\n");
                    printf("+==========================+\n");
                }
            break;
            case 3:
                imprimirFila(f);
            break;
            case 0: 
                printf("SAINDO...\n");
            break;
        }
    }while(opc != 0);
    return 0;
}
