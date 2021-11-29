#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int *p, *q;
    
    p = (int *)malloc(sizeof(int));
    
    q = p;
    if (p != NULL){
        *p = 10;
        *q = 20;
         free(p);
         free(q);
    }

    printf("%x %x %d\n", &p, p, *p);
    printf("%x %x %d", &q, q, *q);
    
    return 0;
}

