import processing.serial.*; //<>//
Serial port;
int value = 0;

void setup() 
{
//String portName = Serial.list()[0];


//port = new Serial(this, "/dev/ttyUSB0", 9600); //Abre uma comunicação Serial com baud rate de 9600
  
  size(600,500);
  textSize(32);
  fill(0, 102, 160);
  text("ola",50,50);
  
}

void draw() 
{
  rect(50, 50, 50, 50);
  fill(value);
  if (keyPressed) {
    if (key == 'w' || keyCode == UP) {
      //port.write('w');
      value = 70;
    }else if(key == 's' || keyCode == DOWN){
      //port.write('s');
      value = 130;
    }else if(key == 'a' || keyCode == LEFT){
      //port.write('a');
      value = 185;
    }else if(key == 'd' || keyCode == RIGHT){
      //port.write('d');
      value = 255;
    }
  }
}