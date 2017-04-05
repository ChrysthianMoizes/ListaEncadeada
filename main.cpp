#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tipoArt{
	char nome[50];
	int faixas;
	tipoArt *prox;
}TArt;	
	
typedef struct tipoList{
	TArt *inicio, *fim;
	int total;
}TList;

typedef struct tipoFaixa{
	char titulo[50];
	int aoVivo;
	int instrumental;
	tipoFaixa *prox;
}TFaixa;

typedef struct tipoArtista{
	char nome[50];
	tipoArtista *prox;
	TFaixa *faixas;
}TArtista;

typedef struct tipoDisco{
	char titulo[50];
	char ano[4];
	tipoDisco *ante, *prox;
	TArtista *part;
}TDisco;

typedef struct tipoLista{
	TDisco *inicio, *fim;
	int total;
}TLista;

int menu();
void inicializa(TLista *Lista);
void inserirDisco(TLista *Lista);
void alterarDisco(TLista *Lista);
void listarDiscos(TLista Lista);
void listarDisk(TLista Lista);
void consultarDisco(TLista Lista);
void excluirDisco(TLista *Lista);
void ordenarDiscoCres(TLista *Lista);
void ordenarDiscoDec(TLista *Lista);
void inserirArtista(TLista *Lista);
void listarArtista(TLista Lista);
void excluirArtista(TLista *Lista);
void excluirArtistaDeDisco(TDisco *disco);
void inserirFaixa(TLista *Lista);
void excluirFaixa(TArtista *artista);
void listarFaixaDisco(TLista Lista);
void listarFaixaArtista(TLista Lista);
void listarTotalFaixasPorDisco(TLista Lista);
void listarTotalFaixasPorArtista(TLista Lista);
void listarArtistaPorFaixa(TLista Lista);
TArt *buscarArtista(TList List, char *artista);

int main(int argc, char** argv) {
	
	int opcao;
	
	TLista Lista;
	inicializa(&Lista);
	
	do{
		opcao = menu();
		
		switch(opcao){
			
			case 0: system("PAUSE"); exit(1);
			case 1: inserirDisco(&Lista); break;
			case 2: alterarDisco(&Lista); break;
			case 3: listarDiscos(Lista); break;
			case 4: consultarDisco(Lista); break;
			case 5: excluirDisco(&Lista); break;
			case 6: ordenarDiscoCres(&Lista); break;
			case 7: ordenarDiscoDec(&Lista); break;
			case 8: inserirArtista(&Lista); break;
			case 9: listarArtista(Lista); break;
			case 10: excluirArtista(&Lista); break;
			case 11: inserirFaixa(&Lista); break;
			case 12: listarFaixaDisco(Lista); break;
			case 13: listarFaixaArtista(Lista); break;
			case 14: listarTotalFaixasPorDisco(Lista); break;
			case 15: listarTotalFaixasPorArtista(Lista); break;
			case 16: listarArtistaPorFaixa(Lista); break; 
		}
				
	}while(opcao != 0);
	
	return 0;
}

int menu(){
	
	int opcao;
	
	system("CLS");
	printf("\n\n\t===============| MENU |===============\n\n\n");
	printf("\t 0 - SAIR \n\n");
	printf("\t 1 - INSERIR DISCO \n\n");
	printf("\t 2 - ALTERAR DISCO \n\n");
	printf("\t 3 - LISTAR DISCOS \n\n");
	printf("\t 4 - CONSULTAR DISCO \n\n");
	printf("\t 5 - EXCLUIR DISCO \n\n");
	printf("\t 6 - REORDENAR DISCOS (cres.) \n\n");
	printf("\t 7 - REORDENAR DISCOS (desc.) \n\n");
	printf("\t 8 - INSERIR ARTISTA EM DISCO \n\n");
	printf("\t 9 - LISTAR ARTISTA EM DISCO \n\n");
	printf("\t 10 - EXCLUIR ARTISTA DE DISCO \n\n");
	printf("\t 11 - INSERIR FAIXA PARA ARTISTA/DISCO \n\n");
	printf("\t 12 - LISTAR FAIXAS DE DISCO \n\n");
	printf("\t 13 - LISTAR FAIXAS DE ARTISTA \n\n");
	printf("\t 14 - LISTAR TOTAL DE FAIXAS POR DISCO \n\n");
	printf("\t 15 - LISTAR TOTAL DE FAIXAS POR ARTISTA \n\n");
	printf("\t 16 - LISTAR ARTISTAS POR FAIXA \n\n");
	
	do{
		printf("\n\n\t\t Informe a OPCAO desejada: ");
		scanf("%d", &opcao);
		
		if((opcao > 16) || (opcao < 0)){
			
			printf("\n\n\t Opcao Invalida! \n\n");
		}
		
	}while((opcao > 16) || (opcao < 0));
		
	return opcao;	
}

