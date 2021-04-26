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

