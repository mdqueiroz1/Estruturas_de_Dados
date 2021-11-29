#include <stdio.h>
#include <stdlib.h>

typedef struct sProduto{
    char nomeProduto[50];
    int quantidadeProduto;
    float precoProduto;
    
}Produto;

void cadastrarProduto(Produto *produto){
    
    printf("Nome do produto:\n");
    scanf("%[^\n]", produto->nomeProduto);
    fflush(stdin);
    printf("Quantidade do produto %s\n", produto->nomeProduto);
    scanf("%d", &produto->quantidadeProduto);
    fflush(stdin);
    printf("Preco do produto %s\n", produto->nomeProduto);
    scanf("%f", &produto->precoProduto);
    fflush(stdin);
}

void imprimirProduto(Produto *produto){
    printf("*----- Produto -----*\n");
    printf("Nome: %s\n", produto->nomeProduto);
    printf("Quantidade: %d\n", produto->quantidadeProduto);
    printf("Preco: %.2f\n", produto->precoProduto);
}

int main(){
    
    int qnt=0;

    printf("Quantidade de produtos que serao adicionados:");
    scanf("%d", &qnt);
    if(qnt<=0) return 1;

    Produto prod[qnt];
    
    fflush(stdin);

    for (int i = 0; i < qnt; i++){
        cadastrarProduto(&prod[i]);
    }
    for (int i = 0; i < qnt; i++){
        imprimirProduto(&prod[i]);
    }

    return 0;
}

