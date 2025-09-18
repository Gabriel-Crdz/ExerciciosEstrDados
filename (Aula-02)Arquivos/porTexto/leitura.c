//Leitura de arquivo

#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *pontArq;
    char texto[20];

    //abrindo o arquivo_frase em modo "somente leitura"
    pontArq = fopen("teste.txt", "r");

    //enquanto não for fim de arquivo o looping será executado
    //e será impresso o texto
    while(fgets(texto, 20, pontArq) != NULL) printf("%s", texto);

    //fechando o arquivo
    fclose(pontArq);

return(0);
}
