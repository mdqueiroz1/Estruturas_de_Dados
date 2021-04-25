#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNo{
    int qntCaracteres;
    char palavra[20];
    struct sNo *dir;
    struct sNo *esq;
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

void inserirInicio(NO **ptrLista, char *elem){
    
    NO *novo;
    novo = alocarNo();
    if(novo == NULL)
        exit(1);

    strcpy(novo->palavra,elem);
    novo->qntCaracteres = strlen(elem);
    
    if((*ptrLista) == NULL){
        (*ptrLista) = novo;
        novo->dir = novo;
        novo->esq = novo;
    }else{
        novo->dir = ((*ptrLista)->dir);
        ((*ptrLista)->dir)->esq = novo;
        (*ptrLista)->dir = novo;
        novo->esq = (*ptrLista); 
    }
}

void removerFinal(NO **ptrLista){
    
    if((*ptrLista)->dir == *ptrLista){
        desalocarNo((*ptrLista)->dir);
        *ptrLista = NULL;
    }else{
        NO *aux = *ptrLista;
        (*ptrLista) = (*ptrLista)->esq;
        (*ptrLista)->dir = aux->dir;
        (aux->dir)->esq = *ptrLista;
        desalocarNo(aux);
    }
}

void init(NO **lista){
    alocarNo(lista);
    (*lista)->qntCaracteres = 0;
    (*lista)->dir = NULL;
    (*lista)->esq = NULL;
}

void imprimirLista(NO *lista){
    NO *aux;
    aux = lista;
    if(lista != NULL ){
        do{
            printf("A palavra %s tem %d caracteres\n",lista->palavra,lista->qntCaracteres);
            lista = lista->dir;
        }while(lista != aux);
    }else{
        printf("\nLista Vazia!\n");
        exit(1);
    }
}