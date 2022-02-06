#include<stdio.h>
#include<stdlib.h>


typedef struct sNO{

    char info;
    struct sNO *prox;

}NO;

void iniciar( NO **ptrLista ){
    
    *ptrLista = NULL;

}

NO* alocarNo(){

    return (NO*) malloc ( sizeof(NO) );

}

void desalocarNo( NO *ptrLista ){   

    free(ptrLista);

}

int listaVazia( NO *ptrLista ){

    if( ptrLista == NULL ) return 1;
    else return 0;

}

void inserirInicio( NO **lista, char elem ){

    NO *novo;

    novo = alocarNo();

    if ( novo != NULL){
        
        novo->info = elem;

        if(listaVazia(*lista)){

            *lista = novo;
            novo->prox = *lista;

        }else{

            novo->prox = (*lista)->prox;
            (*lista)->prox = novo;

        }

    }else{
        printf("\nErro ao alocar no!\n");
        exit(1);
    }    

}

void inserirFim ( NO **lista, char elem ){
    
    NO *novo;

    novo = alocarNo();

    if ( novo != NULL ){
        novo->info = elem;

        if ( listaVazia(*lista) ){
            novo->prox = novo;
        }else{
            novo->prox = (*lista)->prox;
            (*lista)->prox = novo;
        }

        *lista = novo;
    }else{
        printf("\nErro na alocacao do no\n");
        exit(1);
    }
    
}

void removerInicio( NO **lista ){

    NO *aux;

    if (!listaVazia(*lista)){
        
        if ((*lista) == (*lista)->prox){
            desalocarNo(*lista);
            *lista = NULL;
        }else{
            aux = (*lista)->prox;
            (*lista)->prox = aux->prox;
            desalocarNo(aux);
        }

    }else{
        printf("\nErro, lista vazia!\n");
        exit(1);
    }
    
}

void removerFim ( NO **lista ){

    if (!listaVazia(*lista)){

        NO *q;
        q = *lista;
        
        if ((*lista) == (*lista)->prox){   
            
            *lista = NULL;
            desalocarNo(q);

        }else{

            NO *aux;
            aux = (*lista)->prox;
            
            while(aux->prox != (*lista)) aux = aux->prox;
            
            aux->prox = (*lista)->prox;
            (*lista) = aux;
            desalocarNo(q);

        }
        
    }else{
        printf("\nErro, lista vazia!\n");
    }

}

void imprimirLista( NO *lista ){

    NO *aux;

    if (lista != NULL)
    {
        aux = lista->prox;

        do{
            printf("%c \t", aux->info);
            aux = aux->prox;
        } while (aux != lista->prox);

    }else{
        printf("\nLista vazia!");
    }
    
    printf("\n");
}