void inicializa(TLista *Lista){
	
	Lista->inicio = NULL;
	Lista->fim = NULL;
	Lista->total = 0;
}

void inserirDisco(TLista *Lista){
	
	TDisco *novo = (TDisco *) malloc (sizeof(TDisco));
	TDisco *aux = Lista->inicio;
	
	printf("\n\n\t ================| CADASTRO DE DISCO |=================== \n\n");
	
	printf("\t Informe o Nome do Disco: ");
	fflush(stdin);
	gets(novo->titulo);
	
	printf("\n\t Informe o Ano: ");
	fflush(stdin);
	gets(novo->ano);
	
	novo->prox = NULL;
	novo->ante = NULL;
	novo->part = NULL;
	
	if (Lista->inicio == NULL){
		
		Lista->inicio = novo;
		Lista->fim = novo;
		Lista->total = 1;
		
	} else{
		
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
		novo->ante = aux;
		Lista->fim = novo;
		Lista->total++;
	} 		
	
	printf("\n\n\t\t DISCO INSERIDO!\n\n");
	system("PAUSE");
}

void alterarDisco(TLista *Lista){
	
	TDisco *aux = Lista->inicio;
	int disco;
	
	listarDisk(*Lista);
	
	printf("\n\n\t Qual disco deseja alterar: ");
	scanf("%d", &disco);
	
	for(int i = 0; i < disco; i++){
		aux = aux->prox;
	}
	
	if(aux == NULL){
		
		printf("\n\n\t\t DISCO INVALIDO!\n");
		
	}else{
		
		aux->titulo[0] = '\0';
		aux->ano[0] = '\0';
		
		printf("\n\n\t Digite o novo titulo do disco: ");
		fflush(stdin);
		gets(aux->titulo);
		
		printf("\n\n\t Digite o novo ano do disco: ");
		fflush(stdin);
		gets(aux->ano);
		
	}
	
	system("PAUSE");
}

void listarDiscos(TLista Lista){
	
	TDisco *aux = Lista.inicio;
	int cont = 0;
	
	printf("\n\n\t=====================| LISTA DE DISCOS |======================\n\n\n");
	
	while(aux != NULL){
		
		printf("\t %d - %s \t[%s]\n", cont++, aux->titulo, aux->ano);
		aux = aux->prox;		
	}
	
	printf("\n\n\t Total de Discos: %d\n\n", Lista.total);
	system("PAUSE");
}

void listarDisk(TLista Lista){
	
	TDisco *aux = Lista.inicio;
	int cont = 0;
	
	printf("\n\n\t=====================| LISTA DE DISCOS |======================\n\n\n");
	
	while(aux != NULL){
		
		printf("\t %d - %s \t[%s]\n", cont++, aux->titulo, aux->ano);
		aux = aux->prox;		
	}
}

