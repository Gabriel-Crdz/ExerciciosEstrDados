#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Registro{
    char nome[40];
    char situacao;
    int matricula;
    int faltas;
    float nota1;
    float nota2;
    float media;
};

struct Registro turma[40];

void inserirAlunos(){}
void exibirAlunos(){}
void salvarAlunos(){}
void carregarAlunos(){}

int main()
{
    int opc;
    printf("*-*-*REGISTRO DE TURMA*-*-*\n\n");

    do{ // Validação da opção do menu
        printf("+=========MENU=========\n");
        printf("| [1] Inserir alunos\n");
        printf("| [2] Exibir alunos\n");
        printf("| [3] Salvar alunos\n");
        printf("| [4] Carregar alunos\n");
        printf("| [0] Sair\n");
        printf("|.....................\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);

        if(opc < 0 || opc > 4){
            printf("\n************************\n");
            printf("ERRO: Entrada Invalida!!\n");
            printf("************************\n\n");
        }
    }while(opc < 0 || opc > 4);

    switch(opc){
        case 1: inserirAlunos(); // Chama a função de cadastro
            break;

        case 2: exibirAlunos(); // Chama a função para listar os alunos
            break;

        case 3: salvarAlunos(); // Chama a função para gravar os dados
            break;

        case 4: carregarAlunos(); // Chama a função para armazenar na memoria os registros
            break;
        
        case 0: printf("SAINDO...");
                break;
    }
    
    return 0;
}