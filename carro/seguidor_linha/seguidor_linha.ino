#define M1 5 //velocidade motor A - de 0 a 255, Motor direito
#define M2 6 // velocidade motor B - de 0 a 255, Motor esquerdo
#define dirA 7 // Direção
#define dirB 8 // Direção
#define S1 0 // Sensor ligado no pino 0 - direito
#define S2 1 // Sensor ligado no pino 1 - esquerdo
#define led 13

void setup()
{
  pinMode(M1, OUTPUT); // Motor como saida, direito
  pinMode(M2, OUTPUT); // Motor como saida, esquerdo
  pinMode(dirA, OUTPUT); // Motor como saida
  pinMode(dirB, OUTPUT); // Motor como saida
  pinMode(S1, INPUT); // sensor como entrada (leitura)
  pinMode(S2, INPUT); // sensor como entrada (leitura)
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, HIGH);
  pinMode(led, OUTPUT);
  delay(1000);
}

void loop()
{
  int valorlido  = analogRead(S2); // esquerdo
  int valorlido2 = analogRead(S1); // direito

  if ((valorlido < 500) && (valorlido2 < 500)) // Frente
  {
    analogWrite(M1, 80);
    analogWrite(M2, 80);
    digitalWrite(led, LOW);
  }

  if ((valorlido > 400) && (valorlido2 < 400)) //Direita
  {
    analogWrite(M1, 0);
    analogWrite(M2, 80);
    digitalWrite(led, HIGH);
  }

  if ((valorlido < 400) && (valorlido2 > 400)) // Esquerda
  {
    analogWrite(M1, 80);
    analogWrite(M2, 0);
    digitalWrite(led, HIGH);
  }

  if ((valorlido > 500) && (valorlido2 > 500)) // Para
  {
    analogWrite(M1, 0);
    analogWrite(M2, 0);
    digitalWrite(led, LOW);
  }
}