void consultarDisco(TLista Lista){
	
	int disco;
	int contArtista = 0;
	int contFaixa = 0;
	int cont = 0;
	TDisco *aux = Lista.inicio;
		
	listarDisk(Lista);
	
	printf("\n\t Informe o Disco que deseja consultar: ");
	scanf("%d", &disco);
	
	if((disco < 0)||(disco > Lista.total)){
		
		printf("\n\n\t\t DISCO INVALIDO");
		
	}else{
				
		for(int i = 0; i < disco; i++){				// ando com o vetor auxiliar ate o disco informado pelo usuario
			aux = aux->prox;
		}
	
		TArtista *artista = aux->part;
		
		printf("\n\t %d - %s [%s]\n\n", disco, aux->titulo, aux->ano); // estou printando o disco
		
		if(artista == NULL){
			
			printf("\t\t DISCO VAZIO!\n\n");
		
		}else{
		
			do{
				
				printf("\t\tArtista %d: %s\t", contArtista, artista->nome);	
				TFaixa *faixa = artista->faixas;
			
				if(faixa == NULL){
			
					printf("-->\tARTISTA %d SEM FAIXAS!", contArtista);
				
				}else{
					
					do{
						printf("\n\n\t\t\t%d - Titulo: [%s", contFaixa, faixa->titulo);
						
						if((faixa->aoVivo == 1)&&(faixa->instrumental == 1)){
							
							printf(" - Ao Vivo e Instrumental.]");
							
						}else if((faixa->aoVivo == 0)&&(faixa->instrumental == 0)){
							
							printf(" - Gravacao em estudio.]");
							
						}else if((faixa->aoVivo == 1)&&(faixa->instrumental == 0)){
							
							printf(" - Ao Vivo.]");
							
						}else if((faixa->aoVivo == 0)&&(faixa->instrumental == 1)){
							
							printf(" - Instrumental.]");
							
						}else{
							
							printf("\n\t\t FAIXA %d CORROMPIDA!\n\n", contFaixa);
						
						}		
						faixa = faixa->prox;
						contFaixa++;
					
					}while(faixa != NULL);				// estou dentro das faixas				
				}		
				artista = artista->prox; 
				contArtista++;
				contFaixa = 0;
				printf("\n\n");
				
			}while(artista != NULL);
		}
	}
	printf("\n");
	system("PAUSE");
}

void excluirDisco(TLista *Lista){
	
	int disco, cont = 0;
	TDisco *aux = Lista->inicio;
		
	listarDisk(*Lista);
	
	printf("\n\t Informe o Disco que deseja excluir: ");
	scanf("%d", &disco);
	
	if((disco < 0)||(disco >= Lista->total)){
		
		printf("\n\n\t\t ERRO! DISCO NAO ENCONTRADO!!\n\n");
		
	}else{
		
		for(int i = 0; i < disco; i++){
		aux = aux->prox;
		}
		
		excluirArtistaDeDisco(aux);
		
		if((aux->prox == NULL)&&(aux->ante != NULL)){	
			aux->ante->prox = NULL;
			free(aux);
			
		}else if((aux->prox == NULL)&&(aux->ante == NULL)){
			free(aux);
			Lista->inicio = NULL;
			Lista->fim = NULL;
			
		}else if(aux->ante == NULL){
			Lista->inicio = aux->prox;
			aux->prox->ante = NULL;
			free(aux);
			
		}else{
			aux->ante->prox = aux->prox;
			aux->prox->ante = aux->ante;
			free(aux);
		}
		printf("\n\n\t DISCO EXCLUIDO!\n\n");
		Lista->total--;
	}
	system("PAUSE");
}

void ordenarDiscoCres(TLista *Lista){

	TDisco *aux = Lista->inicio;
	TDisco *proximo, *atual;
	
	while(aux != NULL){
		
		proximo = aux->prox;
		
		while(proximo != NULL){
			
			if(strcmp(aux->titulo, proximo->titulo)== 1) {
				
				strcpy(atual->titulo, aux->titulo);
				strcpy(atual->ano, aux->ano);
				atual->part = aux->part;
				
				strcpy(aux->titulo,proximo->titulo);
				strcpy(aux->ano,proximo->ano);
				aux->part = proximo->part;
				
				strcpy(proximo->titulo, atual->titulo);
				strcpy(proximo->ano, atual->ano);
				proximo->part = atual->part;
				
			}
			proximo = proximo->prox;
		}
		aux = aux->prox;
	}
	printf("\n\t\t DISCO ORDENADO!!\n\n");
	system("PAUSE");	
}

