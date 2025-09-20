#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define tam 40 // Define o tamanho da turma

struct Taluno{
    char nome[40];
    char situacao[10];
    int matricula;
    int faltas;
    float nota1;
    float nota2;
    float media;
};

struct Tturma{
    struct Taluno turma[tam]; // aluno pertence a uma turma
    int serieTurma;
    char letraTurma;
};

struct Tturma e; // a Turma pertence a uma escola

/* Função para cadastrar a turma */
int inserirAlunos(){
    int numCadastros, i;
    printf("\n+====CADASTRO DA TURMA====\n"); // Informações da turma
    printf("|= Informe o serie de turma: ");
    scanf("%d", &e.serieTurma);
    printf("|= Informe a letra da turma: ");
    scanf(" %c", &e.letraTurma);
    do{ 
        printf("|= Informe o numero de alunos: ");
        scanf("%d", &numCadastros);
        if(numCadastros > tam){
            printf("\n************************\n");
            printf("ERRO: Numero de cadastros\n");
            printf("maior que o limite maximo\n");
            printf("*************************\n\n");
        }
    }while(numCadastros > tam);
    printf("..........................\n");

    printf("===CADASTRO DOS ALUNOS==="); // Dados dos alunos
    for(i = 0; i < numCadastros; i++){
        printf("\n+== %dº aluno =>\n", i+1);
        printf("|= Nome: ");
        getchar();  // Apaga o ENTER deixado pelo scanf no buffer
        fgets(e.turma[i].nome, 40, stdin);
        e.turma[i].nome[strlen(e.turma[i].nome)-1] = '\0'; // Remove a quebra de linha da string
        printf("|= Matricula: ");
        scanf("%d", &e.turma[i].matricula);
        printf("|= Nota 1: ");
        scanf("%f", &e.turma[i].nota1);
        printf("|= Nota 2: ");
        scanf("%f", &e.turma[i].nota2);
        printf("|= Numero faltas: ");
        scanf("%d", &e.turma[i].faltas);

        /* Determinando a situação do aluno */
        e.turma[i].media = (e.turma[i].nota1 + e.turma[i].nota2) / 2;
        if(e.turma[i].media >= 6 && e.turma[i].faltas <= 20){
            strcpy(e.turma[i].situacao, "Aprovado"); // Insere um valor na string previamente declarada
        }
        else{ strcpy(e.turma[i].situacao, "Reprovado"); }
    }
    printf("..........................\n");
    return numCadastros;

}
/* Função para listar os alunos da turma */
int exibirAlunos(int n){
    char temp, i;
    printf("========LISTA DE ALUNOS========\n");
    printf("TURMA = Serie: %dº%c - Nº alunos: %d\n", e.serieTurma, e.letraTurma, n);
    for(i = 0; i < n; i++){
        printf(".......................\n");
        printf("+== %dº aluno =>\n", i+1);
        printf("|- Nome: \t%s\n", e.turma[i].nome);
        printf("|- Matricula: \t%d\n", e.turma[i].matricula);
        printf("|- Faltas: \t%d\n", e.turma[i].faltas);
        printf("|- Nota 1: \t%2.1f\n", e.turma[i].nota1);
        printf("|- Nota 2: \t%2.1f\n", e.turma[i].nota2);
        printf("|- Media: \t%2.1f\n", e.turma[i].media);
        printf("|- Situação: \t%s\n", e.turma[i].situacao);
    }
    printf("aperte ENTER para voltar: "); // Essa leitura serve para que o menu só apareça
    temp = getchar();                     // quando o usuario terminar de analisar a lista
    return 0;
}
/* Função para salvar em arquivo os alunos */
int salvarAlunos(int n){
    FILE *arq; // Ponteiro do arquivo
    arq = fopen("registro.bin", "wb+"); // Abre o arquivo com escrita(se nao existir cria)
    if(!arq) {
        printf("\n*******************************\n");
        printf("ERRO: ao abrir/criar o arquivo!");
        printf("*******************************\n");
        fflush(stdout);
        return 1;
    }
    size_t salvo = fwrite(&e.turma[0], sizeof(struct Taluno), n, arq); // 
    
    if(salvo != n || ferror(arq) != 0){
        printf("\n**********************************\n");
        printf("ERRO: dados gravados incorretamente!");
        printf("**********************************\n");
        fflush(stdout);
        return 2;
    }
    fclose(arq); // Fecha o arquivo

    printf("\n*******************************\n");
    printf("SUCESSO: os dados foram salvos!");
    printf("*******************************\n");
    fflush(stdout);

    return 0;
}
/* Função para carregar um arquivo de dados dos alunos */
int carregarAlunos(){
    FILE *arq;
    arq = fopen("registro.bin", "rb");
}

/* Função que mostra o menu */
int menu(int n){
    int opc;
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
            getchar(); // Apaga o ENTER deixado pelo buffer

            if(opc < 0 || opc > 4){
                printf("\n************************\n");
                printf("ERRO: Entrada Invalida!!\n");
                printf("************************\n\n");
            }
            else if(n == 0 && opc != 1){
                printf("\n****************************\n");
                printf("ERRO: Nenhum cadastro feito!\n");
                printf("****************************\n\n");
                opc = -1; // Impede a saia do loop por ter erro
            }
        }while(opc < 0 || opc > 4);
        return opc;
}

/* Função principal */
int main()
{
    int opc, numCadastros = 0;
    printf("*-*-*REGISTRO DE TURMA*-*-*\n\n");

    do{ // Menu em loop
        opc = menu(numCadastros);

        switch(opc){
            case 1: 
                numCadastros = inserirAlunos(); // Chama a função de cadastro
                break;

            case 2: exibirAlunos(numCadastros); // Chama a função para listar os alunos
                break;

            case 3: salvarAlunos(numCadastros); // Chama a função para gravar os dados
                break;

            case 4: carregarAlunos(); // Chama a função para armazenar na memoria os registros
                break;
            
            case 0: printf("SAINDO...\n\n");
                    break;
        }
    }while(opc != 0);

    return 0;
}