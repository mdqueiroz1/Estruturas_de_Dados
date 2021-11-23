#include <stdio.h>
#include <stdlib.h>

#include "BBT_Pilha.c"

int menu(pilha **ptrP){
    
    int loop, elem;

    printf("1-Inserir no inicio.\n");
    printf("2-Remover do inicio.\n");
    printf("3-Exibir elementos do modo nao classico.\n");
    printf("4-Exibir elementos do modo classico\n");
    scanf("%d", &loop);
    switch (loop){
        case 1:{
            printf("Informe o numero:\n");
            scanf("%d", &elem);
            inserePilha(ptrP, elem);
            break;
        }
        case 2:{
            removePilha(ptrP);
            break;
        }
        case 3:{
            listaNaoClassico(*ptrP);
            break;
        }
        case 4:{
            listaClassico(*ptrP);
            break;
        }

    }
    return loop;
}

int main(){
    
    pilha *ptrP;
    init(ptrP);
    
    int loop;

    do{
        loop = menu(&ptrP);
    }while(loop != 9);
    
    return 0;
}
