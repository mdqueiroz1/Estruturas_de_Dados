#include <stdio.h>
#include <stdlib.h>

typedef struct sProcesso{
    
    char processoNome[20];
    int processoNum;

}processo;

typedef struct sNo{
    
    processo info;
    struct sNo *prox;

}NO;


void inicializar ( NO **lista ){

    *lista = *lista;
    (*lista)->info.processoNum = 0;
}

int lista_vazia( NO *lista ){

    if( lista->info.processoNum == 0 ) return 1;

    return 0;

}