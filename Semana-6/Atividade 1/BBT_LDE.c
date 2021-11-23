#include <stdio.h>
#include <stdlib.h>

typedef struct sNo{
    int info;
    struct sNo *dir;
    struct sNo *esq; 
}NO;

NO* alocarNo(){
    return (NO*) malloc(sizeof(NO));
}

void desalocarNo(NO *ptrNo){
    free(ptrNo);
}

int listaVazia(NO *ptrNo){
    if(ptrNo->dir == NULL){
        return 0;
    }else{
        printf("K \n");
        return 1;
    }
}

NO* pesquisarNo(NO *ptrLista, char elem){
    NO *aux;
    aux = ptrLista;

    if(!listaVazia(ptrLista)){
        while(aux != NULL){
            if(aux->info == elem){
                return aux;
            }
            aux = aux->dir;
        }
    }
    return NULL;
}

void inserirInicio(NO **lista, int elem){
    NO *novo;
    novo = alocarNo();
    if(novo != NULL){
        novo->info = elem;
        novo->esq = NULL;
        novo->dir = *lista;
        if(!listaVazia(*lista)){
            (*lista)->esq = novo;
        }
        *lista = novo;
    }else{
        exit(1);
    }
}

void inserirFim(NO **lista, int elem){
    NO *novo;
    NO *aux;
    novo = alocarNo();
    if(novo != NULL){
        novo->info = elem;
        novo->esq = NULL;
        novo->dir = NULL;
        if(listaVazia(*lista))
            *lista = novo;
        else{
            aux = *lista;
            while(aux->dir != NULL){
                aux = aux->dir;
            }
                aux->dir = novo;
                novo->esq = aux;
        }
    }else{
            exit(1);
    }
}

void removerInicio(NO **lista){
    NO *q;
    q = *lista;
    if(!listaVazia(*lista)){
        *lista = q->dir;
        (*lista)->esq = NULL;
        desalocarNo(q);
    }else{
        exit(1);
    }
}

void removerFim(NO **lista){
    NO *q;
    q = *lista;
    if(!listaVazia(*lista)){
        while(q->dir != NULL){
            q = q->dir;
        }
        (q->esq)->dir = NULL;
        desalocarNo(q);
    }else{
        printf("Lista Vazia!\n");
        exit(1);
    }
}

int removerValor(NO **lista, int elem){
    NO *q;
    if((pesquisarNo(*lista, elem)) != NULL){
        
        q = pesquisarNo(*lista, elem);
        
        if(*lista == q)
            removerInicio(lista);
        else{
            (q->esq)->dir = q->dir;
            if(q->dir != NULL)
                (q->dir)->esq = q->esq;
            desalocarNo(q);
        }
        return 1;
    }
    return 0;
}

void somarLista(NO **lista){
    NO *q;
    q = *lista;

    int total=0;

    if(!listaVazia(*lista)){
        while(q->dir != NULL){
            total =+ q->info;
            q = q->dir;
        }
        printf("A soma de todos as celulas eh %d", total);     
    }else
        exit(1);
}

int imprimirLista(NO *ptrLista){
    NO *aux;
    if(listaVazia(ptrLista)){
        printf("Lista Vazia!\n");
        return 1;    
    }else{
        aux = ptrLista;
        while(aux != NULL){
            printf("%c\t",ptrLista->info);
            aux = aux->dir;  
        }
    }
    return 0;
}