void ordenarDiscoDec(TLista *Lista){
	
	TDisco *aux = Lista->inicio;
	TDisco *proximo, *atual;
	
	while(aux != NULL){
		
		proximo = aux->prox;
		
		while(proximo != NULL){
			
			if(strcmp(aux->titulo, proximo->titulo)== -1) {
				
				strcpy(atual->titulo, aux->titulo);
				strcpy(atual->ano, aux->ano);
				atual->part = aux->part;
				
				strcpy(aux->titulo,proximo->titulo);
				strcpy(aux->ano,proximo->ano);
				aux->part = proximo->part;
				
				strcpy(proximo->titulo, atual->titulo);
				strcpy(proximo->ano, atual->ano);
				proximo->part = atual->part;
				
			}
			proximo = proximo->prox;
		}
		aux = aux->prox;
	}
	printf("\n\t\t DISCO ORDENADO!!\n\n");
	system("PAUSE");	
}

void inserirArtista(TLista *Lista){
	
	TDisco *aux = Lista->inicio;
	TArtista *novo = (TArtista *) malloc (sizeof(TArtista));
	int cont = 0;
	int disco;
	
	novo->prox = NULL;
	novo->faixas = NULL;
	
	listarDisk(*Lista);
	
	printf("\n\n\t Informe em qual disco ira inserir o Artista: ");
	scanf("%d", &disco);

	if((disco < 0)||(disco >= Lista->total)){
		
		printf("\n\t\t DISCO INVALIDO!\n\n");
		
	}else{
		
		for(int i = 0; i < disco; i++){
			aux = aux->prox;
		}

		printf("\n\n\t Informe o nome do Artista: ");
		fflush(stdin);
		gets(novo->nome);
		
		if(aux->part == NULL){
		
			aux->part = novo;
		
		} else{	
		
			TArtista *corrente = aux->part;
			
			while(corrente->prox != NULL){
				corrente = corrente->prox;
			}
			corrente->prox = novo;	
		}
		
		printf("\n\n\t\t ARTISTA INSERIDO!\n\n");	
	}
	system("PAUSE");
}

void listarArtista(TLista Lista){
	
	int cont = 0;
	int disco;
	TDisco *aux = Lista.inicio;
	
	listarDisk(Lista);
	
	printf("\n\t Informe o Disco desejado: ");
	scanf("%d", &disco);
	
	if((disco < 0)||(disco >= Lista.total)){
		
		printf("\n\t\t DISCO INVALIDO!\n");
			
	}else{
		
		for(int i = 0; i < disco; i++){
			aux = aux->prox;
		}
	
		TArtista *artista = aux->part;
		
		if(artista == NULL){
			
			printf("\n\t\t DISCO SEM ARTISTAS!\n\n");
			
		}else{
			
			do{
				printf("\n\t %d - [%s]", cont++, artista->nome);
				artista = artista->prox;	
				
			}while(artista != NULL);
		}
	}
	printf("\n\n");
	system("PAUSE");
}

