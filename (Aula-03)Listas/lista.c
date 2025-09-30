#include <stdio.h>
#include <string.h>

#define MaxItens 10 // Tamanho maximo de itens na lista
#define TamItem 20  // Tamanho da string

typedef char tpLista[MaxItens][TamItem]; // Cria um tipo como vetor de strings
tpLista L1;                              // Declaração da variavel lista

/* Para iniciar a operação de uma lista, é preciso criar uma lista vazia. */
void criaLista(tpLista l){
    int i;
    for (i = 0; i < MaxItens; i++){
        l[i][0] = '\0'; // Isso pode ser feito zerando todos os strings da lista.
    }
}

int contaLista(tpLista l){
    int i;
    /* Percorre a lista, até chegar ao final do espaço ou encontrar um elemento vazio (tamanho = 0) */
    for (i = 0; i < MaxItens && strlen(l[i]) > 0; i++); // Retorna a posição do elemento vazio, ou MaxItens, que equivale ao número de elementos na lista.
    return (i); // Retorna o total de itens.
}

void insereLista(tpLista l, char *item){   
    int i;
    /* Laço que percorre a lista até encontrar o primeiro elemento vazio com tamanho = 0), ou ultrapassar o espaço alocado para a lista */
    for (i = 0; i < MaxItens && strlen(l[i]) > 0; i++);
    // Testa se ainda tem espaço na lista
    if (i < MaxItens){
        strcpy(l[i], item); // copia o item para a posição vazia da lista
        printf("\nItem (%s) inserido com sucesso", item);
    }
    else
        printf("\nLista cheia, não pode inserir"); // Não tem espaço na lista
}

/* Operação que retira o elemento "item" da lista "l" */
void retiraLista(tpLista l, char *item){
    int i;
    // Procura o elemento "item" na lista. Encerra a busca se chegar ao final do espaço, ou achar o item.
    for (i = 0; i < MaxItens && strlen(l[i]) > 0 && (strcmp(l[i], item) != 0); i++);

    /* Pode ter saído do laço por três razões. */
    if (i < MaxItens && (strcmp(l[i], item) == 0)){ // Encontrou o elemento buscado
        printf("\nItem (%s) encontrado, removendo", item);

        if (i < (MaxItens - 1)){ // Tem outros elementos depois dele, puxa todos para cima
            for (; i < (MaxItens - 1) && strlen(l[i]) > 0; i++) strcpy(l[i], l[i + 1]);
        }

        l[MaxItens - 1][0] = '\0'; // Zera o último elemento do espaço da lista
    }
    else printf("\nItem (%s) não encontrado", item); // Não encontrou o elemento buscado
}

/* Para imprimir o conteúdo de uma lista, basta imprimir todos os strings da lista */
void imprimeLista(tpLista l){
    int i;
    printf("\nItens da lista\n");
    for (i = 0; i < MaxItens && strlen(l[i]) > 0; i++){ // Esse FOR possui um problema pós caso um item seje excluido a lista não e mostrada por completo
        printf("\n%s", l[i]);
    }
    printf("\n");
}
