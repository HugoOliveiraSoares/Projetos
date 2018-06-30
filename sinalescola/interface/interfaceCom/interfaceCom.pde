import processing.serial.*;
Serial port;
int value = 0;

void setup() 
{
  //println(Serial.list());
  port = new Serial(this, "/dev/ttyUSB0", 9600);
  size(600,500);
}
void draw() 
{
  println("L=aciona a musica");
  println("D=desliga a musica");
  rect(50, 50, 50, 50);
  fill(value);
}
void keyPressed()
{
  if (keyCode == 'L')
  {
     value = 255;
     port.write('L');  
  }
     
  if (keyCode == 'D')
   {
     value = 0;
     port.write('D');  
  }
}