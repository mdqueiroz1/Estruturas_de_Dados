#include <stdio.h>
#include <stdlib.h>
#include "BBT_ListaEstatica.c"

void menu(ListaEstatica *ptrLista){
    int opMenu;
    
    printf("1-Cadastrar aluno\n");
    printf("2-Pesquisar aluno com matricula\n");
    printf("3-Remover aluno\n");
    printf("4-Calcular a media da turma nas atividades semanais.\n");
    scanf("%d", &opMenu);
    switch (opMenu)
    {
    case 1:{
        cadastroAluno(ptrLista);
        break;
    }   
    case 2:{
        int matricula, retorno;

        printf("Informe a matricula do aluno a ser pesquisado\n");
        scanf("%d", &matricula);
       
        retorno = pesquisaAluno(ptrLista,matricula);
        
        if(retorno != -1){
            printf("O aluno esta na posicao %d", retorno);
        }

        break;
    } 
    case 3:{
        removeFinal(ptrLista);
        break;
    }
    case 4:{
        calculaMedia(ptrLista);
        break;
    }
    default:
        break;
    }
}

int main(){
    ListaEstatica *ptrLista;
    ptrLista = (ListaEstatica*) malloc(sizeof(ListaEstatica));     
    
    menu(ptrLista);
    
    return 0;
}
