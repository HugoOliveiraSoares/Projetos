
/*
  comandos:
    - w : para frente
    - s : para tras
    - d : direita
    - a : esuerda
    - f : for OFF

*/
#include <Servo.h>

#define servo 3
const int motorA = 5; 
const int dirA = 7;
Servo s;

byte b;
int pos;

// ------------------------------------------------

void setup(){
  Serial.begin(9600);
  Serial.println("Start");
  
  s.attach(servo);
  pinMode(motorA, OUTPUT);
  pinMode(dirA, OUTPUT);
  
  s.write(90);
  
}

// ------------------------------------------------

void loop(){
  
  if(Serial.available() > 0){
    b = Serial.read();
    
    switch(b){
      // Para frente-------------------------------
      case 'w':
       Serial.println("frente");
       for(int x =0; x <= 200; x++)
       { 
          digitalWrite(dirA, HIGH); //SENTIDO DE ROTACAO
          analogWrite(motorA, x); //VELOCIDADE
          //Serial.println("frente");  
          delay(10);
       }
        break;
      
      // Para tras-------------------------------
      case 's':
        Serial.println("tras");
       for(int x =0; x <= 200; x++)
       { 
          digitalWrite(dirA, LOW); //SENTIDO DE ROTACAO
          analogWrite(motorA, x); //VELOCIDADE
          //Serial.println("tras");  
          delay(10);
       }
       
        break;
      
      //  Direita--------------------------------
      case 'a':
        Serial.println("esquerda");
        for(pos = 90;pos > 0; pos--)
        {
            s.write(pos);
            delay(10);
        }
        break;
      // Esquerda------------------------------
      case 'd':
        Serial.println("direita");
        for(pos = 90; pos < 180;pos++)
        {
          s.write(pos);
          delay(10);
        }
        
         break;
      // Off------------------------------------
      case 'f':
        analogWrite(motorA, 0); //VELOCIDADE
        s.write(90);
        Serial.println("OFF");
        break;
        
      default:
        Serial.println("INVALIDO!");
        break;
      }
  }
  
}
