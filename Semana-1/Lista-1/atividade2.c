#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char *str;
    int tamanho = 0;

    printf( "Informe o tamanho da string:\n" );
    scanf( "%d", &tamanho );
    fflush( stdin );

    str = (char *) malloc ( tamanho * sizeof(char) );
    
    printf( "Qual a frase a ser mostrada sem as vogais?" );
    scanf( "%[^\n]", str );

    for (int i = 0; i < tamanho; i++){

        if (str[i] != 'a' && 
            str[i] != 'e' && 
            str[i] != 'i' && 
            str[i] != 'o' && 
            str[i] != 'u'){
            printf("%c", str[i]);
        }
    }

    return 0;
}