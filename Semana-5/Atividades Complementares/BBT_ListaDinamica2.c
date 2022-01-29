#include <stdio.h>

typedef struct sNo{
    char info;
    struct sNo *prox;
}no;

no* init(no *ptrNo){
    ptrNo = NULL;
    return ptrNo;
}

no* alocarNo(){
    return (no*) malloc(sizeof(no));
}

void desalocarNo(no *ptrNo){
    free(ptrNo);
}

int listaVazia(no *ptrNo){
    if(ptrNo->prox == NULL){
        return 0;
    }else{
        printf("Lista vazia. \n");
        return 1;
    }
}

no* inserirInicio(no *ptrLista, char elem){
    no *novo;
    novo = alocarNo();
    if(novo != NULL){
        novo->info = elem;
        novo->prox = ptrLista;
    }else{
        printf("Erro ao alocar o no.\n");
        return NULL;
    }

    return ptrLista;
}

no* inserirFim(no *ptrLista, char elem){
    no *novo;
    no *aux;

    novo = alocarNo();
    if(novo != NULL){
        novo->info = elem;
        novo->prox = NULL;
        if(vazia(ptrLista)){
            ptrLista = novo;
        }else{
            aux = ptrLista;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = novo;
        }
        return ptrLista;
    }else{
        printf("Erro na alocacao do no");
        return NULL;
    }
}

no* removeInicio(no *ptrLista){
    no *q;
    q= ptrLista;

    if(!listaVazia(ptrLista)){
        ptrLista = q->prox;
        desalocarNo(q);
        return ptrLista;
    }else
        return NULL;
}

no* pesquisarNo(no *ptrLista, char elem){
    no *aux;
    aux = ptrLista;

    if(!vazia(ptrLista)){
        while(aux != NULL){
            if(aux->info == elem){
                return aux;
            }
            aux = aux->prox;
        }
    }
    return NULL;
}

no* removeValor(no *ptrLista, char elem){
    no *q;
    no *aux;

    if((q = pesquisarNo(ptrLista,elem)) != NULL){
        aux = ptrLista;
        if(aux == q){
            removeInicio(ptrLista);
        }else{
            while(aux->prox != q){
                aux = aux->prox;
            }
            aux->prox = q->prox;
            desalocarNo(q);
        }
        return ptrLista;
    }
    return NULL;
}

int imprimeLista(no *ptrLista){
    no *aux;
    if(listaVazia(ptrLista)){
        printf("lista vazia.\n");
        return 1;    
    }else{
        aux = ptrLista;
        while(aux != NULL){
            printf("%c\t",ptrLista->info);
            aux = aux->prox;  
        }
    }
    return 0;
}