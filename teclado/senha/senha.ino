const int numLinhas = 4;
const int numColunas = 3;
const int debounce = 20;
const char teclado[numLinhas][numColunas] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}};
const int PinosLINHAS[numLinhas] = { 7, 2, 3, 5};
const int PinosCOLUNAS[numColunas] = { 6, 8, 4};
const char kNADA = 0;
const int motor = 22;
void setup(){
for(int linha = 0; linha < numLinhas; linha++){
pinMode(PinosLINHAS[linha], INPUT);
digitalWrite(PinosLINHAS[linha], HIGH); //habilita pull-up
}
for(int coluna = 0; coluna < numColunas; coluna++){
pinMode(PinosCOLUNAS[coluna], OUTPUT);
digitalWrite(PinosCOLUNAS[coluna], HIGH);
}
pinMode(motor,OUTPUT);
}
void loop(){
char tecla = TeclaPressionada();
if(tecla != kNADA){
if(tecla == '1'){
  digitalWrite(motor,HIGH);
}
 if(tecla =='2'){
  digitalWrite(motor,LOW);
  }
 }
}

char TeclaPressionada(){
char tecla = kNADA;
boolean achou = false;
for(int coluna = 0; coluna < numColunas; coluna++){
digitalWrite(PinosCOLUNAS[coluna], LOW);
for(int linha = 0; linha < numLinhas; linha++){
if(digitalRead(PinosLINHAS[linha]) == LOW){
delay(debounce);
}
if(digitalRead(PinosLINHAS[linha]) == LOW){
while(digitalRead(PinosLINHAS[linha]) != HIGH);
tecla = teclado[linha][coluna];
achou = true;
break;
}
}
digitalWrite(PinosCOLUNAS[coluna], HIGH);
if(achou){
break;
}
}
return tecla;
} //fim do código
