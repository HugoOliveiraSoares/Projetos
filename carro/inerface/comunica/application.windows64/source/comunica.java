import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class comunica extends PApplet {


Serial port;
int value = 0;

public void setup() 
{
 
  String portName = Serial.list()[0];
  port = new Serial(this, portName, 9600); //Abre uma comunica\u00e7\u00e3o Serial com baud rate de 9600
  
  
}
public void draw() 
{
  rect(50, 50, 50, 50);
  fill(value);
}
public void keyPressed()
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
  public void settings() {  size(600,500); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "comunica" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
