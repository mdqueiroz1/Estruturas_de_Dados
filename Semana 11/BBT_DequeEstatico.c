#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 10

typedef struct sDEQUE{
    int info[TAM_MAX];
    int inicio,fim;
}DEQUE;

void init(DEQUE *ptrD){
    ptrD->inicio = TAM_MAX - 1;
    ptrD->fim = TAM_MAX - 1;
}

int dequeVazia(DEQUE *ptrD){
    if(ptrD->inicio == ptrD->fim)   return 1;
    
    return 0;
}

int dequeCheia(DEQUE *ptrD){
    if((ptrD->inicio)-1 == 0) return 1;

    return 0;
}