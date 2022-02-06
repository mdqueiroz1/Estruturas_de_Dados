#include <stdio.h>
#include <stdlib.h>
#include "BBT_LSEC.c"

int main(void){
    

    NO* ptrLista;
    int menu;
    char elem;

    iniciar( &ptrLista );
    
    do{
        printf("\nEscolha uma opcao\n");
        printf( "1-Inserir no inicio\n" );
        printf( "2-Remover no final\n" );
        printf( "3-Listar vogais\n" );
        printf( "4-Sair\n\n" );
        fflush(stdin);
        scanf( "%d", &menu );

        switch (menu){
        case 1:{

            printf( "Insira o char:\n" );
            fflush(stdin);
            scanf( "%c", &elem );
            inserirInicio( &ptrLista, elem );
            break;
        
        }

        case 2:{

            removerFim( &ptrLista );
            break;
        
        }
        
        case 3:{
            
            imprimirLista( ptrLista );
            break;
        
        }
        
        break;
        }
        printf("\n");
    }
    while( menu !=4 );
    return 0;
}