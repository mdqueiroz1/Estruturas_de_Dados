#include <LiquidCrystal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declarando as funções.
typedef struct sTAREFA;
typedef struct sCELULA;

//pinos dos botoes
#define BotDirPin 8
#define BotEsqPin 7
#define BotSeleciona 13

//pinos do led RGB
#define vermelho 10
#define verde 9
#define azul 6

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

typedef struct sTAREFA{
  char texto[90];
  char data[10];
  int priori;
}TAREFA;

typedef struct sCELULA{
  TAREFA info;
  struct sCELULA *esq;
  struct sCELULA *dir;
}CELULA;

void init(struct sCELULA **celula){
  *celula = NULL;
}

struct sCELULA *f;//declaração do ponteiro

void vermelhoFuncao(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, HIGH);
}
void azulFuncao(){
  digitalWrite(azul, HIGH);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, LOW);
}
void verdeFuncao(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, LOW);
}
void amareloFuncao(){
  analogWrite(azul, 0);
  analogWrite(verde, 50);
  analogWrite(vermelho, 255);
}
void roxoFuncao(){
  analogWrite(azul, 207);
  analogWrite(verde, 0);
  analogWrite(vermelho, 255);
}
void brancoFuncao(){
  digitalWrite(azul, HIGH);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, HIGH);
}

void erroFuncao(){
  vermelhoFuncao();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("     Erro!!     ");
  delay(10);
  brancoFuncao();
}

void voltaFuncao(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CLICK P/ VOLTAR ");
  lcd.setCursor(0,1);
  lcd.print("<---------------");
}

int vazio(struct sCELULA *lista){ //testa se a lista esta vazia
  if(lista == NULL)
      return 1;
  
  return 0;
}

void remove_inicio(struct sCELULA **lista){ 
  CELULA *q;

  q = *lista;

  if(!vazio(q)){
    
    *lista= q->dir;
    free(q);
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  REMOVIDO COM  ");
    lcd.setCursor(0,1);
    lcd.print("     SUCESSO    ");
    Serial.println("Removido com sucesso");
    delay(1000);
    voltaFuncao();
  
  }else{
    erroFuncao();
  }
    delay(100);
  menu(*lista);
}

void insere_inicio (struct sCELULA **lista, char strtexto[90], char strdata[10], int priori){
  CELULA *q;

  q = (CELULA*) malloc(sizeof(CELULA));

  int i=0;
  azulFuncao();

  if(q!=NULL){
    strcpy(q->info.data, strdata);
    strcpy(q->info.texto, strtexto);
    q->info.priori = priori;
    q->esq = NULL;
    q->dir = (*lista);
    if(vazio(*lista))
      (*lista)->esq = q;
    
    (*lista) = q;
  }else{
    erroFuncao();
  }
  delay(10);
  brancoFuncao();
  Serial.println("Adicionado com sucesso");
  voltaFuncao();
  menu(*lista);
}

void printa_lista(struct sCELULA *lista){
  
  CELULA *aux;
  aux = lista;

  int clickSelect=0,paraLoop=0;

  if(!vazio(aux)){

    while(1){
      
      delay(10);
      
      if(paraLoop == 0){
        
        lcd.clear();
        if((strlen(aux->info.texto))>40){
          lcd.setCursor(0,0);
          lcd.print(aux->info.data);
          lcd.setCursor(0,11);
          lcd.print(aux->info.texto);
          lcd.setCursor(0,1);
          lcd.print(aux->info.texto[40]); 
        }else{
          lcd.setCursor(0,0);
          lcd.print(aux->info.data);
          lcd.setCursor(0,11);
          lcd.print(aux->info.texto);
        }
        paraLoop++;
      }
      
      lcd.scrollDisplayLeft();
      delay(200);
    if (digitalRead(BotSeleciona) == HIGH){
        delay(10);
        voltaFuncao();
        menu(lista);
      }
      if(digitalRead(BotDirPin) == HIGH){
        if((aux->dir)!= NULL){
          aux=aux->dir;
          delay(10);
          paraLoop=0;
        }else{
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("P/ SAIR APERTE");
          lcd.setCursor(0,11);
          lcd.print("O BOTAO SELECT");
          delay(1000);
          paraLoop=0;
        }
      }
      if(digitalRead(BotEsqPin) == HIGH){
        if((aux->dir)!= NULL){
          aux=aux->esq;
          delay(10);
          paraLoop=0;
        }else{
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("P/ SAIR APERTE");
          lcd.setCursor(0,11);
          lcd.print("O BOTAO SELECT");
          delay(1000);
          paraLoop=0;
        }
      }
    }
    delay(100);
  }else{
    erroFuncao();
    menu(lista);
  }
}

