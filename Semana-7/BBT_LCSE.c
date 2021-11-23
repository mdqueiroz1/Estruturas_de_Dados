 #include<stdio.h>
#include<stdlib.h>

typedef struct sNO{
    int info;
    struct sNO *dir;
}NO;

void init(NO **ptrLista){
    *ptrLista = NULL;
}

void desalocarNo(NO *lista){
    free(lista);
}

void inserirFim (NO **lista, int elem){
    NO *novo;

    novo = alocarNo();
    if(novo != NULL){
        novo->info = elem;
        if(vazia(*lista)){
            novo->dir = novo;    
        }else{
            novo->dir = (*lista)->dir;
            (*lista)->dir = novo;
        }
        *lista = novo;
    }else{
        printf("Erro de alocacao do no");
        exit(1);
    }
}

void removerInicio(NO **lista){
    NO *aux;
    if(!vazia(*lista)){
        if((*lista) == (*lista)->dir){
            desalocarNo(*lista);
            *lista = NULL;
        }else{
            aux = (*lista)->dir;
            (*lista)->dir = aux->dir;
            desalocarNo(aux);
        }
    }else{
        printf("Erro, lista vazia\n");
        exit(1);
    }
}

