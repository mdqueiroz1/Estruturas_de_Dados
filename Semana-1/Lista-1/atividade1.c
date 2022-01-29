#include<stdio.h>
#include<stdlib.h>

int main(){
    
    int *x, *y;
    x = (int *) malloc (sizeof(int));
    y = x;
    if (x != NULL)
    {
        *x = 27;
        *y = 32;
        free(x);
    }
    return 0;
}