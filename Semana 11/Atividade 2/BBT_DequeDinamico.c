#include <stdio.h>
#include <stdlib.h>

typedef struct sNo{
    int info;
    struct sNo *dir;
    struct sNo *esq;
}NO;

typedef struct sDEQUE{
    NO *inicio;
    NO *final;
}DEQUE;

NO* alocaNo(){
    return ((NO*) malloc(sizeof(NO)));
}

void init(DEQUE *ptrD){
    ptrD = ((DEQUE*) malloc(sizeof(DEQUE)));
    ptrD->inicio = NULL;
    ptrD->final = NULL;
}

int vazio(DEQUE *ptrD){
    if (ptrD == NULL) return 1;
    if (ptrD->inicio == NULL) return 1;
    
    return 0;
}

void insereInicioDeque(DEQUE *ptrD, int elem){
    if(ptrD == NULL){
        printf("Deque nao inicializado!\n");
        return;
    }     
    
    NO *novo;
    novo = alocaNo();
    if(novo == NULL) {
        printf("Não foi alocado.\n");
        return;
    }
    
    novo->info = elem;
    novo->dir = ptrD->inicio;
    novo->esq = NULL;

    if(vazio(ptrD)) {
        ptrD->final = novo;
    }else {
        (ptrD->inicio)->esq = novo;
    }

    ptrD->inicio = novo;
}

void removeFinalDeque(DEQUE *ptrD){
    if(ptrD == NULL) return;
    if(ptrD->inicio == NULL) return;

    NO *aux = ptrD->final;
    if(aux == ptrD->inicio){
        ptrD->inicio = NULL;
        ptrD->final = NULL;
    }else{
        (aux->esq)->dir = NULL;
        ptrD->final = aux->dir;
    }
    free(aux);
}

void insereFinalDeque(DEQUE *ptrD, int elem){
    NO* novo;
    novo = alocaNo();
    if(novo == NULL) return;

    novo->info = elem;
    novo->dir = NULL;

    if(vazio(ptrD) == 1){
        ptrD->inicio = novo;
        ptrD->final = novo;
    }else{
        (ptrD->final)->dir = novo;
        novo->esq = ptrD->final;
        ptrD->final = novo;
    }
}

void removeInicioDeque(DEQUE *ptrD){
    NO *aux;
    if(vazio(ptrD)) return;

    aux = (ptrD->inicio)->dir;
    free(ptrD->inicio);
    ptrD->inicio = aux;

    if(ptrD->inicio != NULL)
        (ptrD->inicio)->esq = NULL;
    else
        ptrD->final = NULL;
}

void listaNaoClassico(DEQUE *ptrD){
    if(vazio(ptrD)) return;
    
    NO *aux;
    aux = ptrD->inicio;
    
    while(aux != NULL){
        printf("%d\t", aux->info);
        aux = aux->dir;
    }
    printf("\n");
}

void listaClassico(DEQUE *ptrD){
    return;
}