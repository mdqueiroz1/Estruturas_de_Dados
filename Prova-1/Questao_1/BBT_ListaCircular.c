#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNo{
    int mes, qntCultura;
    char cultura[20];
    struct sNo *dir;
}NO;

NO* alocarNo(){
    return (NO*) malloc(sizeof(NO));
}

NO* inicializarLista(){
    NO *ptrLista  = alocarNo();
    if(ptrLista != NULL)
        ptrLista = NULL;
    return ptrLista;
}

void desalocarNo(NO *ptrNo){
    free(ptrNo);
}

void inserirInicio(NO **ptrLista, char *elem, int mes){
    NO *novo;
    novo = alocarNo();
    if(novo == NULL)
        exit(1);
    NO *aux;
    aux = (*ptrLista);

    strcpy(novo->cultura,elem);
    novo->mes = mes;
    if(mes == 11)
        (*ptrLista)->qntCultura++;

    if((*ptrLista) == NULL){
        (*ptrLista) = novo;
        novo->dir = novo;
    }else{
        while (aux->dir != (*ptrLista)){
            aux = aux->dir;
        }
        aux->dir = novo;
        novo->dir = (*ptrLista);
        (*ptrLista) = novo;
    }
}

void removerFinal(NO **ptrLista){
    NO *aux = (*ptrLista)->dir;
    NO *auxAnterior = *ptrLista;
    
    if((*ptrLista)->dir == *ptrLista){
        if((*ptrLista)->mes == 11)
            (*ptrLista)->qntCultura--;    
        
        desalocarNo((*ptrLista)->dir);
        *ptrLista = NULL;
    }else{
        while (aux->dir != *ptrLista){
            auxAnterior = aux;
            aux = aux->dir;
        }
        
        if(aux->mes == 11)
            (*ptrLista)->qntCultura--;  
        
        auxAnterior->dir = aux->dir;

        desalocarNo(aux);
    }
}

void imprimirLista(NO *lista){
    NO *aux;
    aux = lista;
    if(lista != NULL ){
        do{
            printf("No %d mes, deve-se plantar %s",lista->mes,lista->cultura);
            lista = lista->dir;
        }while(lista != aux);
    }else{
        printf("\nLista Vazia!\n");
        exit(1);
    }
}