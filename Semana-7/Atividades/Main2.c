#include "BBT_PilhaDinamica.c"

int main(){

    Pilha *Pilha;
    inicializar(&Pilha);
    Prato info, P;

    int opcao;

    do{
        
        printf("Selecione uma opcao:\n");
        printf("1 - Empilhar elemento:\n");
        printf("2 - Desempilhar elemento:\n");
        printf("3 - Retorna o item que esta no topo\n");
        printf("4 - Exibir elementos empilhados de forma classica.\n");
        printf("5 - Sair\n");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                
                fflush(stdin);
                printf("\nDigite a cor do prato\n");
                gets(info.cor);
                fflush(stdin);
                printf("\nDigite o tamanho do prato em cm\n");
                scanf("%d", &info.tamanho);
                fflush(stdin);
                printf("\nDigite o material do prato: \n1- Plastico\n2- Vidro\n3- Porcelana\n");
                int opc;
                scanf("%d", &opc);
                switch (opc)
                {
                case 1:
                    strcpy(info.tipo, PLA);
                    break;
                case 2:
                    strcpy(info.tipo, VID);
                    break;
                case 3:
                    strcpy(info.tipo, POR);
                    break;
                
                default:
                    break;
                }
                fflush(stdin);


                empilhar(&Pilha, info);
                break;

            case 2:
        
                strcpy (P.cor,"");
                P = desempilhar(&Pilha);
                if(!strcmp(P.cor, "")) printf("Prato da cor %s foi desempilhado!", P.cor);
        
                break;

            case 3:

                retornaTopo(Pilha);

            case 4:
            
                impressaoClassica(&Pilha);
                break;
        
        default:
        
            printf("Encerrando o programa\n");
            break;
        
        }

    }while(opcao != 5);
}