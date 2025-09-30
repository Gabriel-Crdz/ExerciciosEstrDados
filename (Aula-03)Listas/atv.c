#include <stdio.h>
#include <string.h>

#define MaxItens 10 // Tamanho maximo de itens na lista
#define TamItem 20  // Tamanho da string

typedef char tpLista[MaxItens][TamItem]; // Cria um tipo como vetor de strings

/* Para iniciar a operação de uma lista, é preciso criar uma lista vazia. */
void criaLista(tpLista l){
    int i;
    for (i = 0; i < MaxItens; i++){
        l[i][0] = '\0'; 
    }
}

int contaLista(tpLista l){
    int i;
    /* Percorre a lista, até chegar ao final do espaço ou encontrar um elemento vazio (tamanho = 0) */
    for (i = 0; i < MaxItens && strlen(l[i]) > 0; i++); 
    return (i); // Retorna o total de itens.
}

void inserirItem(tpLista l, char *item){   
    int i;
    for (i = 0; i < MaxItens && strlen(l[i]) > 0; i++);

    if (i < MaxItens){
        strcpy(l[i], item); // copia o item para a posição vazia da lista
        printf("\n***********************\n");
        printf("SUCESSO: Item inserido!\n");
        printf("***********************\n");
    }
    else{
        printf("\n*******************\n");
        printf("ERRRO: Lista cheia!\n"); // Não tem espaço na lista
        printf("*******************\n");
    } 
}

/* Operação que retira o elemento "item" da lista "l" */
void removerItem(tpLista l, char *item){
    int i;

    for (i = 0; i < MaxItens && strlen(l[i]) > 0 && (strcmp(l[i], item) != 0); i++);
    
    /* Pode ter saído do laço por três razões. */
    if (i < MaxItens && (strcmp(l[i], item) == 0)){ // Encontrou o elemento buscado
        printf("\n************************\n");
        printf("SUCESSO: Item removido!!\n");
        printf("************************\n\n");

        if (i < (MaxItens - 1)){ // Tem outros elementos depois dele, puxa todos para cima
            for (; i < (MaxItens - 1) && strlen(l[i]) > 0; i++) strcpy(l[i], l[i + 1]);
        }
        
        l[MaxItens - 1][0] = '\0'; // Zera o último elemento do espaço da lista
    }
    else{
        printf("\n**************************\n");
        printf("ERRO: Item não encontrado!\n");
        printf("**************************\n"); // Não encontrou o elemento buscado
    }
}

/* Para imprimir o conteúdo de uma lista, basta imprimir todos os strings da lista */
void exibirLista(tpLista l){
    int i;
    printf("\n+=====ITENS NA LISTA=====\n");
    for (i = 0; i < MaxItens && strlen(l[i]) > 0; i++){
        printf("|- %d %s\n", i + 1, l[i]);
    }
    printf("|........................\n");
}

int menu(){
    int opc;
    do{
        printf("+=======MENU=======\n");
        printf("| [1] Inserir Item\n");
        printf("| [2] Remover Item\n");
        printf("| [3] Contar Itens\n");
        printf("| [4] Exibir Lista\n");
        printf("| [0] Sair\n");
        printf("|.....................\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);
        getchar(); // Limpa o ENTER

        if(opc < 0 || opc > 4){
            printf("\n************************\n");
            printf("ERRO: Entrada Invalida!!\n");
            printf("************************\n\n");
        }
    }while(opc < 0 || opc > 4);
    return opc;
}

int main(){
    tpLista L1;
    int opc, qtdItens;
    char item[20];

    printf("*=*=*=*=*LISTA*=*=*=*=*\n\n");
    criaLista(L1);
    do{
		opc = menu();    

		switch(opc){
			case 1: 
				printf("+======INSERINDO======\n");
				printf("|= Informe o item a ser inserido: ");
				fgets(item, sizeof(item), stdin);
				item[strlen(item)-1] = '\0';
				inserirItem(L1, item);
				break;
			case 2: 
				printf("+======REMOVENDO======\n");
				printf("|= Informe o item a ser removido: ");
				fgets(item, sizeof(item), stdin);
				item[strlen(item)-1] = '\0';
				removerItem(L1, item);
				break;
			case 3: 
				qtdItens = contaLista(L1);
				printf("\nA %d itens na lista\n", qtdItens);
                printf("......................\n");
				break;
			case 4: exibirLista(L1); 
				break;
			case 0: printf("SAINDO..."); 
				break;
		}
	}while(opc != 0);	
    return 0;
}
