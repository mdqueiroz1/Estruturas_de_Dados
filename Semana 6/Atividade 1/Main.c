#include <stdio.h>
#include <stdlib.h>
#include "BBT_LDE.c"

int menu(NO **ptrNo){
    int opcMenu;

    printf("1- Inserir no inicio da lista\n");
    printf("2- Inserir no final da lista\n");
    printf("3- Remover do inicio da lista\n");
    printf("4- Remover elemento X da lista\n");
    printf("5- Remover elemento do final da lista\n");
    printf("6- Listar elementos da lista em ordem inversa\n");
    printf("7- Somar todos os elementos da lista\n");
    printf("9- Sair do programa.\n");
    scanf("%d",&opcMenu);

    switch (opcMenu){
        
    case 1:{
        int elem;
        printf("Qual o elemento a ser inserido no inicio da lista:\n");
        scanf("%d", &elem);
        inserirInicio(ptrNo,elem);
        break;
    }
    case 2:{
        int elem;
        printf("Qual o elemento a ser inserido no final da lista:\n");
        scanf("%d", &elem);        
        inserirFim(ptrNo,elem);
        break;
    }
    case 3:{
        removerInicio(ptrNo);
        break;
    }

    case 4:{
        int elem;
        printf("Qual o elemento a ser removido da lista:\n");
        scanf("%d", &elem);        
        removerValor(ptrNo,elem);
        break;
    }
    
    case 5:{
        removerFim(ptrNo);
        break;
    }
    case 6:{
        imprimirLista(*ptrNo);
        break;
    }
    case 7:{
        somarLista(ptrNo);
        break;
    }

    default:
        printf("Fora das opcoes disponiveis.");
        break;
    }
    return opcMenu;
}

int main(){
    NO *ptrNo;
    int loopMenu;
    do
    {
        loopMenu = menu(&ptrNo); 
    } while (loopMenu != 9);
    
     
    return 0;
}
