#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BBT_ListaCircular.c"

int menu(NO **ptrNo){
	int opcMenu;
	printf("1-Inserir no inicio da lista\n");
	printf("2-Remover elemento do final da lista\n");
	printf("3-Exibir todos os elementos da lista\n");
	scanf("%d", &opcMenu);
	switch(opcMenu){
		case 1:{
			char elem[20];
			int mes;

			fflush(stdin);
			printf("Qual a cultura a ser cultivada?\n");
			fgets(elem, 20, stdin);
			fflush(stdin);
			
			printf("Em qual mes %s deve ser cultivado?\n",elem);
			scanf("%d", &mes);
			
			inserirInicio(ptrNo, elem, mes);
			
			break;
		}
		case 2:{
			removerFinal(ptrNo);
			break;
		}
		case 3:{
			imprimirLista(*ptrNo);
			break;
		}
	}
	return opcMenu;
}

int main(){
	
	NO *ptrNo = inicializarLista();

	int loopMenu;

	do{
		loopMenu = menu(&ptrNo);	
	}while(loopMenu != 9);
	
	return 0;
}