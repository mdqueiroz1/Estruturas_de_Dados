#include <stdio.h>
#include <stdlib.h>

#include "BBT_DequeEstatico.c"

int menu(DEQUE *prtD){
    
    int loop;

    printf("1-Inserir no inicio.\n");
    printf("2-Inserir no final.\n");
    printf("3-Remover do inicio.\n");
    printf("4-Remover do final.\n");
    printf("5-Exibir elementos do modo nao classico.\n");
    printf("6-Exibir elementos do modo classico");
    scanf("%d", &loop);
    switch (loop){
        case 1:{
            inserirInicio();
            break;
        }
        case 2:{
            inserirFinal();
            break;
        }
        case 3:{
            removerInicio();
            break;
        }
        case 4:{
            removerFinal();
            break;
        }
        case 5:{
            listaNaoClassico();
            break;
        }
        case 6:{
            listaClassico();
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
