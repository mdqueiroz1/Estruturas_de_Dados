#include<stdio.h>
#include<stdlib.h>


typedef struct sNO{

    char info;
    struct sNO *prox;

}NO;

void inicializar( NO **ptrLista ){
    
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

void inserirInicio( NO **ptrLista, char elem ){
    
    NO *novo;
    novo = alocarNo();

    if ( novo != NULL ){
        
        novo->info = elem;
        novo->prox = *ptrLista;
        *ptrLista = novo;

    }else{

        printf( "Nao foi possivel alocar o no\n" );
    
    }
    
}

void removerInicio( NO **ptrLista ){

    NO *aux;


    if( !listaVazia(*ptrLista) ){
        
        aux = *ptrLista;
        *ptrLista = aux->prox;
        printf("%c removido da lista!\n", aux->info );
        desalocarNo(aux);

    }else{
        
        printf("Lista vazia!\n");
    
    }

}

void apagarNos(  NO **ptrLista ){

    NO *aux;
    
    if( !listaVazia(*ptrLista) ){
        
        aux = *ptrLista;
        
        while ( aux != NULL ){
            *ptrLista = aux->prox;
            desalocarNo(aux);
            aux = *ptrLista;
        }  

    }else{

        printf( "Lista vazia!\n" );
    
    }

}

void listar( NO *ptrLista ){

    NO *aux;

    if ( !listaVazia(ptrLista) ){
        
        aux = ptrLista;

        printf( "Lista de caracteres:\n" );
        while ( aux != NULL ){
            printf( "%c ", aux->info );
            aux = aux->prox;
        }
        printf( "\n" );        

    }
    

}