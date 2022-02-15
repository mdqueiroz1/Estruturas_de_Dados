#include <stdio.h>
#include <stdlib.h>

#define PLA "plastico"
#define VID "vidro"
#define POR "porcelana"


typedef struct sPrato{

    char cor[20];
    int tamanho;
    char tipo[20];  

}Prato;

typedef struct sPilha{
    
    Prato info;
    struct sPilha *prox;
 
}Pilha;

void inicializar( Pilha **ptrLista ){
    
    *ptrLista = NULL;

}

Pilha* alocarNo(){

    return (Pilha*) malloc ( sizeof(Pilha) );

}

void desalocarNo( Pilha *ptrLista ){   

    free(ptrLista);

}

int listaVazia( Pilha *ptrLista ){

    if( ptrLista == NULL ) return 1;
    else return 0;

}

void empilhar(Pilha **topo, Prato elem){

    Pilha *novo;

    novo = alocarNo();

    if(novo != NULL){

        novo->info = elem;
        novo->prox = *topo;
        *topo = novo;

    }else{
        printf("Erro ao alocar no\n");
    }

}

Prato desempilhar(Pilha **topo){
    
    if(!listaVazia(*topo)){

        Prato L;
        Pilha *aux;
        aux = *topo;

        *topo = aux->prox;

        L = aux->info;

        desalocarNo(aux);

        return L;

    }else{
        
        printf("Pilha vazia!\n");
    
    }
}

void impressaoClassica(Pilha **topo){
    if(!listaVazia(*topo)){

        while(!listaVazia(*topo)){
            printf("Prato de cor %s possui %dcm de diametro e eh feito de %s \n", (*topo)->info.cor, (*topo)->info.tamanho, (*topo)->info.tipo);
            desempilhar(topo);
        }
    }else{
        printf("Lista vazia!\n");
    }
}


void retornaTopo(Pilha *topo){

    if(!listaVazia(topo)) printf("Prato de cor %s possui %dcm de diametro e eh feito de %s \n", topo->info.cor, topo->info.tamanho, topo->info.tipo);
    else printf("\nLista vazia!\n"); 

}