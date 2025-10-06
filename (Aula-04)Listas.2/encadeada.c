#include <stdio.h>

struct elemento{
    int dado;              // Conteúdo (inteiro)
    struct elemento *prox; // Ponteiro para o próximo registro
};

/* É interessante tratar os nodos como um novo tipo de dados, e atribuir um novo nome a esse tipo. */
typedef struct elemento Nodo;
Nodo n;
Nodo *p;

/* Também podemos definir um tipo Lista como um ponteiro para nodo. */
typedef Nodo *Lista;

/* A criação de uma lista precisa produzir uma lista vazia, o que neste caso significa um
ponteiro do tipo Lista, apontando para NULL. */
Lista criaLista(){
    return NULL;
}

/*
Lista lista1;         // Declaração da variável lista1
lista1 = criaLista(); // Inicialização da lista1 (lista vazia)
*/

// Imprime todos os nodos da lista l
void imprimeLista(Lista l){
    Lista p; // Ponteiro auxiliar, para percorrer a lista
    printf("\nItens da lista\n");
    p = l; // Fazer p apontar para o início da lista
    while (p != NULL){            // Enquanto não chegar ao final da lista
        printf("%d - ", p->dado); // Imprime o elemento
        p = p->prox;              // Avança o ponteiro para o próximo nodo
    }
    printf("\n"); // Avança para a próxima linha
}

// Conta o número de nodos da lista l
int contaLista(Lista l){
    Lista p;
    int cont = 0; // inicia o contador com 0
    p = l;        // aponta p para o início da lista
    while (p != NULL){  // enquando não acabou a lista
        cont++;         // incrementa o contador
        p = p->prox;    // passa para o próximo elemento
    }
    return cont; // retorna o contador
}

// Procura o elemento e na lista l, retornando o endereço
// do elemento se ele estiver na lista, ou NULL em caso contrário
Lista buscaLista(Lista l, int e){
    Lista p; // Ponteiro para percorrer a lista
    p = l;   // Faz o ponteiro apontar para o início da lista
    // Percorre a lista enquanto não chegar ao final da lista
    // e não encontrar o elemento
    while ((p != NULL) && (p->dado != e)){
        p = p->prox;
    }
    return (p); // Retorna o endereço do nodo encontrado
    // ou NULL caso tenha chegado ao final sem
    // encontrar o elemento e na lista.
}

// Insere um elemento 'e' no início da lista l
Lista insereLista(Lista l, int e){
    Lista novo;
    novo = malloc(sizeof(struct elemento)); // Aloca o espaço e faz as atribuições de valores
    novo->dado = e;
    novo->prox = l; // O próximo do novo é o início da lista
    return (novo);  // Retorna o endereço do novo elemento
}
/* Declaração no MAIN
l1 = insereLista(l1, valor);
*/

/* Lista Encadeada Ordenada */
Lista insereLista(Lista l, int e){
    Lista p, ant, novo;
    // Aloca o espaço e faz as atribuições de valores
    novo = malloc(sizeof(struct elemento));
    novo -> dado = e;
    // Procura o ponto de inserção na lista
    p=l;
    ant=p;
    while ((p != NULL) && (p->dado < e)) {
        ant = p;
    p = p->prox;
    }
    if (p != ant) { // Não vai inserir antes do primeiro, insere entre ant e p
        ant->prox = novo;
    }
    else { // Lista vazia ou inserindo antes do primeiro elemento
    l = novo;
    }
    novo->prox = p;
    return l;
}

// Retira o elemento e da lista l, se ele existir.
// Retorna o endereço para o início da lista.
/* O comando free(x) é usado para liberar o espaço de memória apontado pelo ponteiro x */
Lista retiraLista(Lista l, int e){
    Lista p, // Ponteiro p para o elemento atual
        ant; // Ponteiro ant para o elemento anterior
    p = l;
    ant = l;
    // Procura o elemento e até o fim da lista ou encontrá-lo
    while ((p != NULL) && (p->dado != e)){ // Procura o elemento e
        ant = p;
        p = p->prox;
    }
    if (p != NULL){    // Encontrou o elemento e. Remove
        if (p == ant){ // Removendo primeiro elemento
            l = p->prox;
            free(p);
        }
        else{ // Não é o primeiro elemento da lista
            ant->prox = p->prox;
            free(p);
        }
    }
    return (l);
}