#include <stdio.h>
#include "BBT_ListaEstatica.c"
void teste(int teste){
    if(teste){
        printf("Sucesso\n");
        }
    else{
        printf("erro\n");
    }
}
int menu(ListaEstatica *ptrLista){

    int opcmenu;
    do{
        printf("1-Inserir elemento no final da lista\n");
        printf("2-Inserir elemento na posicao N\n");
        printf("3-Remover elemento da posicao N\n");
        printf("4-Modificar elemento da posicao N\n");
        printf("5-listar\n");
        printf("9-Sair\n");
        scanf("%d", &opcmenu);
        switch (opcmenu){
            case 1:{
                int elem;
                
                printf("Informe o elemento a ser adicionado\n");
                scanf("%d", &elem);
                
                teste(inserirFinal(ptrLista,elem));
                break;
            }
                
            case 2:{
                int posicao, elem;
                
                printf("Informe a posicao a adicionar o elemento\n");
                scanf("%d",&posicao);
                
                printf("Informe o elemento a ser adicionado na posicao %d\n",posicao);
                scanf("%d", &elem);
                
                teste(inserirPosicao(ptrLista, posicao, elem));
                break;
            }

            case 3:{
                int posicao;

                printf("Informe a posicao para ser removida.\n");
                scanf("%d", &posicao);
                
                teste(removerPosicao(ptrLista, posicao));
                
                break;
            }

            case 4:{
                int posicao,elem;
                
                printf("Informe a posicao que devera ser modificada\n");
                scanf("%d", &posicao);
                
                printf("Qual o elemento devera ser substiruido na posicao %d\n", posicao);
                scanf("%d", &elem);
                
                teste(modificaPosicao(ptrLista, posicao, elem));
                
                break;
            }
            case 5:{
                printLista(ptrLista);
            }
            default:{
                printf("Selecao fora das opcoes.\n");
                break;
            }
        }
    }while(opcmenu != 9);

}

int main(){
    
    ListaEstatica *ptrLista;
    ptrLista = (ListaEstatica*) malloc(sizeof(ListaEstatica));
    init(ptrLista);
    
    menu(ptrLista);

    return 0;
}
