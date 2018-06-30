
#include <Wire.h>

#define expansor1 0x38

void setup() {
 Wire.begin();
 Wire.beginTransmission(expansor1);
  Wire.write(B11111111);
  Wire.endTransmission();
}

void loop() {
  Wire.beginTransmission(expansor1);
  Wire.write(B0111111);
  Wire.endTransmission();
  delay(1000);
  Wire.beginTransmission(expansor1);
  Wire.write(B10111111);
  Wire.endTransmission();
 delay(1000);
  Wire.beginTransmission(expansor1);
  Wire.write(B11011111);
  Wire.endTransmission();
 delay(1000);
  Wire.beginTransmission(expansor1);
  Wire.write(B11101111);
  Wire.endTransmission();
 delay(1000);
  Wire.beginTransmission(expansor1);
  Wire.write(B11110111);
  Wire.endTransmission();
 delay(1000);
 Wire.beginTransmission(expansor1);
  Wire.write(B11111011);
  Wire.endTransmission();
 delay(1000);
 Wire.beginTransmission(expansor1);
  Wire.write(B11111101);
  Wire.endTransmission();
 delay(1000);
 Wire.beginTransmission(expansor1);
  Wire.write(B11111110);
  Wire.endTransmission();
 delay(1000);
}
