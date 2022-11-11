#include <stdio.h>
#include <string.h>

typedef struct{
	char titulo[30];
	char autor[15];
	int ano;
	int prateleira;
}tlivro;

int qtd = 0;
//--------------------------------------------

void salvaArquivo(tlivro liv[])
{
	FILE *arq;
	int i = 0;
	arq = fopen("dadosLivros.txt", "wb");
	fwrite(&liv[i], sizeof(tlivro), qtd, arq);
	printf("Dados salvos com sucesso.\n");
	fclose(arq);
}
//--------------------------------------------

void carregaArquivo(tlivro liv[]){
	FILE *arq;
	arq = fopen("dadosLivros.txt", "rb");
	if(arq == NULL){
		printf("Arquivo de livros nao encontrado!\n");
		return;
	}
	while(fread(&liv[qtd], sizeof(tlivro), 1, arq) > 0)
		qtd++;
	printf("Dados carregados com sucesso!\n");
	fclose(arq);
}
//--------------------------------------------
void addLivro(tlivro liv[])
{
	printf("Titulo do livro: ");
	fflush(stdin);
	gets(liv[qtd].titulo);
	
	printf("Nome do autor: ");
	fflush(stdin);
	gets(liv[qtd].autor);
	
	printf("Ano de publicacao:");
	fflush(stdin);
	scanf("%d", &liv[qtd].ano);
	
	printf("Prateleira:");
	fflush(stdin);
	scanf("%d", &liv[qtd].prateleira);
	
	qtd++;
}
//--------------------------------------------

void listaLivros(tlivro liv[])
{
	
	for(int i = 0; i < qtd; i++)
	{
		printf("*** Livro %d ***\n", i + 1);
		printf("Titulo: %s\n", liv[i].titulo);
		printf("Nome do autor: %s\n", liv[i].autor);
		printf("Ano de publicacao: %d\n", liv[i].ano);
		printf("Prateleira: %d\n", liv[i].prateleira);
		printf("------------------------\n");
	}
	
}
//--------------------------------------------

int filtraTitulo(tlivro liv[], char tituloConsulta[30])
{
	char tituloAux[40];
	int res = -1;
	
	for(int i = 0; i < qtd; i++)
	{
		strcpy(tituloAux, liv[i].titulo); // copiando do vetor para aux
		strupr(tituloAux); // uppercase
		if(strcmp(tituloConsulta, tituloAux) == 0)
		{
			printf("*** Livro %d ***\n", i + 1);
			printf("Titulo: %s\n", liv[i].titulo);
			printf("Nome do autor: %s\n", liv[i].autor);
			printf("Ano de publicacao: %d\n", liv[i].ano);
			printf("Prateleira: %d\n", liv[i].prateleira);
			printf("------------------------\n");
			res = 0;
		}
	}
	
	return res;
	
}
//--------------------------------------------
int filtraAno(tlivro liv[], int anoCons)
{
	int res = -1;
	
	for(int i = 0; i < qtd; i++)
	{
		if(liv[i].ano >= anoCons)
		{
			printf("*** Livro %d ***\n", i + 1);
			printf("Titulo: %s\n", liv[i].titulo);
			printf("Nome do autor: %s\n", liv[i].autor);
			printf("Ano de publicacao: %d\n", liv[i].ano);
			printf("Prateleira: %d\n", liv[i].prateleira);
			printf("------------------------\n");
			res = 0;
		}
	}
	
	return res;
}
//--------------------------------------------
int menu()
{
	int opcao;
	
	printf("*** Livraria Struct ***\n");
	printf("1 - Cadastrar livro\n");
	printf("2 - Listar livros\n");
	printf("3 - Procurar por titulo\n");
	printf("4 - Filtrar por ano de publicacao\n");
	printf("0 - Sair\n");
	printf("Opcao: ");
	scanf("%d", &opcao);
	printf("\n");
	return opcao;
}
//--------------------------------------------
int main()
{
	tlivro livros[100];
	int op, res, busca;
	char tituloBusca[30];
	
	carregaArquivo(livros);
	
	do
	{
		op = menu();
		switch(op)
		{
			case 1:
				addLivro(livros);
				break;
			case 2:
				listaLivros(livros);
				break;
			case 3:
				printf("Titulo para pesquisa: ");
				fflush(stdin);
				gets(tituloBusca);
				strupr(tituloBusca);
				res = filtraTitulo(livros, tituloBusca);
				if(res == -1)
				{
					printf("Livro nao encontrado!");
				}
				break;
			case 4:
				printf("Insira o ano minimo para publicacao: ");
				scanf("%d", &busca);
				res = filtraAno(livros, busca);
				if(res == -1)
				{
					printf("Nao ha livros publicados a partior desse ano!");
				}
				break;
			case 0:
				printf("Saindo...\n");
				salvaArquivo(livros);
				break;
			default:
				printf("Opcao invalida!!!\n");
				break;
		}
		getch();
		system("cls");
	}while(op != 0);
}
