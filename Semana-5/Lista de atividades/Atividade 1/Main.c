#include "BBT_LDE.c"

int main(){

    NO *ptrLista;
    int menu;

    inicializar( &ptrLista );
    
    do{

        printf( "1-Inserir no final\n" );
        printf( "2-Remover no final\n" );
        printf( "3-Listar inverso\n" );
        printf( "4-Soma da lista\n" );
        printf( "9-Sair\n" );
        scanf( "%d", &menu );

        switch (menu)
        {
        case 1:{

            float elem;

            printf( "Insira o valor:\n" );
            scanf( "%f", &elem );
            fflush(stdin);

            inserirFim( &ptrLista, elem );
            break;
        
        }

        case 2:{

            removerFim( &ptrLista );
            break;
        
        }
        
        case 3:{

            imprimirListaReversa( ptrLista );
            break;
        
        }

        case 4:{
            imprimirSoma( ptrLista );
            break;
        }

        case 5:{
            float elem;

            printf( "Insira o valor:\n" );
            scanf( "%f", &elem );
            fflush(stdin);

            inserirInicio( &ptrLista, elem );
            break;
        }
        case 6:{
            removerInicio(&ptrLista);
            break;
        }
        case 7:{
            imprimirLista(ptrLista);
            break;
        }
        
        default:
            break;
        }


    }while( menu != 9 );

    printf("\n\n\nPrograma finalizado!");

    return 0;
}
