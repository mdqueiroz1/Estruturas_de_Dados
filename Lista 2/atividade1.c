#include<stdio.h>
#include<stdlib.h>
#define EXIT_ERROR 1
#define EXIT_SUCCESS 0

typedef struct sCELULA
{
 int info;
 struct sCELULA *next;
}CELULA;


void init (CELULA **lista){
	*lista = NULL;
}

CELULA* getnode(){
	return (CELULA *) malloc(sizeof(CELULA));
}

void freenode(CELULA *q){
	free(q);
}

int empty(CELULA *lista){
	if (lista == NULL)
		return EXIT_ERROR;

	return EXIT_SUCCESS;
}

CELULA pesquisa(CELULA *lista, int x){
	CELULA *q;

	if(!empty(lista)){
		q=lista;
		while(q!= NULL){
			if(q->info == x)
				return q;

			q = q->next;
		}
	}
	return NULL; //no nao encontrado
}

void insere_inicio(CELULA **lista, int x){
	CELULA *q;
	
	q=getnode();
	if(q != NULL){
		q->info=x;
		q->next= *lista;
		*lista = q;
	}else{
		printf("\nErro. falha na alocacao\n");
		exit(EXIT_ERROR);
	}
}

void insere_final(CELULA **lista, int x){
	CELULA *q;
	CELULA *aux;

	q=getnode();
	if(q!=NULL){
		q->info=x;
		q->next=NULL;
		if(empty(*lista)){
			*lista=q;
		}else{
			aux = *lista;
			while(aux->next !=NULL)
				aux=aux->next;

			aux->next=q;
		}
	}else{
		printf("Erro na alocacao\n");
		exit(EXIT_ERROR);
	}

}

void remove_inicio(CELULA **lista){
	CELULA *q;

	q= *lista;
	if(!empty(*lista)){
		*lista = q->next;
		freenode(q);
	}else{
		printf("Erro, lista vazia\n");
		exit(EXIT_ERROR);
	}
}

int remove_elemento(CELULA **lista, int x){
	CELULA *q;
	CELULA *aux;

	if ((q= pesquisa(*lista, x)) != NULL){
		aux = *lista;
		if(aux == q){
			remove_inicio(lista);
		}else{
			while(aux->next != q)
				aux = aux->next;
			aux->next =q->next;
			freenode(q);
		}
		return EXIT_SUCCESS;
	}
	return EXIT_ERROR;
}

void listar_elementos(CELULA *lista){
	CELULA *aux;

	aux=lista;
	while(aux != NULL){
		printf("%d\t",aux->info);
		aux=aux->next;
	}
	printf("\n");
}

int menu(CELULA **lista){
	int menu;
	printf("1-Inserir um elemento no inicio da lista\n");
	printf("2-Inserir um elemento no final da lista\n");
	printf("3-Remover um elemento do inicio da lista\n");
	printf("4-Remover um determinado elemento da lista;\n");
	printf("5-Exibir os elementos da lista.\n");
	printf("9-Finalizar programa\n");
	scanf("%d", &menu);
	switch(menu){
		
		case 1:{
			int x;

			printf("Inteiro a ser inserido:\n");
			scanf("%d", &x);
			
			insere_inicio(&lista, x);
		}
		
		case 2:{
			int x;

			printf("Inteiro a ser inserido:\n");
			scanf("%d", &x);
			
			insere_final(lista, x);
		}

		case 3:{
			remove_inicio(lista);
		}
		case 4:{
			int remove;
			scanf("%d", &remove);
			remove_elemento(lista, remove);
		}
		case 5:{
			listar_elementos(lista);
			break;
		}
		case 9:{
			return menu;
		}
		default:{
			printf("Erro, numero fora do intervalo.\n");
			exit(EXIT_ERROR);
		}
	}
}

int main(){
	
	CELULA* ptrlista;
	int testeMenu;

	init(&ptrlista);
	do{
		testeMenu = menu(&ptrlista);
	}while(testeMenu != 9);

	
	return 0;
}