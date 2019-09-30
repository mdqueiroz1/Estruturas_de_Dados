#include <stdio.h>
#include <stdlib.h>
#define TAML 10;
#define EXIT_SUCCESS 0;
#define EXIT_ERROR 1;

typedef struct sLISTA
{
	char caractere[TAML];
	int n;
}LISTA;

void inicia_lista(LISTA *L){
	L->n = -1;
}

int lista_vazia(LISTA *L){
	if (L->n == -1)
		return EXIT_ERROR;
	else
		return EXIT_SUCCESS;
}

int lista_cheia(LISTA *L){
	if(L->n == TAML+1);
		return EXIT_ERROR;
	else
		return EXIT_SUCCESS;
}

int lista_inserirfim(LISTA *L, char elem){
	if (lista_cheia(L)){
		printf("Erro, lista cheia!\n");
		return EXIT_ERROR;
	}
	L-> valor[L->n+1]= elem;
	L-> n = L-> n+1;

	return EXIT_SUCCESS;
}

int lista_inserir(LISTA *L, int k, char elem){
	if(lista_cheia(L)){
		printf("Erro, lista cheia!\n");
		return EXIT_ERROR;
	}
	if(k < 0 || k> L->n+1){
		printf("Erro, elemento fora dos limites\n");
		return EXIT_ERROR;
	}
	int i;
	for(i=(L->n+1);i>k;i--){
		L->valor[i] = L->valor[i-1];
	}
	L->valor[k] = elem;
	L-> n = L->n+1;

	return EXIT_SUCCESS;
}

int lista_modificar(LISTA *L, int k, char elem){
	if( k < 0 || k> l->n){
		printf("Erro, elemento fora dos limites\n");
		return EXIT_ERROR;
	}
	L->valor[k] = elem;
	return EXIT_SUCCESS;
}

int lista_remover(LISTA *L, int k){
	if(lista_vazia(L)){
		printf("Erro, lista vazia\n");
		return EXIT_ERROR;
	}
	if(k<0 || k > L->n){
		printf("Erro, elemento fora dos limites\n");
		return EXIT_ERROR;
	}

	for(int i=k;i<(L->n);i++){
		L->valor[i]= L->valor[i+1];
	}

	L-> n= L-> n-1;
	return EXIT_SUCCESS;
}

char lista_acessar(LISTA *L, int k){
	if(  (k<0) || (k>(l->n))  ){
		printf("Erro, elemento fora dos limites\n");
		return EXIT_ERROR;
	}else
		return (L->valor[k]);
}

int lista_buscar(LISTA *L, char val_b){
	int elem = -1;
	int i = 0;

	while (i<= (L->n)){
		if (val_b == L-> valor[i]){
			elem = i;
			break;
		}
		i++;
	}
	return elem;//exit success.
}

int lista_tamanho(LISTA *L){
	return L->n+1;
}

int main(){

	LISTA *L;
	L= (LISTA *) malloc(sizeof(LISTA));
	//(LISTA*)= declaração explicita do tipo da struct.
	if(L == NULL){
		printf("Erro ao alocar!\n\n");
		return EXIT_SUCCESS;
	}

	inicia_lista(L);


	return EXIT_SUCCESS;
}
