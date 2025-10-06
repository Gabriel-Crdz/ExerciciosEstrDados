#include <stdio.h>

int menu(){
    int opc;
    do{
        printf("+---------MENU---------\n");
        printf("| [1] Inserir elemento\n");
        printf("| [2] Remover elemento\\n");
        printf("| [3] contar elementos\n");
        printf("| [4] Buscar elemento\n");
        printf("| [5] Imprimir lista\n");
        printf("|.....................\n");
}

int main(){
    int opc;
    printf("=-=LISTA ENCADEADA ORDENADA=-=\n");
    do{
        opc = menu();
        switch(opc){
            case 1: inserirElemento();
            break;
            case 2: removerElemento();
            break;
            case 3: contarElementos();
            break;
            case 4: buscarElemento();
            break;
            case 5: imprimirLista();
        }

    }while(opc != 0);
    return 0;
}