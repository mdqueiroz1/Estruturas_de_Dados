#include <stdio.h>
#include <stdlib.h>

typedef struct sNo{

    float info;
    struct sNo *dir;
    struct sNo *esq;

}NO;

NO* alocarNo(){

    return (NO*) malloc ( sizeof(NO) );

}

void inicializar( NO **ptrLista){

    *ptrLista = NULL;

}

void desalocarNo( NO *ptrLista ){   

    free(ptrLista);

}

int listaVazia( NO *ptrLista ){

    if( ptrLista == NULL ) return 1;
    else return 0;

}

void inserirFim ( NO **lista, float elem){

    NO *novo;
    NO *aux;

    novo = alocarNo();

    if (novo != NULL){
        
        novo->info = elem;
        novo->esq = NULL;
        novo->dir = NULL;
        
        if (listaVazia( *lista )) *lista = novo;
        else{
            
            aux = *lista;
            
            while (aux->dir != NULL) aux = aux->dir;
            
            aux->dir = novo;
            novo->esq = aux;
                        
        }
        
    }else{

        printf("\nErro, falha na alocacao do no!\n");
        exit(1);
    
    }
    
}

void removerFim( NO **lista){

    NO *q;
    q = *lista;

    if (!listaVazia(*lista)){
        
        if((*lista)->dir == NULL) {
            
            removerInicio(lista);
            exit(0);
        
        }else{

            while ( q->dir != NULL ) q = q->dir;        
            (q->esq)->dir = NULL;
            desalocarNo(q);
        
        }

    }else{

        printf("\nLista vazia!\n");
        exit(1);

    }    

}

void imprimirListaReversa(NO *lista){

    NO *aux;
    aux = lista;

    if(!listaVazia(lista)){
        int i = 1;
        while (aux->dir != NULL) aux = aux->dir;
        
        while ( aux != NULL ){
            printf("%d- %f\n",i, aux->info);
            aux = aux->esq;
            i++;
        }
    
    }else{
        printf("\nLista Vazia!");
    }

    printf("\n\n");
}

void imprimirSoma(NO *lista){

    NO *aux;
    aux = lista;

    if(!listaVazia(lista)){

        float i=0.0;

        while (aux != NULL){
            i+=aux->info;
            aux = aux->dir;
        }
    
    }else{

        printf("\nLista Vazia!");
    
    }

    printf("\nA soma da lista é %.2f.\n\n");

}