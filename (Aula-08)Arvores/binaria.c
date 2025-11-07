#include <stdio.h>

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

arvore buscarArvore(arvore a, int valor){
    if(a == NULL) return NULL; // Arvore vazia, elemento não existe, retorna NULL

    else if(valor < a->dado) return buscarArvore(a->esq, valor); // Se menor que a raiz, busca à esquerda
    else if(valor > a->dado) return buscarArvore(a->dir, valor); // Se maior que a raiz, busca à direita
    else return a; // Encontrou o elemento
}

void preOrdem(arvore a){
    if(a != NULL){
        printf("\n [%d] ");
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}

void inOrdemAsc(arvore a){
    if(a != NULL){ // Imprime os elementos em ordem crescente
        inOrdemAsc(a->esq);
        printf("\n [%d]", a->dado);
        inOrdemAsc(a->dir);
    }
}

void inOrdemDesc(arvore a){
    if(a != NULL){
        inOrdemDesc(a->dir);
        printf("\n[%d]", a->dado);
        inOrdemDesc(a->esq);
    }
}


void posOrdem(arvore a){ // Imprime os elementos em ordem decrescente
    if(a != NULL){
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("\n[%d]", a->dado);
    }
}