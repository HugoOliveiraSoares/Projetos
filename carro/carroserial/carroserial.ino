
/*
  comandos:
    - F : para frente
    - B : para tras
    - R : direita
    - L : esuerda
    - S : for OFF

*/
#include <Servo.h>

#define servo 3
const int motorA = 5; 
const int dirA = 7;
Servo s;

byte b;
int pos = 90;

// ------------------------------------------------

void setup(){
  Serial.begin(9600);
  Serial.println("Start");
  
  s.attach(servo);
  pinMode(motorA, OUTPUT);
  pinMode(dirA, OUTPUT);
  
  s.write(pos);
  
}


// ------------------------------------------------

void loop(){
  
  if(Serial.available() > 0){
    b = Serial.read();
    
    switch(b){
      // Para frente-------------------------------
      case 'F':
       Serial.println("frente");
       digitalWrite(dirA, HIGH); //SENTIDO DE ROTACAO
       analogWrite(motorA, 150); //VELOCIDADE
       
       break;
      
      // Para tras-------------------------------
      case 'B':
       Serial.println("tras");
       digitalWrite(dirA, LOW); //SENTIDO DE ROTACAO
       analogWrite(motorA, 150); //VELOCIDADE
       
       break;
      
      //  Direita--------------------------------
      case 'L':
        Serial.println("esquerda");
        digitalWrite(dirA, HIGH);
        analogWrite(motorA, 150);
        for(pos = 90;pos > 75; pos--)
        {
            s.write(pos);
            delay(10);
        }
        break;
      // Esquerda------------------------------
      case 'R':
        Serial.println("direita");
        digitalWrite(dirA, HIGH);
        analogWrite(motorA, 150);
        for(pos = 90; pos < 110;pos++)
        {
          s.write(pos);
          delay(10);
        }
        
         break;
       //------------------------------------------  
       case 'H':
      Serial.println("backLeft");
      digitalWrite(dirA, LOW);
      analogWrite(motorA, 150);
      for(pos = 90; pos > 75;pos--)
      {
        s.write(pos);
        delay(10);
      }
      
       break;


       case 'J':
    Serial.println("backRight");
    digitalWrite(dirA, LOW);
    analogWrite(motorA, 150);
    for(pos = 90; pos < 100;pos++)
    {
      s.write(pos);
      delay(10);
    }
       break;
      // Off------------------------------------
      case 'S':
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
