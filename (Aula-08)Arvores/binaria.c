#include <stdio.h>
#include <stdlib.h>

/* Declaração do Elemento */
struct elemento{
    int dado;
    struct elemento *esq;
    struct elemento *dir;

};
typedef struct elemento *arvore; // Declaração da arvore

arvore criarArvore(){
    return NULL;
}

void inserirArvore(arvore *a, int valor){
    
    if((*a) == NULL){ // Se arvore binaria é vazia
        (*a) = (arvore)malloc(sizeof(struct elemento)); // aloca o espaço para novo registro
        (*a)->dado = valor;
        (*a)->esq = NULL;
        (*a)->dir = NULL;
    }
    /* Se a arvore não esta vazia */
    else if(valor < (*a)->dado) inserirArvore((&(*a)->esq), valor); // Se o valor é menor que a raiz
    else if(valor > (*a)->dado) inserirArvore((&(*a)->dir), valor); // Se o valor é maior que a raiz

    else{
        printf("***************************\n");
        printf("AVISO: valor já existente!!\n");
        printf("***************************\n");
    }
}

void antecessor(arvore a, arvore *x){
    arvore aux;

    if((*x)->dir != NULL) antecessor(a, &((*x)->dir)); // *x tem filho na direita, logo não é o maior
    else{ // *x não tem filho na direita, logo é o substituto
        a->dado = (*x)->dado; // Move dado substituto para o retirado
        aux = *x; // Promove o filho da esquerda do substituto
        *x = aux->esq;
        free(aux); // Libera o espaço usado pelo substituto
    }
}

void retirarArvore(arvore *a, int valor){
    arvore aux; // Ponteiro auxiliar
    if(*a != NULL){ // Arvore não nula
        if(valor > ((*a)->dado)) retirarArvore(&((*a)->dir), valor); // Retira da sub-arvore da direita
        else if (valor < ((*a)->dado)) retirarArvore(&((*a)->esq), valor); // Retira da sub-arvore da esquerda
        else{ // Achou o elemento para remover
            if((*a)->dir == NULL){ // Elemento não tem filho na direita
                aux = (*a);
                *a = aux->esq;
                free(aux);
            }
            else if((*a)->esq == NULL){
                aux = (*a)->dir;
                free(*a);
                *a = aux;
            }
            else antecessor(*a, &((*a)->esq));
        }
    }
}

arvore buscarArvore(arvore a, int valor){
    if(a == NULL) return NULL; // Arvore vazia, elemento não existe, retorna NULL

    else if(valor < a->dado) return buscarArvore(a->esq, valor); // Se menor que a raiz, busca à esquerda
    else if(valor > a->dado) return buscarArvore(a->dir, valor); // Se maior que a raiz, busca à direita
    else return a; // Encontrou o elemento
}

void preOrdem(arvore a){
    if(a != NULL){
        printf("[%d] ", a->dado);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}

void inOrdemAsc(arvore a){
    if(a != NULL){ // Imprime os elementos em ordem crescente
        inOrdemAsc(a->esq);
        printf("[%d] ", a->dado);
        inOrdemAsc(a->dir);
    }
}

void inOrdemDesc(arvore a){
    if(a != NULL){
        inOrdemDesc(a->dir);
        printf("[%d] ", a->dado);
        inOrdemDesc(a->esq);
    }
}


void posOrdem(arvore a){ // Imprime os elementos em ordem decrescente
    if(a != NULL){
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("[%d] ", a->dado);
    }
}

int menu(){
    int opc;
    do{
        printf("\n+------------MENU------------\n");
        printf("| [1] Inserir na Arvore\n");
        printf("| [2] Retirar da Arvore\n");
        printf("| [3] Buscar na Arvore\n");
        printf("| [4] Imprimir pre-Ordem\n");
        printf("| [5] Imprimir in-Ordem crescente\n");
        printf("| [6] Imprimir in-Ordem decrescente\n");
        printf("| [7] Imprimir pós-Ordem\n");
        printf("| [0] Sair\n");
        printf("|............................\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);
        getchar();
        
        if(opc < 0 || opc > 7){
            printf("\n************************\n");
            printf("ERRO: Entrada Invalida!!\n");
            printf("************************\n\n");
        }
        
    }while(opc < 0 || opc > 7);
    return opc;
}

int main(){
    arvore a;
    int opc, valor;

    a = criarArvore();
    
    printf("+=+=+=ARVORE BINARIA=+=+=+\n");
    do{
        opc = menu();
        system("clear");
        switch (opc){
            case 1:
                printf("+======INSERINDO======\n");
                printf("|= Informe o item a ser inserido: ");
                scanf("%d", &valor);
                inserirArvore(&a, valor);
            break;
            
            case 2:
                printf("+======REMOVENDO======\n");
                printf("|= Informe o item a ser retirado: ");
                scanf("%d", &valor);
                retirarArvore(&a, valor);
            break;
            case 3:
                printf("+=====BUSCANDO=====\n");
                printf("|= Informe o elemento a ser buscado: ");
                scanf("%d", &valor);
                a = buscarArvore(a, valor);
                if(a != NULL){
					printf("\n***************************\n");
					printf("Elemento existe na arvore!!\n");
					printf("***************************\n");
				}
                else{
                    printf("\n****************************\n");
					printf("Elemento não esta na arvore!\n");
					printf("****************************\n");
                }
            break;
            case 4:
                preOrdem(a);
            break;
            case 5:
                inOrdemAsc(a);
            break;
            case 6:
                inOrdemDesc(a);
            break;
            case 7:
                posOrdem(a);
            break;
            case 0: 
                printf("SAINDO...\n");
            break;
        }
    }while(opc != 0);
    return 0;
}
