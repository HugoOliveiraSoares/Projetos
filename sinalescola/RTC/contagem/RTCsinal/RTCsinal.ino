#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

const int sirene = 12;

int horaLiga[] = {7, 8, 8, 9, 10, 10, 11, 12, 13, 14, 14, 15, 16, 16, 17};
int minutoLiga[] = {10, 00, 50, 40, 00, 50, 40, 30, 10, 00, 50, 40, 00, 50, 40};
int segundoLiga[] = {00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00};

int horaDesliga[] = {7, 8, 8, 9, 10, 10, 11, 12, 13, 14, 14, 15, 16, 16, 17};
int minutoDesliga[] = {10, 00, 50, 40, 00, 50, 40, 30, 10, 00, 50, 40, 00, 50, 40};
int segundoDesliga[] = {05, 05, 05, 05, 05, 05, 05, 05, 05, 05, 05, 05, 05, 05, 05};

void setup(){
Serial.begin(57600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
 if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

pinMode(amplificador, OUTPUT);
pinMode(sirenegeral,OUTPUT); 
pinMode(sireneprofessor,OUTPUT); 
}
void loop (){

DateTime now = rtc.now();

alarme(now.hour(),now.minute());

Serial.print(now.day(), DEC);
Serial.print('/');
Serial.print(now.month(), DEC);
Serial.print('/');
Serial.print(now.year(), DEC);
Serial.print(' ');
Serial.print(zero(now.hour()));
Serial.print(':');
Serial.print(zero(now.minute()));
Serial.print(':');
Serial.print(zero(now.second()));
Serial.println();
delay(1000);
}

String zero(int digits){
String lead;
if (digits < 10){
lead ="0"+ String(digits);
}
else{
lead = String(digits);
}
return lead;
}
