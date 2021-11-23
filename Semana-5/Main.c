#include<stdio.h>
#include<stdlib.h>
#include"BBT_ListaDinamica.c"
int menu(no *ptrNo){
    int opcMenu;

    printf("1- Inserir no inicio da lista\n");
    printf("2- Inserir no final da lista\n");
    printf("3- Remover do inicio da lista\n");
    printf("4- Remover elemento X da lista\n");
    printf("5- Listar elementos da lista\n");
    printf("9- Sair do programa.\n");
    scanf("%d",&opcMenu);

    switch (opcMenu){
        
    case 1:{
        char elem;
        printf("Qual o caractere a ser inserido no inicio da lista:\n");
        scanf("%c", &elem);
        inserirInicio(ptrNo,elem);
        break;
    }
    case 2:{
        char elem;
        printf("Qual o caractere a ser inserido no final da lista:\n");
        scanf("%c", &elem);        
        inserirFim(ptrNo,elem);
        break;
    }
    case 3:{
        removeInicio(ptrNo);
        break;
    }

    case 4:{
        char elem;
        printf("Qual o caractere a ser removido da lista:\n");
        scanf("%c", &elem);        
        removeValor(ptrNo,elem);
        break;
    }
    
    case 5:{
        imprimeLista(ptrNo);
        break;
    }
    default:
        printf("Fora das opcoes disponiveis.");
        break;
    }
    return opcMenu;
}


int main(){
    
    no *ptrNo;
    
    int flag;

    do{
        flag = menu(ptrNo); 
    }while(flag != 9);

    return 0;
}
