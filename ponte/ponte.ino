#include <Servo.h>
#define servo1  3  // Porta digital 3 pwm
#define servo2  6
const int trig = 11;
const int echo = 12;
//Criando objeto da classe servo
Servo s1;
Servo s2;
int pos;
void setup() {
 pinMode(trig,OUTPUT);
 pinMode(echo, INPUT);
 //associando o pino digital ao objeto da classe Servo
 s1.attach(servo1);
 s2.attach(servo2);
//posição inicial para os servos
 s1.write(90); // correto
 s2.write(180);

}

void loop() {
 long duracao;
 long distancia;
 digitalWrite(trig, LOW);
 delayMicroseconds(2);
 digitalWrite(trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig, LOW);
 duracao = pulseIn(echo, HIGH);
 distancia = duracao / 58;

 if(distancia <= 10){
 s1.write(180); // correto
 s2.write(90);
delay(3000);
}
else{
  
  s1.write(90); // correto
  s2.write(180);
  }

 }
