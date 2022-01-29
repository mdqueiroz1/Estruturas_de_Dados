#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sDados{
    
    int cargaHoraria,creditos;
    char nome[20], codigo[6];

}Dados;

typedef struct sListaDinamica{
    
    Dados info;
    struct sListaDinamica *prox; 

}ListaDinamica;

ListaDinamica* inicializarLista( ListaDinamica *ptrLista ){

    ptrLista = NULL;
    return ptrLista;

}

ListaDinamica* alocarNoLista(){
    
    return ( ListaDinamica* ) malloc ( sizeof(ListaDinamica) );

}

void desalocarNoLista( ListaDinamica *ptrLista ){
    
    free(ptrLista);

}

int listaVazia( ListaDinamica *ptrLista ){

    if(ptrLista == NULL) return 1;
    else return 0;

}

ListaDinamica* inserirInicioLista( ListaDinamica *ptrLista, Dados elem ){

    ListaDinamica *novo;
    novo = alocarNoLista();

    if( novo != NULL ){

        novo->info = elem;
        novo->prox = ptrLista;

        ptrLista = novo;

        return ptrLista;

    }else{

        printf( "No nao alocado!\n" );
        return NULL;
    
    }

}

ListaDinamica* inserirFimLista( ListaDinamica *ptrLista, Dados elem ){
    
    ListaDinamica *novo, *aux;

    novo = alocarNoLista();

    if( novo != NULL ){
        
        novo->info = elem;
        novo->prox = NULL;

        if( listaVazia(ptrLista) ) ptrLista = novo;
        else{
            
            aux = ptrLista;

            while( aux->prox != NULL ) aux = aux->prox;

            aux->prox = novo;
        }
        
        return ptrLista;
    }else{

        printf("Erro na alocacao do no!\n");
        return NULL;
    
    }

}

ListaDinamica* removerInicioLista( ListaDinamica *ptrLista ){

    ListaDinamica *no;

    no = ptrLista;

    if( !listaVazia(ptrLista) ){

        ptrLista = no->prox;
        desalocarNoLista(no);
        return ptrLista;
    
    }else{

        printf("Erro, lista vazia!\n");
        return NULL;
    
    }

}

ListaDinamica* pesquisarNaLista( ListaDinamica *ptrLista, int elem ){

    ListaDinamica *aux;
    aux = ptrLista;

    if ( !listaVazia( ptrLista ) ){
        
        while( aux != NULL){
            
            if( aux->info.codigo == elem ) return aux;
        
            aux = aux->prox;
        
        }

    }

    return NULL;
}

ListaDinamica* removerValorNaLista( ListaDinamica *ptrLista, Dados elem ){

    ListaDinamica *no, *aux;

    if( ( no = pesquisarNaLista(ptrLista, elem.codigo) ) != NULL ){

        aux = ptrLista;
        if( aux == no ) removerInicioLista(ptrLista);
        else{

            while (aux->prox != no) aux = aux->prox;

            aux->prox = no->prox;
            desalocarNoLista(no);

        }
        return ptrLista;
    
    }
    return NULL;
     
}

void imprimirLista( ListaDinamica *ptrLista ){
    
    ListaDinamica *aux;

    aux = ptrLista;

    printf("Lista: \n\n");
    while(aux != NULL){

        if( aux->info.codigo[0] == 'S' && aux->info.codigo[1] == 'I' && aux->info.codigo[2] == 'N' && aux->info.cargaHoraria > 60 ){
            
            printf("%s - %s\n", aux->info.codigo, aux->info.nome);
            printf("Carga horaria:%d\nCreditos:%d\n", aux->info.cargaHoraria, aux->info.creditos);
            
        }

        aux = aux->prox;
    
    }
    printf("\n\nPressione enter para voltar\n");
    scanf("%c", stdin);

}
