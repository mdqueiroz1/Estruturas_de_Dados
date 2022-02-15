#include <stdio.h>
#include <stdlib.h>

#define TAMP 26

typedef struct sPilha{

    int topo;
    char itens[TAMP];

}Pilha;

void inic(Pilha *ptr){

    /*Inicializando a lista com todas as letras do alfabeto*/

    for (int i = 0; i < 26; i++){
        ptr->itens[i] = 97 + i;
        ptr->topo = i;
    }

}

int vazia(Pilha *ptr){

    if(ptr -> topo == -1) return 1;
    else return 0;

}

int cheia(Pilha *ptr){

    if(ptr -> topo == TAMP-1) return 1;
    
    return 0;

}

void empilhar(Pilha *ptr, float elem){
    
    if(!cheia(ptr)){

        (ptr -> topo)++;
        ptr->itens[ ptr -> topo ] = elem;

    }else{

        printf("Pilha cheia\n");

    }

}


void desempilhar(Pilha *ptr){

    if(!vazia(ptr)){

        float elemento;
        elemento = ptr->itens[ ptr->topo ];

        (ptr -> topo)--;

        return elemento;

    }else{

        printf("Pilha vazia!\n\n");
        return -1;

    }

}

void retornaTopo(Pilha *ptr){

    if (!vazia(ptr)) printf("%c\n", ptr->itens[ptr->topo]);
    else printf("Pilha vazia!\n\n");
    
}


void impressaoClassica( Pilha *ptr ){

    if (!vazia(ptr)){
        
        while (ptr->topo != -1 ){
            printf( "%c\t", ptr->itens[ptr->topo]);
            ptr->topo--;
        }
        printf("\n");
    }else{
        printf("Pilha vazia!\n\n");
    }
    

}