void excluirArtista(TLista *Lista){
	
	int disco;
	int artista;
	int cont = 0;
	TDisco *aux = Lista->inicio;
	TArtista *proximo, *artistas;
	TFaixa *faixa;
	
	listarDisk(*Lista);
	
	printf("\n\t Informe o Disco que contem o Artista que deseja excluir: ");
	scanf("%d", &disco);
	
	if((disco < 0)||(disco >= Lista->total)){
		
		printf("\n\t\t DISCO INVALIDO!\n\n");
	
	}else{
		
		for(int i = 0; i < disco; i++){
			aux = aux->prox;
		}
			
		artistas = aux->part;	
			
		if(artistas == NULL){
		
			printf("\n\n\t\t DISCO SEM ARTISTAS!\n");
		
		} else{
		
			while(artistas != NULL){
			
				printf("\n\t %d - [%s]\t\n", cont++, artistas->nome);
				artistas = artistas->prox;		
			}
			
			artistas = aux->part;
		
			printf("\n\t Informe o Artista que deseja excluir: ");
			scanf("%d", &artista);
		
			if((artista < 0)||(artista > cont)){
				
				printf("\n\n\t\t ARTISTA INVALIDO!\n");
				
			}else{
				
				if (artista == 0){
			
					if(aux->part->faixas == NULL){
				
						proximo = aux->part;
						aux->part = aux->part->prox;
						free(proximo);
				
					}else{
					
						excluirFaixa(aux->part);
				
						proximo = aux->part;
						aux->part = aux->part->prox;
						free(proximo);
					}
				}else{
				
					for(int i = 0; i < artista; i++){
						aux->part = aux->part->prox;
					}	
				
					if(aux->part->faixas == NULL){
					
						proximo = aux->part;
						aux->part = aux->part->prox;
						free(proximo);
					
					}else{
					
						excluirFaixa(aux->part);
						
						proximo = aux->part->prox;
						aux->part->prox = aux->part->prox->prox;
						free(proximo);
					}
				}	
				printf("\n\n\t\t ARTISTA EXCLUIDO!\n");	
			}
		}	
	}
	system("PAUSE");
}

void excluirArtistaDeDisco(TDisco *disco){
	
	int cont = 0;
	TArtista *atual;
	TFaixa *faixa;
		
	if (disco->part == NULL){
		
		printf("\n\n\t DISCO SEM ARTISTAS!\n\n");
		
	}else{
			
		while(disco->part != NULL){
			
			if(disco->part->faixas == NULL){
			
				atual = disco->part;
				disco->part = disco->part->prox;
				free(atual);
			
				printf("\n\n\t ARTISTA %d SEM FAIXAS!\n\n", cont++);
				printf("\n\n\t ARTISTA %d EXCLUIDO!\n\n", cont);
			
			}else{
			
				do{	
					faixa = disco->part->faixas;
					disco->part->faixas = disco->part->faixas->prox;
					free(faixa);
			
				}while(disco->part->faixas != NULL);
			
				atual = disco->part;
				disco->part = disco->part->prox;
				free(atual);
				printf("\n\n\t EXCLUINDO FAIXAS DE ARTISTA!\n\n");
				printf("\n\n\t ARTISTA %d EXCLUIDO!\n\n", cont++);		
			}
		}	
	}		
}

void inserirFaixa(TLista *Lista){
	
	TDisco *aux = Lista->inicio;
	TFaixa *novo = (TFaixa *) malloc (sizeof(TFaixa));
	int cont = 0;
	int disco;
	int artista;
	
	novo->prox = NULL;
	novo->aoVivo = 0;
	novo->instrumental = 0;
	
	listarDisk(*Lista);
	
	printf("\n\n\t Informe em qual disco ira inserir a Faixa: ");
	scanf("%d", &disco);
	
	if((disco < 0)||(disco >= Lista->total)){
		
		printf("\n\n\t\t DISCO INVALIDO!\n");
		
	}else{
	
		for(int i = 0; i < disco; i++){
			aux = aux->prox;
		}
		
		TArtista *artistas = aux->part;
	
		if(artistas == NULL){
		
			printf("\n\n\t\t DISCO SEM ARTISTAS!\n\n");
	
		}else{
			
			do{
				printf("\n\t %d - [%s]", cont++, artistas->nome);
				artistas = artistas->prox;	
				
			}while(artistas != NULL);
			
			artistas = aux->part;
			
			printf("\n\n\t Informe em qual Artista ira inserir a Faixa: ");
			scanf("%d", &artista);
			
			for(int i = 0; i < artista; i++){
				artistas = artistas->prox;
			}	
			
			TFaixa *faixa = artistas->faixas;
			
			printf("\n\n\t Informe o nome da Faixa: ");
			fflush(stdin);
			gets(novo->titulo);
		
			printf("\n\t 1 = SIM \t 0 = NAO");
	
			printf("\n\n\t Ao Vivo: ");
			scanf("%d", &novo->aoVivo);
	
			printf("\n\n\t Instrumental: ");
			scanf("%d", &novo->instrumental);
	
			if(faixa == NULL){
				artistas->faixas = novo;
		
			} else{
				
				TFaixa *atual = faixa;
							
				while(atual->prox != NULL){
					atual = atual->prox;
				}
				atual->prox = novo;		
			}		
		}	
	}
	printf("\n\n");
	system("PAUSE");
}

