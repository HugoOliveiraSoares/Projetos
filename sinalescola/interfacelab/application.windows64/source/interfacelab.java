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

public class interfacelab extends PApplet {

 //Importa a biblioteca para abrir uma comunica\u00e7\u00e3o Serial
Serial myPort; //Inst\u00e2ncia a biblioteca para a comunia\u00e7\u00e3o Serial

//Cria uma inst\u00e2ncia para cada imagem da interface
PImage fundo; //Background
PImage ponteiro; //Ponteiro
       
PImage ledOff; //LED desligado
PImage ledVerdeOn; //LED Verde (ligado)
PImage ledVermelhoOn; //LED Vermelho (ligado)
       
PImage botaoOn; //Bot\u00e3o em estado pressionado (Ligado)
PImage botaoOff; //Bot\u00e3o em estado pressionado (desligado)
PImage botaoNot; //Bot\u00e3o Desabilitado
//=======================

int valor_recebido; //Cria uma vari\u00e1vel para armazenas o valor recebido pela serial
int valor_pot; //Cria uma vari\u00e1vel para armazenar o valor do potenciometro
int valor_botao; //Cria uma vari\u00e1vel para armazenar o valor do bot\u00e3o

boolean habilita_botao = true; //Cria uma vari\u00e1vel para habilitar o bot\u00e3o da interface
boolean estadoLEDvermelho = false; //Cria uma vari\u00e1vel para armazenar o estado do LED Vermelho
boolean estadoLEDverde = false; //Cria uma vari\u00e1vel para armazenar o estado do LED Verde

int ajuste_y=14; //Vari\u00e1vel para ajusta o eixo x na tela (Centralizar)
                 //Se n\u00e3o precisar de ajuste deixe com valor 0

public void setup()
{
    
  String portName = Serial.list()[0]; //Lista as portas COM (Serial) encontradas
                                      //Pega a primeira porta (Posi\u00e7\u00e3o 0 em "Serial.list()[0]" e
                                      //armazena na vari\u00e1vel portName
                                      //Se voc\u00ea tiver mais de uma porta COM, identifique qual a do Garagino
  
  myPort = new Serial(this, portName, 9600); //Abre uma comunica\u00e7\u00e3o Serial com baud rate de 9600
  
   //Define o tamanho da tela

  //Carrega as imagens e armazena elas em suas respectivas inst\u00e2ncias
  fundo = loadImage("fundo.jpg");
  ponteiro = loadImage("ponteiro.png");
  ledVerdeOn = loadImage("ledVerdeOn.png");
  ledVermelhoOn = loadImage("ledVermelhoOn.png");
  ledOff = loadImage("ledOff.png");
  botaoOn = loadImage("botaoOn.png");
  botaoOff = loadImage("botaoOff.png");
  botaoNot = loadImage("botaoNot.png");
  //================================================================
  
}

public void draw()
{
  
  if (myPort.available() > 0) //Se algo for recebido pela serial
  {
    valor_recebido = myPort.read(); //Armazena o que foi lido dentro da vari\u00e1vel valor recebido
    
    if (valor_recebido<181) valor_pot = valor_recebido; //Se o valor recebido for menor que 181,
                                                        //armazena esse valor dentro da vari\u00e1vel valor_pot
                                                        
    else if (valor_recebido == 254 || valor_recebido == 255) valor_botao = valor_recebido;
    //Sen\u00e3o, se o valor recebido for 254 eu 255 armazena esse valor dentro da vari\u00e1vel valor_botao
  }

  background(fundo); //Atualiza a imagem de fundo (backgroud) da interface

  translate(width/2, height/2+ajuste_y); //Posiciona o ponto 0 da interface no centro da tela
                                         //Com ajuste de 14 pixels em y (height)


  //***************************************
  //***************************************
  //Descomente "borda_mouse();" para visualizar as bordas das imagens clic\u00e1veis
  //E a visualiza\u00e7\u00e3o do centro da tela
            //borda_mouse();
  //***************************************
  //***************************************
  
  
  
  //********************************************************
  if (habilita_botao == true) //Se o bot\u00e3o estiver habilitado
  {
    if (valor_botao == 255) //Se o valor do bot\u00e3o for igual a 255
    {
      image(botaoOff, -(botaoOff.width/2), 125); //Coloca a imagem do bot\u00e3o desligado (Off)
                                                 //Centralizado no eixo x (width/2)
                                                 //e na posi\u00e7\u00e3o 125 em y (height)
                                                 
      image(ledOff, -(ledOff.width*3), 50); //Coloca a imagem de LED desligado na posi\u00e7\u00e3o do LED Verde
      image(ledVermelhoOn, ledVermelhoOn.width*2, 50); //Coloca a imagem do LED Vermelho ligada na posi\u00e7\u00e3o x,y/width,height (65, 50)
    }
    else if (valor_botao == 254) //Se o valor do bot\u00e3o for igual a 254
    {
      image(botaoOn, -(botaoOn.width/2), 125); //Coloca a imagem do bot\u00e3o ligado (On)
                                               //Centralizado no eixo x (width/2)
                                               //e na posi\u00e7\u00e3o 125 em y (height)
      image(ledVerdeOn, -65*3, 50); //Coloca a imagem do LED Verde ligado na posi\u00e7\u00e3o x,y/width,height (-130, 50)
      image(ledOff, ledOff.width*2, 50); //Coloca a imagem de LED desligado na posi\u00e7\u00e3o do LED Vermelho
    }
  }
  //OBS: "botaoOff.width" equivale ao tamanho da imagem em width,
  //nesse caso a imagem possui 65x100(width x height),
  //logo, botaoOff.width = 65
  //=======================================================
  
  
  
  //********************************************************
  else //Se n\u00e3o se o bot\u00e3o n\u00e3o estiver habilitado
  {
    image(botaoNot, -(152/2), 125); //Coloca a imagem do bot\u00e3o desabilitado (Bloqueado)
                                    //Centralizado no eixo x (width/2)
                                    //e na posi\u00e7\u00e3o 125 em y (height)
    if (estadoLEDverde==false) image(ledOff, -65*3, 50); //Se o estado do LED verde for false (desligado)
                                                         //Atualiza a imagem do LED Verde para o LED apagado
    else image(ledVerdeOn, -65*3, 50); //Sen\u00e3o, se o estado do LED verde for true (aceso)
                                       //Atualiza a imagem do LED apagado para o LED Verde
                                       
    if (estadoLEDvermelho==false) image(ledOff, 65*2, 50); //Se o estado do LED vermelho for false (desligado)
                                                         //Atualiza a imagem do LED vermelho para o LED apagado
    else image(ledVermelhoOn, 65*2, 50); //Sen\u00e3o, se o estado do LED vermelho for true (aceso)
                                       //Atualiza a imagem do LED apagado para o LED Vermelho
  }
  //=======================================================


  
  //float c = radians(valor_pot-90); //Pega o valor lido referendo ao potenci\u00f4metro
                                   
  rotate(radians(valor_pot-90)); //Pega o valor lido referendo ao potenci\u00f4metro,
                                 //Subtrai 90 desse valor, converte para radianos e
                                 //Executa a fun\u00e7\u00e3o de rota\u00e7\u00e3o da tela
                                 
  image(ponteiro, -(ponteiro.width/2), -ponteiro.height+(7)); //Posiciona o centro do furo do ponteiro
                                                              //Na posi\u00e7\u00e3o central do gr\u00e1fico na imagem de fundo
  
}


public void mouseClicked()
{
  
  //Se o mouse for clicado em cima da imagem do bot\u00e3o
  if (mouseX>= ((width/2)-76) && mouseX<= (width/2+76) && mouseY>=(height/2+125+ajuste_y) && mouseY<=(height/2+277+ajuste_y) )
  {
    habilita_botao = !habilita_botao; //Inverte o estado do bot\u00e3o
    myPort.write(253); //Envia o valor 253 para o Garagino
    estadoLEDvermelho = false; //Altera o estado do LED vermelho na tela para false
    estadoLEDverde = false; //Altera o estado do LED verde na tela para false
  }
  //================================================
  
 //Se o mouse for clicado em cima da imagem do LED esquerda
  else if (mouseX>= ((width/2)-(65*3)) && mouseX<= (width/2) && mouseY>=(height/2+50+ajuste_y) && mouseY<=(height/2+150+ajuste_y) )
  {
    if (habilita_botao == false) //Se o bot\u00e3o estiver desabilitado
    {
      estadoLEDverde = !estadoLEDverde; //Inverte a vari\u00e1vel de estado do LED verde
      myPort.write(254); //Envia o valor 254 para o Garagino
    }
  }
//==========================================================
  
  //Se o mouse for clicado em cima da imagem do LED direita
  else if (mouseX>= (width/2+65*2) && mouseX<= (width/2+195) && mouseY>=(height/2+50+ajuste_y) && mouseY<=(height/2+150+ajuste_y) )
  {
    if (habilita_botao == false) //Se o bot\u00e3o estiver desabilitado
    {
      estadoLEDvermelho = !estadoLEDvermelho; //Inverte a vari\u00e1vel de estado do LED vermelho
      myPort.write(255);  //Envia o valor 255 para o Garagino
    }
  }
  //=========================================================
  
}

public void borda_mouse()
{

  textSize(32); //Define o tamanho da letra
  fill(204, 102, 0); //Define a cor Laranja (R, G, B)
  text("MouseX = " + (mouseX-width/2), -400, 250); //Escreve MouseX + o valor da posi\u00e7\u00e3o do mouse na tela
  text("MouseY = " + (mouseY-height/2), -400, 280); //Escreve MouseY + o valor da posi\u00e7\u00e3o do mouse na tela
  fill(255, 255, 255); //Define a cor Branca (R, G, B)
  
  //Cria Cruz central
  line(-width/2, 0, width/2, 0);
  line(0, -height/2, 0, height/2);
  //==
   
   //Cria borda do Botao
   rect(-(botaoOn.width/2), 125, 152, 152);
   //==
   
   //Cria borda do LED da esquerda
   rect(-(ledOff.width*3), 50, 65, 100);
   //==
   
   //Cria borda do LED da direita
   rect(ledOff.width*2, 50, 65, 100);
   //==
 
}
  public void settings() {  size(800, 600); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "--present", "--window-color=#666666", "--stop-color=#cccccc", "interfacelab" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
