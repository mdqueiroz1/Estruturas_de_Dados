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
    if(ptrD == NULL) return -1;
    if(ptrD->inicio == 0) return 1;
    else return 0;
}

int dequeCheia(DEQUE *ptrD){
    if((ptrD->inicio)+1 == TAM_MAX) return 1;

    return 0;
}

void inserirInicio(DEQUE *ptrD, char elem){
    if(ptrD->inicio == 0){
        ptrD->inicio = TAM_MAX -1;
    }else{
        (ptrD->inicio)--;
    }

    if(cheia(ptrD)== 1){
        printf("Deque cheia\n");
        ptrD->inicio = (ptrD->inicio + 1) % TAM_MAX;
        return;
    }
    ptrD->info[(ptrD->inicio+1)%TAM_MAX] = elem;
}

void insereFinal(DEQUE *ptrD, int elem){
    if(ptrD == NULL || (ptrD->inicio)+1 == TAM_MAX) return;

    ptrD->info[ptrD->inicio] = elem;
    ptrD->fim = (ptrD->fim + 1 ) % TAM_MAX;
    ptrD->inicio--;
    return;
}

void removeInicio(DEQUE *ptrD){
    if(dequeVazia(ptrD)) return;
    
    ptrD->inicio = (ptrD->inicio + 1) % TAM_MAX;
    return;
}

void removeFinal(DEQUE *ptrD){
    if(dequeVazia(ptrD)) return;

    ptrD->fim--;
    if(ptrD->fim < 0)
        ptrD->fim = TAM_MAX-1;   
}

void listaClassico(DEQUE *ptrD){
    if(dequeVazia(ptrD)) return;

    while (dequeVazia(ptrD)){
        printf("%d ", ptrD->info[ptrD->inicio]);
        removeInicio(ptrD);
    }
}

void listaNaoClassico(DEQUE *ptrD){
    if(dequeVazia(ptrD)) return;

    for(int i = 0; i < TAM_MAX; i++){
        printf("%d ", ptrD->info[i]);
    }
    printf("\n");
}