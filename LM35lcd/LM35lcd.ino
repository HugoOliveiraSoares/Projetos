const int LM35 = 0;
float temperatura = 0;
int ADClido = 0;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  analogReference(INTERNAL);
 lcd.begin(16,2);
}

void loop() {
  ADClido = analogRead(LM35);
  temperatura = ADClido * 0.1075268817;
  lcd.setCursor(0,0);
  lcd.print("Temperatura");
  lcd.setCursor(0,1);
  lcd.print("*C");
  lcd.setCursor(2,2);
  lcd.print(temperatura);
  delay(1000);
 }
