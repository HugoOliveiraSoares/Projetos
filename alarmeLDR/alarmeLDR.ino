const int LDR = 0;
const int Buzzer = 12;
int ValorLido = 0;
int pwm = 0;
void setup() {
  pinMode(Buzzer,OUTPUT);
}

void loop() {
  ValorLido = analogRead(LDR);
  if(ValorLido < 716){
    digitalWrite(Buzzer,HIGH);
    }  
    else{
      digitalWrite(Buzzer,LOW);
      }
      if(ValorLido > 250){
        digitalWrite(Buzzer,LOW);
        }
  }


