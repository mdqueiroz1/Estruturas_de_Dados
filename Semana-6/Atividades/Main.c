#include "BBT_LSEC.c"

int main(){
    

    NO *ptrLista;
    int menu;

    inicializar( &ptrLista );
    
    do{

        printf( "1-Inserir no inicio\n" );
        printf( "2-Remover no final\n" );
        printf( "3-Listar vogais\n" );
        printf( "4-Sair\n" );
        scanf( "%d", &menu );

        switch (menu)
        {
        case 1:{

            char elem;

            printf( "Insira o char:\n" );
            scanf( "%c", &elem );
            fflush(stdin);

            inserirFim( &ptrLista, elem );
            break;
        
        }

        case 2:{

            removerInicio( &ptrLista );
            break;
        
        }
        
        case 3:{

            imprimirLista( ptrLista );
            break;
        
        }
        
        default:
            break;
        }


    }while( menu != 4 );

    return 0;
}
