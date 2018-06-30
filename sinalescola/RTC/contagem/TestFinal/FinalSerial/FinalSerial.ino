
/* Projeto de Hugo Oliveira Soares
 *  O arduino ira fazer o controle do horario do acionamento da musica 
atravez de um leitor MP3 que,um rele acionado pelo o arduino, fara a substituição do botao START. */
#include <Wire.h>
#include "RTClib.h"
// initializa os pinos do arduino
RTC_Millis rtc;

int hora = 0;
int minuto = 0;
int segundo = 0;
const int rele = 10;

void setup () {
Wire.begin();
Serial.begin(57600);
pinMode(rele, OUTPUT);
digitalWrite(rele, LOW);

rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop () {
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


// Periodo da manha------------------------------------------------
if (hora == 7 && minuto == 10 && segundo == 0) {
alarme();
  }
if (hora == 8 && minuto == 0 && segundo == 0) {
alarme();
  }
if (hora == 8 && minuto == 50 && segundo == 0) {
alarme();
  }
if (hora == 9 && minuto == 40 && segundo == 0) {
alarme();
  }

if (hora == 10 && minuto == 0 && segundo == 0) {
alarme();
  } 

if (hora == 10 && minuto == 50 && segundo == 0) {
alarme();
  }

if (hora == 11 && minuto == 40 && segundo == 0) {
alarme();
  }

if (hora == 12 && minuto == 00 && segundo == 0) {
alarme();
  }

//Periodo da tarde-------------------------------------------------
if (hora == 13 && minuto == 10 && segundo == 0) {
alarme();
  }
if (hora == 14 && minuto == 00 && segundo == 0) {
alarme();
  }
if (hora == 14 && minuto == 50 && segundo == 0) {
alarme();
  }
if (hora == 15 && minuto == 40 && segundo == 0) {
alarme();
  }

if (hora == 16 && minuto == 0 && segundo == 0) {
alarme();
  }

if (hora == 16 && minuto == 50 && segundo == 0) {
alarme();
  }

if (hora == 17 && minuto == 40 && segundo == 0) {
alarme();
  }
}
void alarme() {
digitalWrite(rele, HIGH);
delay(100);
digitalWrite(rele, LOW);
delay(40000);
digitalWrite(rele, HIGH);
delay(100);
digitalWrite(rele, LOW);
}
