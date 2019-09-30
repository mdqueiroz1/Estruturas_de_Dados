#include <LiquidCrystal.h>
#include <stdio.h>
#include <string.h>

//Declarando as funções.
typedef struct sTAREFA;
typedef struct sCELULA;

//pinos dos botoes
#define BotDirPin 7
#define BotEsqPin 8

//pinos do led RGB
#define vermelho 10
#define verde 9
#define azul 6

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

  
typedef struct sTAREFA{
  char texto[100], dia[8];
  /* dia será dd/mm/aa ou dd/mm/aaaa?
  tarefa definida com até 100 caracteres porque a tela não 
  consegue mostrar mais que isso xD
  */
}TAREFA;

typedef struct sCELULA{
  TAREFA info;
  struct sCELULA *esq;
  struct sCELULA *dir;
}CELULA;

CELULA* getnode();
void insere_inicio (CELULA **lista, TAREFA tarefa);
void tela_print(char *frase);

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
CELULA* getnode(){
  return (CELULA *) malloc(sizeof(CELULA));
}

int empty(CELULA *lista){
  if(lista == NULL){
    vermelhoFuncao();
    lcd.clear();
    lcd.print("Lista vazia!");
    delay(1000);
    return 1;
  }
    return 0;
}

void insere_inicio (CELULA **lista, TAREFA tarefa){
  CELULA *q;
  q = getnode();
  if(q != NULL){
    q->info->texto = gets();
    q->esq = NULL;
    q->dir = *lista;
    if(!empty(*lista))
      (*lista)-> esq = q;
    *lista = q;
  }else{
    vermelhoFuncao();
    delay(1000);
    brancoFuncao();
    exit(1);
  }
}

int BotEstadoDir = 0,BotEstadoEsq = 0;//seta os estados para LOW  

void tela_print(char *frase){
   
  int i=0,stringTam;
  stringTam = strlen(frase);
  if(stringTam>50){
    lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print(frase);
    
    lcd.setCursor(0,0);
    lcd.print(frase[50]);
  }else{
    //Limpa a tela
   lcd.clear();
    //Posiciona o cursor na coluna 0, linha 0;
    lcd.setCursor(0,0);
    //Envia o texto para o LCD
    lcd.print(frase);
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

void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  
  //Define os botões como INPUT
  pinMode(BotDirPin, INPUT);
  pinMode(BotEsqPin, INPUT);
  
  Serial.begin(9600);
  //Define os leds
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(vermelho, OUTPUT);
}

void loop()
{ 
  brancoFuncao();
  char string[100]={"1234567890abcdefghijklmnopqrstuvwxyz0000acima de 50 caracteres"};
  tela_print(string);
}