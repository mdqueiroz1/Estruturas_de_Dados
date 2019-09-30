#include <stdio.h>
#define TAML 10

typedef struct sLISTA{
	int info[TAML];
	int n;
}LISTA;

void init(LISTA *L){
	L->n= -1;
}

int main(){
	
	LISTA lista;

	init(&lista);



	return 0;
}