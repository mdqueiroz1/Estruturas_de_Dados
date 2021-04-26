#include <stdio.h>
#include <stdlib.h>

typedef struct sDEQUE{
    int info;
    struct sDEQUE *dir;
    struct sDEQUE *esq;
    struct sDEQUE *inicio;
    struct sDEQUE *final;
}DEQUE;

DEQUE* alocaDeque(){
    return (DEQUE*) malloc(sizeof(DEQUE));
}

int dequeVazia(DEQUE *ptrD){
    if (ptrD == NULL) return 1;
    if (ptrD->inicio == NULL) return 1;
    return 0;
}

void insereInicioDeque(DEQUE **ptrD, int elem){
    if(*ptrD == NULL) return 0;
    
    DEQUE *novo;
    novo = alocaDeque();
    if(novo == NULL) return 0;

    novo->info = elem;
    novo->dir = (*ptrD)->inicio;
    novo->esq = NULL;
    if((*ptrD)->inicio == NULL) 
        (*ptrD)->final = novo;
    else 
        (*ptrD)->inicio->esq = novo;

    (*ptrD)->inicio = novo;
}

void insereFinalDeque(DEQUE **ptrD, int elem){
    if(*ptrD == NULL) return 0;

    DEQUE *novo;
    novo = alocaDeque();
    if(novo == NULL) return 0;

    novo->info = elem;
    novo->dir = NULL;
    
    if((*ptrD)->final == NULL){
        novo->esq = NULL;
        (*ptrD)->inicio = novo;
    }else{
        novo->esq = (*ptrD)->final;
        (*ptrD)->final->dir = novo;
    }

    (*ptrD)->final = novo;
}