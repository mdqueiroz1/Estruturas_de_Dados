#include<stdio.h>
#include<stdlib.h>

typedef struct Data{
	int dia;
	char mes[10];
	int ano;
}data;

void imprimir(data dat, int p){
	printf("Pessoa %d\n\n",p+1);
	printf("Dia: %d\tMes:%s\tAno:%d\t",dat.dia,dat.mes,dat.ano);
	printf("\n\n");
}

data cadastro(data dnAluno){
	printf("Informe sua data de nascimento, com o mês por extenso.\n");
	scanf("%d", &dnAluno.dia);
	fflush(stdin);
	scanf("%s", &dnAluno.mes);
	fflush(stdin);
	scanf("%d",&dnAluno.ano);
	return dnAluno;
}

int main(){

	data dataNas[36];

	int i;

	for(i=0;i<=1;i++){
		cadastro(dataNas[i]);
	}
	for(i=0;i<=1;i++){
		imprimir(dataNas[i],i);
	}

	return 0;

}
