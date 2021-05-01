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
    if(*ptrD == NULL) return;
    
    DEQUE *novo;
    novo = alocaDeque();
    if(novo == NULL) {
        printf("Não foi alocado.\n");
        return;
    }
    novo->info = elem;
    novo->dir = (*ptrD)->inicio;
    novo->esq = NULL;
    if((*ptrD)->inicio == NULL) {
        (*ptrD)->final = novo;
        printf("adicionou no inicio\n");
    }else {
        (*ptrD)->inicio->esq = novo;
        printf("adicionou depois do inicio\n");
    }

    (*ptrD)->inicio = novo;
}

void insereFinalDeque(DEQUE **ptrD, int elem){
    if(*ptrD == NULL) return;

    DEQUE *novo;
    novo = alocaDeque();
    if(novo == NULL) return;

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

void removeInicioDeque(DEQUE **ptrD){
    if(*ptrD == NULL) return;
    if((*ptrD)->inicio == NULL) return;

    DEQUE *aux = (*ptrD)->inicio;
    (*ptrD)->inicio = (*ptrD)->inicio->dir;
    if((*ptrD)->inicio == NULL)
        (*ptrD)->final = NULL;
    else
        (*ptrD)->inicio->esq = NULL;
    free(aux);
}

void removeFinalDeque(DEQUE **ptrD){
    if(*ptrD == NULL) return;
    if((*ptrD)->inicio == NULL) return;

    DEQUE *aux = (*ptrD)->final;
    if(aux == (*ptrD)->inicio){
        (*ptrD)->inicio = NULL;
        (*ptrD)->final = NULL;
    }else{
        aux->esq->dir = NULL;
        (*ptrD)->final = aux->dir;
    }
    free(aux);
}

void listaNaoClassico(DEQUE *ptrD){
    DEQUE *aux;
    aux = ptrD;
    if(dequeVazia(ptrD)) return;
    
    while(aux != NULL){
        printf("%d\t", aux->info);
        aux = aux->dir;
    }
    printf("\n");
}

void listaClassico(DEQUE *ptrD){
    return;
}