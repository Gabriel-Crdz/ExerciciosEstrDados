#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define os campos que compõem o endereço
struct ender 
{
	char rua[50];
	int numero;
	char complemento[15];
	char bairro[30];
	char cidade[30];
	char UF[4];
	char CEP[10];
};

// Define os campos que compõem o registro de um aluno
struct aluno
{
	char nome[50];
	int matricula;
	char nascimento[12];
	char sexo;
	char telefone[20];
	//long int telefone;
	struct ender endereco;
    
};

// Estrutura que contém os dados dos alunos de uma turma
struct turma
{
    struct aluno cadastro[50];
    int cont;
};

// Declaração de uma variável global "c" que contém os dados de uma turma.
struct turma c;

// Função auxiliar para retirar o caracter de fim de linha de um string s
void tiraf(char *s)
{
	s[strlen(s)-1] = '\0';
}

// Função auxiliar para ler um string s, com no máximo tam caracteres.
void leString(char *s, int tam)
{
	fgets(s,tam,stdin); // Lê <tam> caracteres da entrada padrão, armazenando em <s>
	tiraf(s);           // Tira o fim de linha de <s>
}

// Função que lê todos os dados de um aluno, retornando um registro do tipo aluno.
struct aluno leAluno()
{
	struct aluno a;			// Declara uma variável <a> que conterá uma estrutura aluno
	char buffer[100];
	
	// Leitura dos dados da estrutura aluno
	printf("\nNome:");
	leString(a.nome,sizeof(a.nome));
	printf("\nMatricula:");
	leString(buffer,sizeof(buffer));
	sscanf(buffer,"%d",&a.matricula);
	printf("\nData de nascimento (DD/MM/AAAA):");
	leString(a.nascimento, sizeof(a.nascimento));
	printf("\nSexo: ");
	leString(buffer, sizeof(buffer));
	a.sexo = buffer[0];
	printf("\nTelefone:");
	leString(a.telefone,sizeof(a.telefone));
	//sscanf(buffer,"%ld",&a.telefone);
	printf("\nRua: ");
	leString(a.endereco.rua, sizeof(a.endereco.rua));
	printf("\nNúmero: ");
	leString(buffer,6);
	// Leitura dos dados da estrutura endereço
	sscanf(buffer,"%i",&a.endereco.numero);
	printf("\nComplemento: ");
	leString(a.endereco.complemento,sizeof(a.endereco.complemento));
	printf("\nBairro: ");
	leString(a.endereco.bairro,sizeof(a.endereco.bairro));
	printf("\nCidade: ");
	leString(a.endereco.cidade,sizeof(a.endereco.cidade));
	printf("\nUF: ");
	leString(a.endereco.UF,sizeof(a.endereco.UF));
	printf("\nCEP: ");
	leString(a.endereco.CEP,sizeof(a.endereco.CEP));
	return a;
}

// Função que salva os dados dos alunos da turma (variável global c) 
// no arquivo "alunos.txt" na pasta corrente
// Retorna 0 se conseguiu gravar, e 1 em caso de erro.
int salvaCadastro(int i)
{
	FILE *arq;
	int j;
	
	arq = fopen("alunos.txt","w");
	if (arq == NULL) 
	{
		fprintf(stderr,"\nErro ao abrir arquivo alunos.txt");
		return (1);
	}
	else
	{
	   // Grava todos os registros com um único comando
	   fwrite(&c.cadastro[0], sizeof(struct aluno),i,arq);
	   // Grava um registro por vez
	   //for (j = 0; j < i; j ++) {
	   //   fwrite(&c.cadastro[j], sizeof(struct aluno),1,arq);
	   //}
	   fclose(arq);
	}
	return (0);
}

// Função que permite ao usuário digitar os dados dos alunos, e armazena na variável c
// Retorna o número de alunos lidos.
int leCadastro()
{
	char buffer[100];
	char continua;
	int i;
	
	i = 0;
	do {
		c.cadastro[i] = leAluno();
		
		printf("\nJá foram lidos %d alunos. Deseja continuar (s/n):",i+1);
		leString(buffer,sizeof(buffer));
		continua = buffer[0];
		i++;
		printf("Continua = %c",continua);
	} while ((continua == 's') && (i<50));
	
	return i;
}

// Função que abre o arquivo alunos.txt, lê os dados, um registro por vez
//    e armazena na variável c
// Retorna o número de registros lidos, e -1 em caso de erro.
int carregaCadastro()
{
	FILE *arq;
	int j, lido;
	
	arq = fopen("alunos.txt","r");
	if (arq == NULL) 
	{
		fprintf(stderr,"\nErro ao abrir arquivo alunos.txt");
		return (-1);
	}
	else
	{
		j = 0;
		do {
			lido = fread(&c.cadastro[j], sizeof(struct aluno),1,arq);
			j++;
		} while (lido == 1);
		fclose(arq);
	}
	return (j-1);
}

// Função que lista na tela os dados dos registros dos alunos,
//   armazenados na variável c
void listaCadastro(int i)
{
	int j;
	
	for (j=0 ; j<i; j++)
	{
		printf("\n%d - %s - Sexo(%c) - Nasc. %s - Fone: %s", 
				c.cadastro[j].matricula, c.cadastro[j].nome, c.cadastro[j].sexo,
				c.cadastro[j].nascimento, c.cadastro[j].telefone);
	}
}

// Função que oferece as opções para o usuário
// Retorna o número da opção escolhida

int menu()
{
	int op;
	char str[10];
	
	do {
		printf("\n1 - Carrega o Cadastro de Alunos");
		printf("\n2 - Cadastrar Alunos");
		printf("\n3 - Salva o Cadastro de Alunos");
		printf("\n4 - Listar o Cadastro de Alunos");
		printf("\n0 - Encerra");
		printf("\n\n Entre com a opção: ");
		leString(str,sizeof(str));
		sscanf(str,"%d",&op);
	} while ((op < 0) || (op > 4));
	return (op);
}
		

// Programa principal.
// Inicializa o número de alunos em 0;
// Entra no laço, até que o usuário escolha a opção 0 (sair)
// Oferece as opções disponíveis ao usuário
// Chama a função correspondente à opção escolhida pelo usuário
int main()
{
	int numAlunos, codigo, opcao;
	
	numAlunos = 0;
	do {
		opcao = menu();
		switch (opcao) {
			case 1: numAlunos = carregaCadastro();
				printf("\nNumero de Alunos = %d",numAlunos);
				break;
			case 2: numAlunos = leCadastro();
				break;
			case 3: codigo = salvaCadastro(numAlunos);
				if (codigo == 0) 
					printf("\nCadastro salvo com sucesso");
				break;
			case 4: listaCadastro(numAlunos);
				break;
		}
	} while (opcao != 0);
	return codigo;
}
	
