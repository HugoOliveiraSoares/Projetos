// SENSOR > 300 ESCURO
// SENSOR < 300 CLARO

#include <Servo.h>
Servo s; // define o nome do servo como s

const int motorA = 5; //velocidade motor A - de 0 a 255, Motor direito
const int motorB = 3; // pino do servo motor
const int dirA = 7; //direcao do motor A - HIGH ou LOW

int pos = 90; // posiçao do servo

 
int Sensor1 = 0; // Sensor ligado no pino 0
int Valor_Sensor1 = 0; // Valor lido do sensor2
int Sensor2 = 1; // Sensor ligado no pino 1
int Valor_Sensor2 = 0;// Valor lido do sensor2

void setup(){

  s.attach(motorB);
  s.write(pos);
  
  pinMode(motorA, OUTPUT);// Motor como saida
  pinMode(dirA, OUTPUT);
  digitalWrite(dirA, HIGH); // Motor vai para frente
  analogWrite(motorA, 0); // Velocidade
  
}

void loop(){
  Valor_Sensor1 = analogRead(Sensor1); // Armazena o valor lido pelo sensor1
  Valor_Sensor2 = analogRead(Sensor2); // Armazena o valor lido pelo sensor2
  
  if((Valor_Sensor1 < 500) && (Valor_Sensor2 < 500)){ // Se sensor1 e sensor2 lerem uma faixa escura o carro vai pra frente
    analogWrite(motorA, 50); // Velocidade 
  }
  
  if((Valor_Sensor1 > 500) && (Valor_Sensor2 < 500)){ // Se sensor1 ler uma faixa clara e sensor2 faixa escura o carro vai para a direita
    analogWrite(motorA, 50); // Motor desligado 
    for(pos = 90;pos > 75; pos--) // posiçao servo motor
    {    s.write(pos);   }
  }
  
  if((Valor_Sensor1 < 500) && (Valor_Sensor2 > 500)){ // Se sensor1 ler uma faixa clara e sensor2 faixa escura o carro vai para a esquerda
    analogWrite(motorA, 50); // Velocidade 
    for(pos = 90;pos < 110;pos++) // posiçao servo motor
    {    s.write(pos);   }
  }  
  
}