void excluirFaixa(TArtista *artista){
	
	TFaixa *faixa;
	
	if (artista->faixas == NULL){
			
		printf("\n\n\t DISCO SEM ARTISTAS!\n\n");
			
	}else{
			
		do{
			faixa = artista->faixas;
			artista->faixas = artista->faixas->prox;					// excluindo faixas do artista
			free(faixa);
					
		}while(artista->faixas != NULL);
		printf("\n\n\t FAIXAS EXCLUIDAS!\n\n");
	}			
}

void listarFaixaDisco(TLista Lista){
	
	int disco, cont = 0;
	TDisco *aux = Lista.inicio;
	
	listarDisk(Lista);
	
	printf("\n\n\tInforme o disco desejado: ");
	scanf("%d", &disco);
	
	for(int i = 0; i < disco; i++){
		aux = aux->prox;
	}
	

	if(aux == NULL){
		
		printf("\n\n\t\t DISCO INVALIDO!\n");
	
	}else{

		TArtista *artista = aux->part;
		TFaixa *faixa = artista->faixas;
		
		printf("\n");
		while(artista != NULL){
			
			while(faixa != NULL){
				
				printf("\n\t %d - [%s", cont++, faixa->titulo);
				
				if((faixa->aoVivo == 1)&&(faixa->instrumental == 1)){
						
					printf(" - Ao Vivo e Instrumental.]");
						
				}else if((faixa->aoVivo == 0)&&(faixa->instrumental == 0)){
						
					printf(" - Gravacao em estudio.]");
						
				}else if((faixa->aoVivo == 1)&&(faixa->instrumental == 0)){
						
					printf(" - Ao Vivo.]");
						
				}else if((faixa->aoVivo == 0)&&(faixa->instrumental == 1)){
							
					printf(" - Instrumental.]");
				}
				faixa = faixa->prox;
			}
			artista = artista->prox;
		}		
	}
	printf("\n\n");
	system("PAUSE");	
}

void listarFaixaArtista(TLista Lista){

	int cont = 0;
	TDisco *aux = Lista.inicio;
	
	char artista[50];
	artista[0] = '\0';
	
	printf("\n\n\t Informe o nome do artista: ");
	fflush(stdin);
	gets(artista);
	
	if(aux == NULL){
		
		printf("\n\n\t\t LISTA SEM DISCOS!\n");
	
	}else{
		
		printf("\n");
		while(aux != NULL){
			
			TArtista *artistas = aux->part;
			
			while(artistas != NULL){
				
				TFaixa *faixa = artistas->faixas;
				
				if(strcmp(artista, artistas->nome)==0){
					
					while(faixa != NULL){
					
						printf("\n\t %d - Faixa: [%s", cont++, faixa->titulo);
						
						if((faixa->aoVivo == 1)&&(faixa->instrumental == 1)){
						
							printf(" - Ao Vivo e Instrumental.]");
						
						}else if((faixa->aoVivo == 0)&&(faixa->instrumental == 0)){
						
							printf(" - Gravacao em estudio.]");
						
						}else if((faixa->aoVivo == 1)&&(faixa->instrumental == 0)){
						
							printf(" - Ao Vivo.]");
						
						}else if((faixa->aoVivo == 0)&&(faixa->instrumental == 1)){
							
							printf(" - Instrumental.]");
						}
						faixa = faixa->prox;
					}
				}	
				artistas = artistas->prox;
			}
			aux = aux->prox;	
		}	
	}
	printf("\n\n");
	system("PAUSE");		
}

