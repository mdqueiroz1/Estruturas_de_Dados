#include<stdio.h>
#include<stdlib.h>
#define TAML 10

typedef struct sLISTA{
	char info[TAML];
	int n;
}LISTA;

void init(LISTA *L){
	
	L->n = -1;
}

int vazia(LISTA *L){
	if(L->n == -1)
		return 1;
	else
		return 0;
}

int cheia(LISTA *L){
	if(L-> n+1 == TAML)
		return 1;
	else
		return 0;
}

int inserir_fim(LISTA *L, char elem){
	if(cheia(L)){
		printf("Lista cheia.\n");
		return 1;
	}
	L->info[L->n+1] = elem;
	L->n = L->n+1;

	return 0;
}

int remover_fim(LISTA *L){
	if(vazia(L)){
		printf("lista vazia.\n");
		return 1;
	}else{
		printf("Elemento %c removido\n\n", L->info[(L->n)]);
		L->n = L->n-1;
		return 0;
	}

}

int modificar(LISTA *L, int k, char elem){
	if(k<0 || k> L->n){
		printf("erro, elemento fora dos limites\n");
		return 1;
	}
	L->info[k] = elem;

	return 0;
}
void listar_elementos(LISTA *L){
	int i;
	if(vazia(L)){
		printf("lista vazia\n");
	}else{
		printf("ELEMENTOS NA LISTA:\n");
		for(i=0;i<=(L->n);i++){
			printf("%c\t", L->info[i]);
		}
		printf("\n\n");
	}

}

int menu(LISTA *L){
	int x, pos;
	char elem;
	
	printf("1-Inserir elemento\n");
	printf("2-Remover elemento\n");
	printf("3-Alterar elemento\n");
	printf("4-Listar elementos\n");
	printf("9-Finalizar programa\n");
	scanf("%d", &x);

	switch(x){
		case 1:{
			printf("Elemento a ser adicionado:\n");
			fflush(stdin);
			scanf("%s", &elem);
			inserir_fim(L, elem);
			break;
		}
		case 2:{
			remover_fim(L);
			break;
		}
		case 3:{
			printf("Qual a posicao a ser trocada?\n");
			scanf("%d", &pos);
			
			if (pos > L->n || pos < 0){
				printf("Fora de posicao\n");
				break;
			}else{
				printf("Elemento a ser inserido\n");
				fflush(stdin);
				scanf("%s", &elem);
			}
			
			modificar(L,pos,elem);
			break;
		}
		case 4:{
			listar_elementos(L);
			break;
		}

		case 9:{
			return x;
		}
		default:{
			printf("numero fora da lista.\n");
			return 1;
		}
	}
	return x;
}

int main(){

	int testeMenu;
	LISTA *ptrlista;

	ptrlista= (LISTA*) malloc(sizeof(LISTA));
	init(ptrlista);

	do{
		menu(ptrlista);
	}while ((testeMenu=menu(ptrlista)) != 9);

	return 0;

}