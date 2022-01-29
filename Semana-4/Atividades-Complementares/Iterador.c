#include<stdio.h>

int main(){

    char str[10] = "1234567890";
    int i = 0, k = 0;

    for(int j = 0; j < 10; j++){
        i = j;
        while(i < 10){
            printf("%c", str[i]);
            i++;
        }
        while(k < j){
            printf("%c", str[k]);
            k++;
        }
        printf("\n");
        k = 0;
    }

    return 0;
}