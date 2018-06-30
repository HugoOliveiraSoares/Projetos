#include "Servo.h" //biblioteca para controle do servomotor
  
//Criando objeto da classe Servo
Servo servoMotor1Obj;  //para controlar o servo 1
Servo servoMotor2Obj;  //para controlar o servo 2
Servo servoMotor3Obj;  //para controlar o servo 3
Servo servoMotor4Obj;  //para controlar o servo 4 

//pinos analógicos dos potenciômetros
int const potenciometro1Pin = 0; //potenciômetro 1
int const potenciometro2Pin = 1; //potenciômetro 2
int const potenciometro3Pin = 2; //potenciômetro 3
int const potenciometro4Pin = 3; //potenciometro 4

//pino digital associado ao servomotor
int const servoMotor1Pin = 3; //controle do servomotor 1
int const servoMotor2Pin = 5; //controle do servomotor 2
int const servoMotor3Pin = 6; //controle do servomotor 3
int const servoMotor4Pin = 9; //controle do servomotor 4

//variáveis usadas para armazenar o valor lido nos potenciômetros
int valPotenciometro1; //potenciômetro 1
int valPotenciometro2; //potenciômetro 2
int valPotenciometro3; //potenciômetro 3
int valPotenciometro4; //potemciometro 4 

//variáveis para armazenar os valores em graus dos servomotores
int valServo1; //servomotor 1
int valServo2; //servomotor 2
int valServo3; //servomotor 3
int valServo4; //servomotor 4  

void setup() { 
  //associando o pino digital ao objeto da classe Servo
  servoMotor1Obj.attach(servoMotor1Pin); //Servo 1
  servoMotor2Obj.attach(servoMotor2Pin); //Servo 2
  servoMotor3Obj.attach(servoMotor3Pin); //Servo 3  
  servoMotor4Obj.attach(servoMotor4Pin); //Servo 4
} 
  
void loop() 
{ 
  //lendo os valores dos potenciômetros 
  //o (intervalo do potenciômetro é entre 0 e 1023)
  valPotenciometro1 = analogRead(potenciometro1Pin); 
  valPotenciometro2 = analogRead(potenciometro2Pin); 
  valPotenciometro3 = analogRead(potenciometro3Pin);      
  valPotenciometro4 = analogRead(potenciometro4Pin);
  
  //mapeando os valores dos potenciômetros para a escala 
  //do servo (intervalo entre 5 e 175 graus)      
  valServo1 = map(valPotenciometro1, 0, 1023, 5, 175); 
  valServo2 = map(valPotenciometro2, 0, 1023, 5, 175); 
  valServo3 = map(valPotenciometro3, 0, 1023, 5, 175);   
  valServo4 = map(valPotenciometro4, 0, 1023, 5, 175);     
  
  //definindo o valor/posição dos servomotores em graus
  servoMotor1Obj.write(valServo1); 
  servoMotor2Obj.write(valServo2); 
  servoMotor3Obj.write(valServo3); 
  servoMotor4Obj.write(valServo4); 
  
  delay(15);   
}
