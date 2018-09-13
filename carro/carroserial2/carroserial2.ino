
/*
  comandos:
    - F : para frente
    - B : para tras
    - R : direita
    - L : esuerda
    - S : for OFF

*/
const int motorA = 5;
const int motorB = 6;
const int dirA = 7;
const int dirB = 8;

byte b;

// ------------------------------------------------

void setup(){
  Serial.begin(9600);
  Serial.println("Start");

  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  // pinMode(dirA, OUTPUT);
  // pinMode(dirB, OUTPUT);

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
       digitalWrite(dirB, HIGH); //SENTIDO DE ROTACAO
       analogWrite(motorB, 150); //VELOCIDADE

       break;

      // Para tras-------------------------------
      case 'B':
       Serial.println("tras");
       digitalWrite(dirA, LOW); //SENTIDO DE ROTACAO
       analogWrite(motorA, 150); //VELOCIDADE
       digitalWrite(dirB, LOW); //SENTIDO DE ROTACAO
       analogWrite(motorB, 150); //VELOCIDADE

       break;

      //  Direita--------------------------------
      case 'L':
        Serial.println("esquerda");
        digitalWrite(dirA, HIGH);
        analogWrite(motorA, 200);
        digitalWrite(dirB, HIGH);
        analogWrite(motorB, 90);

        break;
      // Esquerda------------------------------
      case 'R':
        Serial.println("direita");
        digitalWrite(dirA, HIGH);
        analogWrite(motorA, 90);
        digitalWrite(dirB, HIGH);
        analogWrite(motorB, 200);

        break;

      // Off------------------------------------
      case 'S':
        analogWrite(motorA, 0); //VELOCIDADE
        analogWrite(motorB, 0); //VELOCIDADE

        Serial.println("OFF");
        break;

      default:
        Serial.println("INVALIDO!");
        break;
      }
  }

}
