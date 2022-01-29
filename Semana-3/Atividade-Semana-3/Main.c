#include <stdio.h>
#include <stdlib.h>

#include "BBT_LLD.c"

int main(){

    int menu;
    ListaDinamica *ptrLista;
    ptrLista = inicializarLista(ptrLista);

    do{

        system("cls");
        printf("1- Adicionar na lista\n");
        printf("2- Remover na lista\n");
        printf("3- Listar\n");
        printf("4- Sair\n");
        scanf("%d", &menu);
        fflush(stdin);
        switch (menu){

            case 1:{

                Dados elem;
                
                printf("Insira o codigo da disciplina\n");
                fgets(elem.codigo, 7, stdin);
                strupr(elem.codigo);
                fflush(stdin);
                  
                printf("Insira o nome da disciplina:\n");
                fgets(elem.nome, 20, stdin);
                fflush(stdin);
                
                printf("Insira os creditos da disciplina:\n");
                scanf("%d", &elem.creditos);
                fflush(stdin);
                
                printf("Insira a carga horaria:\n");
                scanf("%d",&elem.cargaHoraria);
                fflush(stdin);

                ptrLista = inserirFimLista(ptrLista, elem);
                break;
            
            }
            case 2:{

                ptrLista = removerInicioLista(ptrLista);
                break;
            
            }
            case 3:{

                imprimirLista(ptrLista);
            
            }
        
        }

    } while (menu != 4);

    return 0;
}
