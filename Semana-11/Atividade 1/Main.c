#include <stdio.h>
#include <stdlib.h>

#include "BBT_DequeEstatico.c"

int menu(DEQUE **ptrD){
    
    int loop, elem;

    printf("1-Inserir no inicio.\n");
    printf("2-Inserir no final.\n");
    printf("3-Remover do inicio.\n");
    printf("4-Remover do final.\n");
    printf("5-Exibir elementos do modo nao classico.\n");
    printf("6-Exibir elementos do modo classico");
    scanf("%d", &loop);
    switch (loop){
        case 1:{
            printf("Informe o numero:\n");
            scanf("%d", &elem);
            inserirInicio(ptrD, elem);
            break;
        }
        case 2:{
            printf("Informe o numero:\n");
            scanf("%d", &elem);            
            inserirFinal(ptrD, elem);
            break;
        }
        case 3:{
            removerInicio(ptrD);
            break;
        }
        case 4:{
            removerFinal(ptrD);
            break;
        }
        case 5:{
            listaNaoClassico(ptrD);
            break;
        }
        case 6:{
            listaClassico(ptrD);
            break;
        }

    }
    return loop;
}


int main(){
    DEQUE *ptrD;
    int loop;
    do{
        loop = menu(ptrD);
    }while(loop != 9);
    return 0;
}
