#include<stdio.h>

int menu(){
	int x,teste;
	printf("1-Inserir\n");
	printf("2-Remover\n");
	printf("3-Listar\n");
	printf("9-Finalizar programa.\n");
	scanf("%d",&x);

	switch(x){
		case 1:{
			scanf("%d",&teste);
			printf("%d\n",teste);
			break;
		}
		case 9:{
			return x;
		}
		default:{
			printf("Numero invalido\n");
			return 1;
		}
	}

	return 0;
}

int main(){

	int testemenu;

	do{
		menu();
	}while ((testemenu = menu())!= 9);


	return 0;
}