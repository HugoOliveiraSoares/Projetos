import processing.serial.*;
int value = 0;
Serial port;
void setup() {
println(Serial.list());
port = new Serial(this, Serial.list()[0], 9600);
}
void draw() {
rect(25, 25, 50, 50);
fill(value);
}
void mouseClicked() {
if (value == 0) {
value = 255;
port.write('L');
}
else {
value = 0;
port.write('D');
}
}