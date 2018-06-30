#include <Servo.h>

/* a:braço lado esquerdo
   A:braço lado direito
   r:braço pos inicial
   R:braço pos inicial
   w:braço pra cima
   W:braço pra baixo
   s:garra pra baixo
   S:garra pra cima
   f:garra abre
   F:garra fecha
    */


#define servo1 3 //servo base
#define servo2 5 //braço pra cima/baixo
#define servo3 6 //garra pra cima/baixo
#define servo4 9 //abre/fecha garra
 //Criando objeto da classe Servo
Servo s1;
Servo s2;
Servo s3;
Servo s4;

int pos = 0;
byte b;
void setup() {
  //associando o pino digital ao objeto da classe Servo
  s1.attach(servo1);
  s2.attach(servo2);
  s3.attach(servo3);
  s4.attach(servo4);
  Serial.begin(9600);
  s1.write(90);
  s2.write(50);
  s3.write(0);
  s4.write(0);
}

void loop() {
  if(Serial.available()){
    b = Serial.read();
    switch(b){
     //servo1 base----------------------------------------------------
      case 'a':
     for(pos = 90;pos > 0; pos--){
      s1.write(pos);
      delay(12);}
      
     break;
    
    case 'A':
    for(pos = 90; pos < 180;pos++){
    s1.write(pos);
    delay(12);}
    break;
   
    
    case 'r':
    for(pos = 0; pos < 90;pos++){
    s1.write(pos);
    delay(12);}
    break; 
  
   
    case 'R':
    for(pos = 180; pos > 90;pos--){
    s1.write(pos);
    delay(12);}
    break; 
   // servo2 braço pra cima/baixo-----------------------------------------------------
    case 'w':
    for(pos = 50; pos < 130;pos++){
    s2.write(pos);
    delay(12);}
    break;

    case 'W':
    for(pos = 130; pos > 50;pos--){
    s2.write(pos);
    delay(12);}
    break;
   
   //servo3 garra pra cima/baixo---------------------------------------------------------
     case 's':
    for(pos = 0; pos < 90;pos++){
    s3.write(pos);
    delay(12);}
    break;
    
     case 'S':
    for(pos = 90; pos > 0;pos--){
    s3.write(pos);
    delay(12);}
    break; 
    
    //servo4 abre/fecha garra-------------------------------------------------------
    case 'F':
    for(pos = 0; pos < 50;pos++){
    s4.write(pos);
    delay(12);}
    break;
   
    case 'f':
    for(pos = 50; pos > 0;pos--){
    s4.write(pos);
    delay(12);}
    break;
    }
  }
}
    
