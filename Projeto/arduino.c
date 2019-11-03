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

typedef struct sTAREFA{
  char texto[90];
  char data_tarefa[10];
  /*  tarefa definida com até 100 caracteres porque a tela não 
  consegue mostrar mais que isso xD
  */
}TAREFA;

typedef struct sCELULA{
  TAREFA info;
  struct sCELULA *esq;
  struct sCELULA *dir;
}CELULA;

void insere_inicio (CELULA **lista, char *frase,char *ptrData);
void tela_print(struct sCELULA *lista);
void init (struct sCELULA *lista);
void get_frase(struct sCELULA **lista);

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

void init(struct sCELULA *lista){
  lista = NULL;
}

void erroFuncao(){
  vermelhoFuncao();
  lcd.clear();
  lcd.print("ERRO!!!");
  delay(1000);
  lcd.clear();
  brancoFuncao();
}

int empty(struct sCELULA *lista){
  if(lista == NULL){
    erroFuncao();
    return 1;
  }
    return 0;
}

void get_frase(struct sCELULA **lista){
  
  int i=0;
  azulFuncao();
  char frase[90],data[10];
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("INSIRA A TAREFA:");
  lcd.setCursor(0,1);
  lcd.print("LIM100CARACTERES");
  while(i == 0){
    while(Serial.available() > 0){
      frase[i]=Serial.read();
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
      data[i]=Serial.read();
      i++;
      delay(10);
    }
  }
  insere_inicio(lista,frase,data);
  menu(*lista);
}/* Funcao criada pra pegar a frase e entrar na insere_inicio */

void insere_inicio (struct sCELULA **lista, char *frase,char *ptrData){
  CELULA *q;
  q = (CELULA *) malloc(sizeof(CELULA));
   brancoFuncao();
  lcd.clear();
  if(q != NULL){
    strcpy(q->info.texto,frase);
    strcpy(q->info.data_tarefa, ptrData);
    q->esq = NULL;
    q->dir = *lista;
    if(!empty(*lista)){
      (*lista)->esq = q;
    }
    *lista = q;
  }else{
    erroFuncao();
    exit(1);
  }
  verdeFuncao();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tarefa adiciona-");
  delay(10);
  lcd.setCursor(0,1);
  lcd.print("da com sucesso!!");
  delay(10);
  menu(*lista);
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
  CELULA *aux;
  aux = lista;
  int BotEstadoDir = 0,BotEstadoEsq = 0;//seta os estados para LOW
  
  Serial.println(aux->info.texto);
  
  int i=0,stringTam;
  stringTam = strlen(aux->info.texto);
  
  if(stringTam>50){
    lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print(aux->info.texto);
    
    lcd.setCursor(0,1);
    lcd.print(aux->info.texto[50]);
  }else{
    //Limpa a tela
   lcd.clear();
    //Posiciona o cursor na coluna 0, linha 0;
    lcd.setCursor(0,0);
    //Envia o texto para o LCD
    lcd.print(aux->info.texto);
  }
  
  BotEstadoDir = digitalRead(BotDirPin);
  BotEstadoEsq = digitalRead(BotEsqPin);
  delay(100);

  //Rolagem para a esquerda
  do{
    lcd.scrollDisplayLeft();
    delay(100);
    BotEstadoEsq = digitalRead(BotEsqPin);
    BotEstadoDir = digitalRead(BotDirPin);
    if(BotEstadoEsq == HIGH){
      aux = aux->esq;
    }
    if(BotEstadoDir == HIGH){
      aux = aux->dir;
    }
  }while(BotEstadoEsq == LOW || BotEstadoDir == LOW);
  
}

int clickDir=0, clickSelect=0, intLoop=0;
/*Variáveis declaradas globalmente pois o loop gerado pelo arduino
faz com que elas fiquem sempre zeradas, não deixando navegar entre 
as opções do menu.
*/

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
  
  //Define os botões como entrada
  pinMode(BotDirPin, INPUT);
  pinMode(BotEsqPin, INPUT);
  pinMode(BotSeleciona, INPUT);
  
  Serial.begin(9600);
  //Define os leds
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(vermelho, OUTPUT);
  struct sCELULA *f;
  init (f);
}
void loop()
{ 
  struct sCELULA *f;
  brancoFuncao();
  menu(f);
}