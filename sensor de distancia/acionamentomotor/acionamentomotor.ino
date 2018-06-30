const int motor = 30;
const int trig = 13;
const int echo = 12;

void setup() 
{
  pinMode(motor, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() 
{
  long duracao;
  long distancia;
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duracao = pulseIn(echo, HIGH);
  distancia = duracao / 58;
  
  if(distancia <= 5)
  {
    digitalWrite(motor,HIGH);}
  else
  {
    digitalWrite(motor,LOW);
  }
  
  delay(50);
  
}
