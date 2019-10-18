#include <LiquidCrystal.h>
#include <stdio.h>
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

typedef struct sData{
  int dia,mes,ano;

}DATA;

typedef struct sTAREFA{
  char texto[100];
  DATA data;
  /*  tarefa definida com até 100 caracteres porque a tela não 
  consegue mostrar mais que isso xD
  */
}TAREFA;

typedef struct sCELULA{
  TAREFA info;
  struct sCELULA *esq;
  struct sCELULA *dir;
}CELULA;

CELULA* getnode();
void insere_inicio (CELULA **lista, char frase[100]);
void tela_print(struct sCELULA *lista);

//Funções responsáveis por executar o brilho selecionado
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
  lcd.print("ERRO!!!");
  delay(1000);
  lcd.clear();
  brancoFuncao();
}

CELULA* getnode(){
  return (CELULA *) malloc(sizeof(CELULA));
}

int empty(struct sCELULA *lista){
  if(lista == NULL){
    erroFuncao();
    return 1;
  }
    return 0;
}

void get_frase(struct sCELULA **lista){
  char frase[100];
  
  azulFuncao();
  
  lcd.clear();
  lcd.print("TAREFA:");
  
  fgets(frase, 100, stdin);
  insere_inicio(lista, frase);
  
  brancoFuncao();
}/* Funcao criada pra pegar a frase e entrar na insere_inicio */

void insere_inicio (struct sCELULA **lista, char *frase){
  CELULA *q;
  q = getnode();
  if(q != NULL){
    strcpy(q->info.texto,frase);
    q->esq = NULL;
    q->dir = *lista;
    if(!empty(*lista))
      (*lista)-> esq = q;
    *lista = q;
  }else{
    erroFuncao();
    exit(1);
  }
}
void remove_inicio(struct sCELULA **lista){
  CELULA *q;

  q = *lista;
  if(!empty(*lista)){
    *lista = q->dir;
    (*lista)->esq = NULL;
    free(q);
  }else{
    erroFuncao();
    exit(1);
  }
}

void tela_print(struct sCELULA *lista){
  
  int BotEstadoDir = 0,BotEstadoEsq = 0;//seta os estados para LOW
  
  int i=0,stringTam;
  stringTam = strlen(lista->info.texto);
  if(stringTam>50){
    lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print(lista->info.texto);
    
    lcd.setCursor(0,0);
    lcd.print(lista->info.texto[50]);
  }else{
    //Limpa a tela
   lcd.clear();
    //Posiciona o cursor na coluna 0, linha 0;
    lcd.setCursor(0,0);
    //Envia o texto para o LCD
    lcd.print(lista->info.texto);
  }

  
  BotEstadoDir = digitalRead(BotDirPin);
  BotEstadoEsq = digitalRead(BotEsqPin);
    delay(1000);

  //Rolagem para a esquerda
  do{
    lcd.scrollDisplayLeft();
    delay(100);
    BotEstadoDir = digitalRead(BotDirPin);
    BotEstadoEsq = digitalRead(BotEsqPin);
  }while(BotEstadoEsq == LOW || BotEstadoDir == LOW);
   
  //Rolagem para a direita
  /*do{
    lcd.scrollDisplayRight();
    delay(100);
  }while(frase[i]!='\0');*/
}

int clickDir=0, clickSelect=0, intLoop=0;

void menu(struct sCELULA *lista){
  
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
     tela_print(lista);
   }
   if(digitalRead(BotSeleciona)==HIGH && clickDir == 1){
      get_frase(&lista);
   }
   if(digitalRead(BotSeleciona)==HIGH && clickDir == 2){
     remove_inicio(&lista);
   }
}


void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  
  //Define os botões como INPUT
  pinMode(BotDirPin, INPUT);
  pinMode(BotEsqPin, INPUT);
  pinMode(BotSeleciona, INPUT);
  
  Serial.begin(9600);
  //Define os leds
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(vermelho, OUTPUT);
}
void loop()
{ 
  struct sCELULA *f; 
  brancoFuncao();
  menu(f);
}