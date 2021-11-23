#include <stdio.h>
#include <stdlib.h>

#include "BBT_Fila.c"

int menu(Fila *ptrF){
    
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
            insereFila(ptrF, elem);
            break;
        }
        case 2:{
            removeFila(ptrF);
            break;
        }
        case 3:{
            listaNaoClassico(ptrF);
            break;
        }
        case 4:{
            listaClassico(ptrF);
            break;
        }

    }
    return loop;
}

int main(){
    
    Fila ptrF;
    init(&ptrF);
    
    int loop;

    do{
        loop = menu(&ptrF);
    }while(loop != 9);
    return 0;
}
