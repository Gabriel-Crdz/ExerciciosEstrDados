#include <stdio.h>
#include <stdlib.h>
#define TAM 10




int menu(){
    int opc;
    do{
        printf("\n+----------MENU----------\n");
        printf("| [1] Inserir na Vetor\n");
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
    do{
        opc = menu();
        system("clear");
    }while(opc != 0);
    return 0;
}