import processing.serial.*;
Serial port;
int value = 0;

void setup() 
{
 
  port = new Serial(this, "/dev/ttyUSB0", 9600); //Abre uma comunicação Serial com baud rate de 9600
  
  size(600,500);
}
void draw() 
{
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