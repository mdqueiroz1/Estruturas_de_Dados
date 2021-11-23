#include <stdio.h>
#include <stdlib.h>

typedef struct sNo{
    int info;
    struct sNo *dir;
}No;

typedef struct sFila{
    No *inicio;
    No *final;
}Fila;

No* alocaNo(){
    return (No*) malloc(sizeof(No));
}

void init(Fila *ptrF){
    ptrF->inicio = NULL;
    ptrF->final = NULL;
}

int vazioFila(Fila *ptrF){
    if(ptrF->inicio == NULL) return 1;
    if(ptrF->final == NULL) return 1;
    return 0;
}

void insereFila(Fila *ptrF, int elem){
    if(ptrF == NULL) return;

    No *novo;
    novo = alocaNo();
    novo->dir == NULL;

    novo->info = elem;
    novo->dir = NULL;

    if(ptrF->inicio == NULL){
        ptrF->inicio = novo;
        ptrF->final = novo;
        return;
    }
    ptrF->final->dir = novo;
    ptrF->final = novo;
}

void removeFila(Fila *ptrF){
    if(ptrF == NULL){
        printf("Lista nao alocada!\n");
        return;
    } 
    if(ptrF->inicio == NULL){
        printf("Lista vazia!\n");
    }

    No *novo;
    novo = alocaNo();
    novo = ptrF->inicio;
    ptrF->inicio = ptrF->inicio->dir;

    if(ptrF->inicio == NULL){
        ptrF->final = NULL;
    }    
    free(novo);
    
}

void listaNaoClassico(Fila *ptrF){
    
}

void listaClassico(Fila *ptrF){
    if(ptrF == NULL) return;
    if(vazioFila(ptrF)) return;

    printf("%d\n", ptrF->inicio->info);
}
