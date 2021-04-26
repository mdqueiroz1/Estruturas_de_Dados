#include <stdio.h>
#include <stdlib.h>

typedef struct sDEQUE{
    int info;
    struct sDEQUE *inicio;
    struct sDEQUE *final;
}DEQUE;

DEQUE* alocaDeque(){
    return (DEQUE*) malloc(sizeof(DEQUE));
}

int dequeVazia(DEQUE *ptrD){
    if (ptrD == NULL) return 1;
    if (ptrD->inicio == NULL) return 1;
    return 0;
}

