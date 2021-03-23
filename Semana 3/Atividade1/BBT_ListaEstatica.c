#include <stdio.h>
#define TAML 50

typedef struct sListaEstatica{
    int info[TAML];
    int n;
}ListaEstatica;

int init(ListaEstatica *ptrLista){
    ptrLista->n = -1;
}

int listaCheia(ListaEstatica *ptrLista){
    if((ptrLista->n)+1 == TAML){
        printf("A lista esta cheia!\n");
        return 1;
    }
    return 0;
}

int listaVazia(ListaEstatica *ptrLista){
    if (ptrLista->n == -1){
        printf("Lista vazia!\n");
        return 1;
    }
    return 0;
}

int inserirFinal(ListaEstatica *ptrLista, int elem){
    if(listaCheia(ptrLista)){
        return 1;
    }
    ptrLista->info[(ptrLista->n)+1] = elem;
    ptrLista->n = (ptrLista->n)+1;
}

int inserirPosicao(ListaEstatica *ptrLista, int posicao, int elem){
    if(listaCheia(ptrLista)){
        return 1;
    }
    
    if(posicao < 0 || posicao >((ptrLista->n)+1)){
        printf("Posicao fora da lista.\n");
        return 1;
    }

    for(int i = ((ptrLista->n)+1); i > posicao; i--){
        ptrLista->info[i] = ptrLista->info[i-1];
    }

    ptrLista->info[posicao] = elem;
    
    return 0;
}

int removerPosicao(ListaEstatica *ptrLista, int posicao){
    int i;
    if(listaVazia(ptrLista)){
        return 1;
    }
    
    for (i = posicao; i < ptrLista->n; i++){
        ptrLista->info[i] = ptrLista->info[i+1];
    }
    ptrLista->n = (ptrLista->n)-1;

    return 0;
}

int modificaPosicao(ListaEstatica *ptrLista, int posicao, int elem){
    if(posicao < 0 || posicao > ptrLista->n){
        printf("Fora dos limites da lista.\n");
        return 1;
    }

    ptrLista->info[posicao] = elem;

    return 0;
}

void printLista(ListaEstatica *ptrLista){
    int i;
    if(!(listaVazia(ptrLista))){
        system("cls");
        printf("Lista contem os seguintes elementos:\n");
        for (i = 0; i < (ptrLista->n)+1; i++){
            printf("%d\n", ptrLista->info[i]);
        }
        getchar();
    }
}