void insere_fim(struct sCELULA **lista, char insere_texto[90],char insere_data[8],int intPrioridade){
	CELULA *q;
	CELULA *aux;

	q = (CELULA*) malloc(sizeof(CELULA));

	if(q!= NULL) {
		strcpy(q->info.texto, insere_texto);
		strcpy(q->info.data, insere_data);
		q->info.priori = intPrioridade;
		q->esq = NULL;
		q->dir = NULL;
		if (vazio(*lista)){
			*lista = q;
		}else{
			aux = *lista;
			while (aux->dir != NULL)
				aux = aux->dir;

			aux->dir = q;
			q->esq = aux;
		}
	}else{
		erroFuncao();
	}
		delay(100);
  		voltaFuncao();
		menu(*lista);
}

void insere_lista(struct sCELULA **lista, char insere_texto[90],char insere_data[8],int intPrioridade){
  CELULA *aux;
  CELULA *q;

  q = (CELULA*) malloc(sizeof(CELULA));
  if(q != NULL){
    strcpy(q->info.texto, insere_texto);
    strcpy(q->info.data, insere_data);
    q->info.priori = intPrioridade;
  }else{
    erroFuncao();
    Serial.println("memoria");
    exit(1);
  }

  aux = (*lista);
  
  while(aux != NULL && intPrioridade >= aux->info.priori){
		aux = aux->dir;
	}

	if (aux == NULL){
		insere_fim(lista, insere_texto, insere_data, intPrioridade);
	}

	q->dir = aux->dir;
  	aux->dir = q;
	q->esq = aux;
  	
  

	if((*lista) == aux){
		(*lista) = q;
		delay(100);
		voltaFuncao();
		menu(*lista);
	}
	voltaFuncao();
	aux->esq->dir = q;
}

void recebe_dados(struct sCELULA *lista){
	
	char strtexto[90],strdata[10],strpriori[1];
  	int i=0;
  	int priori;

  	lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("INSIRA A TAREFA:");
  	lcd.setCursor(0,1);
  	lcd.print("LIM100CARACTERES");
  	while(i == 0){
    	while(Serial.available() > 0){
      		strtexto[i]=Serial.read();
      		i++;
      		delay(10);
    	}
  	}
  	delay(50);
  	i=0;
  	lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("INSIRA A DATA NA");
  	lcd.setCursor(0,1);
  	lcd.print("FORMA DD/MM/AAAA");  
  	while(i == 0){
    	while(Serial.available() > 0){
      		strdata[i]=Serial.read();
      		i++;
      		delay(10);
    	}
  	}
  	delay(50);
  	i=0;
  	lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("INSIRA A PRIORI");
  	lcd.setCursor(0,1);
  	lcd.print("DADE 1, 2 OU 3 ");  
  	while(i == 0){
    	while(Serial.available() > 0){
      		strpriori[i]=Serial.read();
      		i++;
      		delay(10);
          	priori = atoi(strpriori);
              Serial.println(priori);
    	}
  	}
  	delay(200);
  	insere_lista(&lista, strtexto, strdata, priori);
  	delay(200);
}

int clickDir=0, clickSelect=0, intLoop=0;
/*Variáveis declaradas globalmente pois o loop gerado pelo arduino
faz com que elas fiquem sempre zeradas, não deixando navegar entre 
as opções do menu.
*/

void menu(struct sCELULA *lista){
  
  while(1){
  
  if(clickDir>2){
    clickDir=2;
  }
  if(clickDir<0){
    clickDir=0;
  }
     
  if(clickDir==0 && intLoop==0){
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("    LISTA DE    ");
     lcd.setCursor(0,1);
     lcd.print("|-  AFAZERES  ->"); 
   }
   
   if(clickDir==1 && intLoop==0){
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("    ADICIONAR   ");
     lcd.setCursor(0,1);
     lcd.print("<-  NA LISTA  ->");       
   }

   if(clickDir==2 && intLoop==0){
     lcd.setCursor(0,0);
     lcd.print("     EXCLUIR    ");
     lcd.setCursor(0,1);
     lcd.print("<-  DA LISTA  -|");       
   }
   intLoop++;

   if(digitalRead(BotDirPin) == HIGH){
     clickDir++;
     delay(300);
     intLoop=0;
   }
   if(digitalRead(BotEsqPin) == HIGH){
     clickDir--;
     delay(300);
     intLoop=0;
   }
   if(digitalRead(BotSeleciona)==HIGH && clickDir == 0){
     printa_lista(lista);

   }
   if(digitalRead(BotSeleciona)==HIGH && clickDir == 1){
      recebe_dados(lista);
   }
   if(digitalRead(BotSeleciona)==HIGH && clickDir == 2){
     remove_inicio(&lista);
   }

  }

}

void setup(){
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);

  //Define os botões como entrada
  pinMode(BotDirPin, INPUT);
  pinMode(BotEsqPin, INPUT);
  pinMode(BotSeleciona, INPUT);

  Serial.begin(57600);
  //Define os leds
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(vermelho, OUTPUT);
  
  init (&f);
    
}

void loop()
{
  brancoFuncao();
  menu(f);
}