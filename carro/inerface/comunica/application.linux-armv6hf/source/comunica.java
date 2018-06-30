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
 
  port = new Serial(this, "/dev/ttyUSB0", 9600); //Abre uma comunica\u00e7\u00e3o Serial com baud rate de 9600
  
  
}
public void draw() 
{
  rect(50, 50, 50, 50);
  fill(value);
}
public void keyPressed()
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
