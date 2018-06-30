
const int pino_led = 13;
char buf;
 
void setup()
{
  pinMode(pino_led, OUTPUT);
  Serial.begin(9600);
  Serial.println("Start");
}
 
void loop()
{
  //Serial.println("Start");
  while (Serial.available() > 0)
  {
    buf = Serial.read();
    // Caso seja recebido o caracter L, acende o led
    if (buf == 'L')
    {
      digitalWrite(pino_led,1); // Liga o led da porta 13
      // Envia a resposta para o Raspberry
      Serial.println("Recebido! - Estado Led: Ligado");
         
    }else if(buf == 'D')
    {  
       digitalWrite(pino_led,0);
       Serial.println("Recebido! - Estado Led: Desligado");
    }else
    {
      Serial.println("Nao Reconhecido");
      }
  }
}
