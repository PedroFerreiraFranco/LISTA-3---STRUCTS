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
//-----------------------------
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
//-----------------------------
int menu(){
	int opcao;
	printf("***SISTEMA DE CADRASTRO ROCK4YOU***\n");
	printf("1- Cadastrar\n");
	printf("2- Listar\n");
	printf("3- Busca\n");
	printf("4- Filtrar Genero\n");
	printf("5- Procurar nome da banda\n");
	printf("6- Excluir\n");
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
int procurarBanda(tbanda b[], char nomeBanda[40]){
	int i;
	char nomeAux[40];
	for(i=0;i<qtd;i++){
		strcpy(nomeAux,b[i].nome);//copiando dados do vetor para a variavel
		strupr(nomeAux);//uppercase
		if(strcmp(nomeBanda,nomeAux)==0){
			printf("\n** Banda %d **\n",i+1);
			printf("Genero da banda: %s\n",b[i].genero);
			printf("Quantidade de integrantes: %d\n",b[i].integrantes);
			printf("Ranking da banda: %d\n",b[i].ranking);
				return i;//encontrou e retornou o indice
		}
	}
	return -1;//nao encontrou 
}
//-----------------------------
void removeBanda(tbanda b[], char nomeBanda[40]){
	int posicao,resp;
	
	posicao = procurarBanda(b,nomeBanda);
	if(posicao == -1){
		printf("Banda nao encontrada\n");
	return;
	}//fim if
	printf("\nDeseja mesmo deletar a banda?\n[1-sim][2-nao]\n\nOp escolhida:");
	scanf("%d",&resp);
	if(resp==1){
		b[posicao] = b[qtd-1];//sobrepondo a ultima banda
		qtd--;
	printf("Banda removida com sucesso");
}
	else 
		printf("Operacao cancelada\n");
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
//-----------------------------
int main(){
	tbanda bandas[100];
	int opcao, busca;
	char genero[40],nome[40];
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
			break;	
				
			case 5:
				printf("\nNome da banda: ");
				fflush(stdin);
				gets(nome);
				strupr(nome);
				if(procurarBanda(bandas,nome)==-1)
					printf("\nBanda nao encontrada :(\n");
				else
					printf("\nBanda encontrada :)\n");
			break;
			
			case 6:
				printf("\nNome da banda para: ");
				fflush(stdin);
				gets(nome);
				strupr(nome);
				removeBanda(bandas,nome);
			break;
			
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
