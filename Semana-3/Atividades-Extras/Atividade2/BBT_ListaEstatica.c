#include <stdio.h>
#define TAML 60

typedef struct sAluno{
    char matricula[4], idTurma[1],nome[20];
    float nQuiz[10], nListaExer[10], nParticipa[10];
}Aluno;


typedef struct sListaEstatica{
    Aluno info[TAML];
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

int cadastroAluno(ListaEstatica *ptrLista){
    
    int i;

    printf("Matricula do aluno:\n");
    scanf("%d", &ptrLista->info->matricula);
    
    printf("Nome do aluno:\n");
    fflush(stdin);
    fgets(ptrLista->info->nome,20,stdin);
    fflush(stdin);

    printf("Turma do aluno:\n");
    scanf("%c", &ptrLista->info->idTurma);
    fflush(stdin);

    printf("Informe as 10 notas do quiz do aluno\n");
    for (i = 0; i < 10; i++){
        do{
            printf("nota %d", i+1);
            scanf("%f",ptrLista->info->nQuiz[i]);
            if(ptrLista->info->nQuiz[i] > 3.3 ||ptrLista->info->nQuiz[i] < 0){
                printf("Valor invalido.\n");
            }
        }while(ptrLista->info->nQuiz[i] > 3.3 ||ptrLista->info->nQuiz[i] < 0);
    }
    printf("Informe as 10 notas da lista de exercicios do aluno\n");
    for (i = 0; i < 10; i++){
        do{
            printf("nota %d", i+1);
            scanf("%f",ptrLista->info->nListaExer[i]);
            if(ptrLista->info->nListaExer[i] > 3.3 ||ptrLista->info->nListaExer[i] < 0){
                printf("Valor invalido.\n");
            }
        }while(ptrLista->info->nListaExer[i] > 3.3 ||ptrLista->info->nListaExer[i] < 0);
    }
    
    printf("Informe as 10 notas da participacao em aula do aluno\n");
    for (i = 0; i < 10; i++){
        do{
            printf("nota %d", i+1);
            scanf("%f",ptrLista->info->nParticipa[i]);
            if(ptrLista->info->nParticipa[i] > 3.3 ||ptrLista->info->nParticipa[i] < 0){
                printf("Valor invalido.\n");
            }
        }while(ptrLista->info->nParticipa[i] > 3.3 ||ptrLista->info->nParticipa[i] < 0);
    }
}

int inserirFinal(ListaEstatica *ptrLista, int elem){
    if(listaCheia(ptrLista)){
        return 1;
    }
    cadastroAluno(ptrLista);
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

    cadastroAluno(ptrLista);
    
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

    cadastroAluno(ptrLista);

    return 0;
}

int pesquisaAluno(ListaEstatica *ptrLista, int matricula){
    if(!listaVazia(ptrLista)){
        for(int i = 0; i< ptrLista->n; i++){
            if(matricula == ptrLista->info[i].matricula){
                return matricula;
            }
        }
    }else{
        printf("Aluno nao encontrado!\n");
        return -1;
    }
}

int removeFinal(ListaEstatica *ptrLista){
    if(!listaVazia(ptrLista)){
        ptrLista->n = (ptrLista->n)-1;
        return 0; 
    }else
    return 1;
}

void calculaMedia(ListaEstatica *ptrLista){
    float valor, total;

    if(listaVazia(ptrLista)){
        return 1;
    }
    
    for(int i = 0; i < ptrLista->n; i++){
        for(int j = 0; j<10 ; j++){
            valor =+ (ptrLista->info[i].nListaExer[j]);
            valor =+ (ptrLista->info[i].nParticipa[j]);
            valor =+ (ptrLista->info[i].nQuiz[j]);
        }
    }

    total = valor / ptrLista->n;
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

