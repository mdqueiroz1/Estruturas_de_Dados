#include <stdio.h>
#include <stdlib.h>

typedef struct sPilha{
    int info;
    struct sPilha *dir;
}pilha;

pilha* alocaNo(){
    return (pilha*) malloc(sizeof(pilha));
}

void init(pilha *ptrP){
    ptrP->dir = NULL;
    if ( ptrP == NULL ){
        printf("Erro na alocacao do no\n");
        exit(0);
    }
}

int vaziaPilha(pilha *ptrP){
    if ( ptrP->dir == NULL ) return 1;
    return 0;
}

void inserePilha(pilha **ptrP, int elem){
    pilha *novo;
    novo = alocaNo();
    if ( novo == NULL ) return;
    printf("passou!\n");
    novo->info = elem;
    novo->dir = *ptrP;
    
    *ptrP = novo;
}

void removePilha(pilha **ptrP){
    if(vaziaPilha(*ptrP)) {
        printf("Lista Vazia!\n");
        return;
    }
    
    pilha *aux;
    aux = *ptrP;
    
    *ptrP = aux->dir;
    
    free(aux);
}

void listaClassico(pilha *ptrP){
    if(vaziaPilha(ptrP)){
        printf("Lista vazia!\n");
        return;
    }
    
    pilha *aux;

    while(ptrP != NULL){
        printf("%d\n", ptrP->info);
        aux = ptrP;
        ptrP = ptrP->dir;
        removePilha(aux);
    }
}

void listaNaoClassico(pilha *ptrP){
    if(vaziaPilha(ptrP)){
        printf("Lista vazia!\n");
        return;
    }
    
    pilha *aux;
    aux = ptrP;

    while(!vaziaPilha(aux)){
        printf("%d\n", aux->info);
        aux = aux->dir;
    }
}