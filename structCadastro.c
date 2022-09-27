#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[40];
	char genero[40];
	int integrantes;
	int ranking;
}tbanda;
int qtd=0; //controlar posição dentro do vetor

void addBanda(tbanda b[]){
	printf("Nome da banda: ");
	fflush(stdin);//limpa o buffer do teclado
	gets(b[qtd].nome);
	printf("Genero da banda: ");
	fflush(stdin);//limpa o buffer do teclado
	gets(b[qtd].genero);
	printf("Quantidade de integrantes: ");
	scanf("%d",&b[qtd].integrantes);	
	printf("Ranking da banda: ");
	scanf("%d",&b[qtd].ranking);
	qtd++;
}

void listaBandas(tbanda b[]){
	int i;
	for(i=0;i<qtd;i++){
		printf("\n** Banda %d **\n",i+1);
		printf("Nome: %s\n",b[i].nome);
		printf("Genero da banda: %s\n",b[i].genero);
		printf("Quantidade de integrantes: %d\n",b[i].integrantes);
		printf("Ranking da banda: %d\n",b[i].ranking);
	}
}

int menu(){
	int opcao;
	printf("***SISTEMA DE CADRASTRO ROCK4YOU***\n");
	printf("1- Cadastrar\n");
	printf("2- Listar\n");
	printf("3- Busca\n");
	printf("4- Filtrar Genero\n");
	printf("0- Sair\n");
	printf("\nEntre com sua escolha: ");
	scanf("%d",&opcao);
	return opcao;
}//fim menu;
//-----------------------------
void listaRanking(tbanda b[], int busca){
	int i;
	for(i=0;i<qtd;i++){
		if(busca==b[i].ranking){
			printf("\n** Banda %d **\n",i+1);
			printf("Nome: %s\n",b[i].nome);
			printf("Genero da banda: %s\n",b[i].genero);
			printf("Quantidade de integrantes: %d\n",b[i].integrantes);
			printf("Ranking da banda: %d\n",b[i].ranking);
		}
	}
}
//-----------------------------
void filtroGenero(tbanda b[], char generoBusca[40]){
	int i;
	char generoAux[40];
	for(i=0;i<qtd;i++){
		strcpy(generoAux,b[i].genero);
		strupr(generoAux);
		if(strcmp(generoBusca,generoAux)==0){
			printf("\n** Banda %d **\n",i+1);
			printf("Nome: %s\n",b[i].nome);
			printf("Genero da banda: %s\n",b[i].genero);
			printf("Quantidade de integrantes: %d\n",b[i].integrantes);
			printf("Ranking da banda: %d\n",b[i].ranking);
		}
	}
}
//-----------------------------
void salvaArquivo(tbanda bandas[]){
	FILE *arq;
	int i=0;
	arq=fopen("dadosBandas.txt","wb");
	fwrite(&bandas[i],sizeof(tbanda),qtd,arq);
	printf("Dados salvos com sucesso\n");
	fclose(arq);
}
//-----------------------------
void carregaArquivo(tbanda bandas[]){
	FILE *arq;
	arq=fopen("dadosBandas.txt","rb");
	if(arq==NULL){
	  printf("Arquivo nao encontrado :(\n");
	  return;
	  }// fim if
	 while(fread(&bandas[qtd],sizeof(tbanda),1,arq) >0 )
	      qtd++;  
	 printf("Dados carregados com sucesso !\n");
	fclose(arq);
}

int main(){
	tbanda bandas[100];
	int opcao, busca;
	char genero[40];
	carregaArquivo(bandas);
	
	do{
		opcao = menu();
		switch(opcao){
			
			case 1: 
				addBanda(bandas);
			break;
			
			case 2: 
				listaBandas(bandas);
			break;
			
			case 3:
				printf("\nValor para busca: ");
				scanf("%d",&busca);
				listaRanking(bandas,busca);
			
			case 4:
				printf("\nNome do genereo para busca: ");
				fflush(stdin);
				gets(genero);
				strupr(genero);
				filtroGenero(bandas,genero);	
			
			case 0:
				printf("Saindo...\n");
				salvaArquivo(bandas);
			break;
			
			default: printf("Opcao invalida\n");
		}//fim  switch	
		getch();//pausa
		system("cls");//limpa tela
	}while(opcao!=0);
}
