/* Projeto de Hugo Oliveira Soares
 *  O arduino ira fazer o controle do horario do acionamento da musica 
atravez de um leitor MP3 que,um rele acionado pelo o arduino, fara a substituição do botao START.
A contagem da hora é via codigo*/
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 rtc;

//variaveis de tempo
int hora = 0;
int minuto = 0;
int segundo = 0;

const int rele1 = 13; // Botao PLAY do leitor MP3
const int rele2 = 10; // Alimentação do leitor
const int rele3 = 9;// Alimentação do amplificador
const int rele4 = 8;// Sirene

void setup () {
Wire.begin();
Serial.begin(57600);
pinMode(rele1, OUTPUT);
pinMode(rele2, OUTPUT);
pinMode(rele3, OUTPUT);
pinMode(rele4, OUTPUT);
digitalWrite(rele1, LOW);
digitalWrite(rele2, LOW);
digitalWrite(rele3, LOW);
digitalWrite(rele4, LOW);

if (!rtc.isrunning()) {
    Serial.println("RTC parado vou ajustar no horario da compilacao");
    // ajusta o RTC com o horario em que o sketch foi compilado
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
}

void loop () {
if (!rtc.isrunning()) {
    Serial.println("RTC parado");
    
    }

// Obtem a data e hora correntes e armazena em tstamp
DateTime tstamp = rtc.now();
hora = (tstamp.hour());
minuto = (tstamp.minute());
segundo = (tstamp.second());


Serial.print(tstamp.day());
Serial.print('/');
Serial.print(tstamp.month());
Serial.print('/');
Serial.print(tstamp.year(), DEC);
Serial.print (' ');
Serial.print(tstamp.hour());
Serial.print(':');
Serial.print(tstamp.minute());
Serial.print(':');
Serial.print(tstamp.second());
Serial.println();
delay(1000);


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

if (hora == 13 && minuto == 45 && segundo == 0) {
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

if (hora == 15 && minuto == 55 && segundo == 0) {
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
Serial.println("Sinal");
digitalWrite(rele3, HIGH);//alimenta o amplificador
digitalWrite(rele2, HIGH);//alimenta o leitor
delay(43000);
digitalWrite(rele1, HIGH);
delay(100); 
digitalWrite(rele1, LOW);
delay(5000);
digitalWrite(rele2, LOW);
digitalWrite(rele3, LOW);
}
void sirene(){
Serial.println("Faltam 5min");
digitalWrite(rele4,HIGH);//aciona a sirene
delay(4000);  
digitalWrite(rele4,LOW);
}
