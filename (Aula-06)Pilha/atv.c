#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct elemento{
    int dado; // Conteúdo (inteiro)
    struct elemento *prox; // Ponteiro para o próximo registro
};

typedef struct elemento *Pilha;

Pilha criaPilha(){ return NULL; }

int pilhaVazia(Pilha p){
    if (p == NULL) return TRUE;
    else return FALSE;
}

Pilha empilhar(Pilha p, int e){
    Pilha novo;

    novo = malloc(sizeof(struct elemento)); // Aloca o espaço
    novo -> dado = e; // Atribui os dados ao novo elemento
    novo -> prox = p; // O próximo do novo é o topo anterior
    return novo;
}

Pilha desempilhar(Pilha p, int *e){
    Pilha ap; // apontador auxiliar
    if (!pilhaVazia(p)){ // se a pilha não for vazia
        *e = p->dado; // Retorna o valor do elemento que está no topo da pilha
        ap = p; // Salva o endereço do topo para liberação
        p = p->prox; // Faz o topo apontar para o próximo elemento
        free(ap); // Libera o espaço ocupado pelo elemento removido
    }
    else{ // Retorna -1 se a pilha estiver vazia
        *e = -1;
        printf("\n********************\n");
        printf("AVISO: Pilha Vazia!!\n");
        printf("********************\n");
    }
    return p;
}

void imprimirPilha(Pilha p){
    Pilha ap; // apontador auxiliar
    ap = p;
    printf("\n-----ELEMENTOS DA PILHA-----\n");
    while (ap != NULL){
        printf("[%d] - ",ap->dado);
        ap = ap->prox;
    }
    printf("\n");
}
int menu(){
    int opc, valor;
    do{
        printf("+------------MENU------------\n");
        printf("| [1] Empilhar elemento\n");
        printf("| [2] Desempilhar elemento\n");
        printf("| [3] Imprimir pilha\n");
        printf("| [0] Sair\n");
        printf("|............................\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);
        getchar();
        
        if(opc < 0 || opc > 4){
            printf("\n************************\n");
            printf("ERRO: Entrada Invalida!!\n");
            printf("************************\n\n");
        }
        
    }while(opc < 0 || opc > 4);
    return opc;
}

int main(){
    Pilha p;
    int opc, valor;
    p = criaPilha();
    printf("=-=PILHA=-=\n");
    do{
        opc = menu();
        system("clear");
        switch (opc){
            case 1: 
                printf("+======INSERINDO======\n");
			    printf("|= Informe o item a ser inserido: ");
                scanf("%d", &valor);
                p = empilhar(p, valor);
            break;
            case 2:
                p = desempilhar(p, &valor);
                if(!pilhaVazia(p)){
                    printf("+==========================+\n");
                    printf("SUCESSO: Elemento removido!!\n");
                    printf("+==========================+\n");
                }
            break;
            case 3:
                imprimirPilha(p);
            break;
            case 0:
                printf("SAINDO...\n");
            break;
        }
    }while(opc != 0); 
}
