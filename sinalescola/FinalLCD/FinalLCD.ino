/* Projeto de Hugo Oliveira Soares
 *  O arduino ira fazer o controle do horario do acionamento da musica 
atravez de um leitor MP3 que,um rele acionado pelo o arduino, fara a substituição do botao PLAY, mostrando o Horario na tela de LCD.
O RTC(relogio digital)é ligado nos pinos SCL,SDA*/

//bibliotecas
#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h> 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);// pinos do arduino
RTC_DS1307 rtc;

//variaeis do tempo
int hora = 0;
int minuto = 0;
int segundo = 0;

const int rele1 = 13; // Botao PLAY do leitor MP3
const int rele2 = 10; // Alimentação do leitor
const int rele3 = 9;// Alimentação do amplificador
const int rele4 = 8;// Sirene

void setup() {
//verifica se o RTC esta funcionando
if (!rtc.isrunning()) {
lcd.setCursor(0, 1);
lcd.print("RTC parado, vou ajustar com a hora da compilacao...");
rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

// Declara uma variável para armazenar dados   
Wire.begin();
rtc.begin();
lcd.begin(16, 2);
pinMode(rele1, OUTPUT);
pinMode(rele2, OUTPUT);
pinMode(rele3, OUTPUT);
pinMode(rele4, OUTPUT);
digitalWrite(rele1, LOW);
digitalWrite(rele2, LOW);
digitalWrite(rele3, LOW);
digitalWrite(rele4, LOW);
}

void printnn(int n) {
// imprime um numero com 2 digitos
// acrescenta zero `a esquerda se necessario
String digitos = String(n);
if (digitos.length() == 1) {
digitos = "0" + digitos;
}
lcd.print(digitos);
}

void loop() {
  if (!rtc.isrunning()) {
lcd.print("RTC parado");
  while (1);
  }
  
  // Obtem a data e hora correntes e armazena em tstamp
DateTime tstamp = rtc.now();
hora = (tstamp.hour());
minuto = (tstamp.minute());
segundo = (tstamp.second());

lcd.setCursor(0, 0);
printnn(tstamp.day());
lcd.print('/');
printnn(tstamp.month());
lcd.print('/');
lcd.print(tstamp.year(), DEC);
lcd.setCursor(0, 1);
lcd.print (' ');
printnn(tstamp.hour());
lcd.print(':');
printnn(tstamp.minute());
lcd.print(':');
printnn(tstamp.second());
delay(1000);
lcd.clear();

// Periodo da manha--------------------------------------------------------------
if (hora == 7 && minuto == 9 && segundo == 56) {
alarme();//Inicio turno da manhã
}

  if (hora == 7 && minuto == 55 && segundo == 0) {
sirene();//sirene de 5 min
}

if (hora == 7 && minuto == 59 && segundo == 56) {
alarme();//Aula 2
}
  if (hora == 8 && minuto == 45 && segundo == 0) {
sirene();//sirene de 5 min
}

if (hora == 8 && minuto == 49 && segundo == 56) {
alarme();//Aula 3
}
 
  if (hora == 9 && minuto == 35 && segundo == 0) {
sirene();//sirene de 5 min
}
if (hora == 9 && minuto == 39 && segundo == 56) {
alarme();//Recreio
}
  if (hora == 9 && minuto == 45 && segundo == 0) {
sirene();//sirene de 5 min
}

if (hora == 9 && minuto == 59 && segundo == 56) {
alarme();//Aula 4
}

if (hora == 10 && minuto == 45 && segundo == 0) {
sirene();//sirene de 5 min
}

if (hora == 10 && minuto == 49 && segundo == 56) {
alarme();//Aula 5
}

if (hora == 11 && minuto == 35 && segundo == 0) {
sirene();//sirene de 5 min
}

if (hora == 11 && minuto == 39 && segundo == 56) {
alarme();//Aula 6
}

if (hora == 12 && minuto == 25 && segundo == 0) {
sirene();//sirene de 5 min
}

if (hora == 12 && minuto == 29 && segundo == 56) {
alarme();//Fim turno da manhã
}

//Periodo da tarde----------------------------------------------------------------
if (hora == 12 && minuto == 59 && segundo == 56) {
alarme();//Inicio turno da tarde
}

if (hora == 12 && minuto == 35 && segundo == 0) {
sirene();//sirene de 5 min
}

if (hora == 13 && minuto == 49 && segundo == 56) {
alarme();//Aula 2
}

if (hora == 14 && minuto == 35 && segundo == 0) {
sirene();//sirene de 5 min
}

if (hora == 14 && minuto == 39 && segundo == 56) {
alarme();//Aula 3
}

if (hora == 15 && minuto == 25 && segundo == 0) {
sirene();//sirene de 5 min
}

if (hora == 15 && minuto == 29 && segundo == 56) {
alarme();//Recreio
}

if (hora == 15 && minuto == 45 && segundo == 0) {
sirene();//sirene de 5 min
}

if (hora == 15 && minuto == 59 && segundo == 56) {
alarme();//Aula 4
}

if (hora == 16 && minuto == 45 && segundo == 0) {
sirene();//sirene de 5 min
}

if (hora == 16 && minuto == 49 && segundo == 56) {
alarme();//Aula 5
}

if (hora == 17 && minuto == 35 && segundo == 0) {
sirene();//sirene de 5 min
}

if (hora == 17 && minuto == 39 && segundo == 56) {
alarme();//Fim turno da tarde
   }
 }

void alarme() {
digitalWrite(rele3, HIGH);//alimenta o amplificador
digitalWrite(rele2, HIGH);//alimenta o leitor
delay(43000);
digitalWrite(rele1, HIGH);
delay(100); 
digitalWrite(rele1, LOW);
delay(3000);
digitalWrite(rele2, LOW);
}
void sirene(){
lcd.print("Faltam 5min");
digitalWrite(rele4,HIGH);
delay(1000);  
digitalWrite(rele4,LOW);
}
 //Fim do codigo
