#include "BBT_PilhaEstatica.c"

int main(){

    float elem;
    int opcao;
    Pilha s;


    inic(&s);

    do{
        
        printf("Selecione uma opcao:\n");
        printf("1 - Empilhar elemento:\n");
        printf("2 - Desempilhar elemento:\n");
        printf("3 - Retornar elemento no topo\n");
        printf("4 - Exibir elementos Classico.\n");
        printf("5 - Sair\n");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao){
            case 1:

                fflush(stdin);
                printf("\nDigite uma letra do alfabeto:");
                scanf("%c", &elem);
                empilhar(&s, elem);
            
                break;

            case 2:
            
                desempilhar(&s);
                break;
            
            case 3:{

                retornaTopo(&s);
                break;
            }

            case 4:
            
                impressaoClassica(&s);
                break;

        default:
        
            printf("Encerrando o programa\n");
            break;
        
        }

    }while(opcao != 5);
    
    return 0;
}