import processing.serial.*;
Serial port;
int value = 0;

void setup() 
{
 
  String portName = Serial.list()[0];
  port = new Serial(this, portName, 9600); //Abre uma comunicação Serial com baud rate de 9600
  
  size(600,500);
}
void draw() 
{
  rect(50, 50, 50, 50);
  fill(value);
}
void keyPressed()
{
  if (keyCode == 'w')
  {
     value = 255;
     port.write('w');  
  }
     
  if (keyCode == 's')
   {
     value = 0;
     port.write('s');  
  }
  
  if (keyCode == 'a')
  {
     value = 255;
     port.write('a');  
  }
     
  if (keyCode == 'd')
   {
     value = 0;
     port.write('d');  
  }
}