void listarTotalFaixasPorDisco(TLista Lista){
	
	TDisco *aux = Lista.inicio;
	int cont = 0, contFaixa = 0;

	if(aux == NULL){
		
		printf("\n\n\t\t LISTA SEM DISCOS!\n");
	
	}else{
	
		printf("\n");
		
		while(aux != NULL){
			
			TArtista *artista = aux->part;
			printf("\n\t\t Disco %d: ", cont++);
			
			while(artista != NULL){
				
				TFaixa *faixa = artista->faixas;
				while(faixa != NULL){
					
					contFaixa++;
		
					faixa = faixa->prox;
				}
				artista = artista->prox;
			}
			printf("%d Faixas.\n", contFaixa);
			contFaixa = 0;
			aux = aux->prox;	
		}	
	}
	printf("\n");	
	system("PAUSE");
}

void listarTotalFaixasPorArtista(TLista Lista){
	
	TList List;
	TArt *art;
	
	List.inicio = NULL;
	List.fim = NULL;
	List.total = 0;
	
	TDisco *aux = Lista.inicio;
	int cont = 0;
	int i = 0;
	TArtista *artista;
	TFaixa *faixa;
	
	if(aux == NULL){
		
		printf("\n\n\t\t LISTA VAZIA!\n\n");
	
	}else{		
	
		printf("\n");
		while(aux != NULL){

			i = 1;
			artista = aux->part;
			
			while(artista != NULL){
				
			    art = buscarArtista(List, artista->nome);
					
				if(art==NULL){
					
					TArt *novo = (TArt *) malloc (sizeof(TArt));
					strcpy(novo->nome, artista->nome);
					novo->faixas = 0;
					novo->prox = NULL;
					
					if(List.inicio == NULL){
					
						List.fim = novo;
						List.inicio = novo;
						
					}else{
						
						List.fim->prox = novo;
						List.fim = novo;	
					}
					art = novo;	
				}
		
				faixa = artista->faixas;
				
				while(faixa != NULL){
				   	art->faixas++; 	
					faixa = faixa->prox;
				}	
				artista = artista->prox;
			}
			aux = aux->prox;	
		}
	}	
	
	if(i == 0){
		printf("\n\n\t\t DISCOS VAZIOS!\n\n");
		
	}else{
		
		art = List.inicio;
		while(art != NULL){
		
			printf("\n\n\t %d - %s: %d Faixas.\n", cont++, art->nome, art->faixas);
			art = art->prox;
		}	
	}
	system("PAUSE");
}

void listarArtistaPorFaixa(TLista Lista){
	
	int cont = 0;
	TDisco *aux = Lista.inicio;
	
	char faixa[50];
	faixa[0] = '\0';
	
	printf("\n\n\t Informe o titulo da Faixa: ");
	fflush(stdin);
	gets(faixa);
	
	if(aux == NULL){
		
		printf("\n\n\t\t LISTA SEM DISCOS!\n\n");
		system("PAUSE");
	
	}else{
		
		TArtista *artista = aux->part;
		TFaixa *fx = artista->faixas;
		
		printf("\n\n\tFaixa - %s:\n", faixa);
		
		while(aux != NULL){
			
			while(artista != NULL){
				
				while(fx != NULL){
						
					if(strcmp(faixa, fx->titulo)==0){
							
						printf("\n\t\t %d - %s.", cont++, artista->nome);
					}
					fx = fx->prox;	
				}
			artista = artista->prox;
			}
		aux = aux->prox;	
		}
		printf("\n\n\t\t %d Artistas cantam essa Faixa.\n\n", cont);	
	}
	system("PAUSE");
}

TArt *buscarArtista(TList List, char *artista){
	
	TArt *aux = List.inicio;
	TArt *retorno = NULL;
	
	while(aux != NULL){
		
		if(strcmp(artista, aux->nome)==0){
			
			retorno = aux;
			break;
		}
		aux = aux->prox;
	}
	return retorno;
}



