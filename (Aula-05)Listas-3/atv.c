#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int dado;              // Conteúdo (inteiro)
    struct elemento *prox; // Ponteiro para o próximo registro
};

typedef struct elemento Nodo;
Nodo n;
Nodo *p;

typedef Nodo *Lista;

Lista criarLista(){
    return NULL;
}

Lista inserirElemento(Lista l, int e){
    Lista p, ant, novo;
    
    novo = malloc(sizeof(struct elemento));
    novo->dado = e;
    p = l;
    ant = p;
    
    while((p != NULL) && (p->dado <= e)){
        ant = p;
        p = p->prox;
    }
    if(p != ant){ // Insere entre ant e p
        ant->prox = novo;
    }
    else{ // Lista Vazia
        l = novo;
    }

    novo->prox = p;
    return l;
}

Lista removerElemento(Lista l, int e){
    Lista p, ant; 
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
    return l;
}

int contarElementos(Lista l){
    Lista p;
    int cont = 0; 
    p = l;        // aponta p para o início da lista
    while (p != NULL){  // enquando não acabou a lista
        cont++;         
        p = p->prox;    // passa para o próximo elemento
    }
    return cont; // retorna o contador
}

Lista buscarElemento(Lista l, int e){
    Lista p; 
    p = l;   // Faz o ponteiro apontar para o início da lista
    // Percorre a lista enquanto não chegar ao final da lista e não encontrar o elemento
    while ((p != NULL) && (p->dado != e)){
        p = p->prox;
    }
    return p; // Retorna o endereço do nodo encontrado ou NULL

}

void imprimirLista(Lista l){
    Lista p; 
    printf("\n-----ELEMENTOS DA LISTA-----\n");
    p = l; // Fazer p apontar para o início da lista
    while (p != NULL){            // Enquanto não chegar ao final da lista
        printf("[%d] - ", p->dado); 
        p = p->prox;              
    }
    printf("\n"); // Avança para a próxima linha
}

int menu(){
    int opc;
    do{
        printf("+---------MENU---------\n");
        printf("| [1] Inserir elemento\n");
        printf("| [2] Remover elemento\n");
        printf("| [3] Contar elementos\n");
        printf("| [4] Buscar elemento\n");
        printf("| [5] Imprimir lista\n");
        printf("| [0] Sair\n");
        printf("|......................\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);
        getchar();
        
        if(opc < 0 || opc > 5){
            printf("\n************************\n");
            printf("ERRO: Entrada Invalida!!\n");
            printf("************************\n\n");
        }
        
    }while(opc < 0 || opc > 5);
    return opc;
}

int main(){
    int opc, valor, qtd;
    Lista l1;
    l1 = criarLista();
    printf("=-=LISTA ENCADEADA ORDENADA=-=\n");
    do{
        opc = menu();
        system("clear");
        switch(opc){
            case 1: 
                printf("+======INSERINDO======\n");
			    printf("|= Informe o item a ser inserido: ");
                scanf("%d", &valor);
                l1 = inserirElemento(l1, valor);
            break;
            case 2:
                printf("+======REMOVENDO======\n");
				printf("|= Informe o item a ser removido: ");
				scanf("%d", &valor);
                l1 = removerElemento(l1, valor);
                break;
            case 3:
                qtd = contarElementos(l1);
                printf("\nA [%d] elementos na lista\n", qtd);
                printf(".......................\n");
                break;
            case 4: 
                printf("+======BUSCA======\n");
				printf("|= Informe o item a ser encontrado: ");
				scanf("%d", &valor);
                p = buscarElemento(l1, valor);
                if(p != NULL){
					printf("Elemento: [%d]\n",p->dado);
					printf(".......................\n");
				}
				else{
					printf("\n****************************\n");
					printf("ERRO: Elemento Inexistente!!\n");
					printf("****************************\n\n");
				}
                break;
            case 5:    
                imprimirLista(l1);
                break;
            default:
                printf("SAINDO...\n");
                break;
        }

    }while(opc != 0);
    return 0;
}
