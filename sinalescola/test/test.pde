PImage ledOff; //LED desligado
PImage ledVermelhoOn; //LED Vermelho (ligado)
PImage botaoOn; //Botão em estado pressionado (Ligado)
PImage botaoOff; //Botão em estado pressionado (desligado)
boolean habilita_botao = true; //Cria uma variável para habilitar o botão da interface
boolean estadoLEDvermelho = false; //Cria uma variável para armazenar o estado do LED Vermelho
int ajuste_y=14; //Variável para ajusta o eixo x na tela (Centralizar)
                 //Se não precisar de ajuste deixe com valor 0
                 
void setup(){
size(800,600);

ledVermelhoOn = loadImage("ledVermelhoOn.png");
  ledOff = loadImage("ledOff.png");
  botaoOn = loadImage("botaoOn.png");
  botaoOff = loadImage("botaoOff.png");
}

void draw(){ 
    rect(25, 25, 50, 50);
if (habilita_botao == true) //Se o botão estiver habilitado
  {
 image(botaoOff, -(botaoOff.width/2), 125); //Coloca a imagem do botão desligado (Off)
                                                 //Centralizado no eixo x (width/2)
                                                 //e na posição 125 em y (height)
                                                 
      image(ledOff, -(ledOff.width*3), 50); //Coloca a imagem de LED desligado na posição do LED Verde
      image(ledVermelhoOn, ledVermelhoOn.width*2, 50); //Coloca a imagem do LED Vermelho ligada na posição x,y/width,height (65, 50)
    }
    
    else {
      image(botaoOn, -(botaoOn.width/2), 125); //Coloca a imagem do botão ligado (On)
                                               //Centralizado no eixo x (width/2)
                                               //e na posição 125 em y (height)
      image(ledOff, ledOff.width*2, 50); //Coloca a imagem de LED desligado na posição do LED Vermelho
    }
translate(width/2, height/2+ajuste_y); //Posiciona o ponto 0 da interface no centro da tela
                                         //Com ajuste de 14 pixels em y (height) 


} 

void mouseClicked(){
  //Se o mouse for clicado em cima da imagem do botão
  if (mouseX>= ((width/2)-76) && mouseX<= (width/2+76) && mouseY>=(height/2+125+ajuste_y) && mouseY<=(height/2+277+ajuste_y) )
  {
    habilita_botao = !habilita_botao; //Inverte o estado do botão
    estadoLEDvermelho = false; //Altera o estado do LED vermelho na tela para false
  }
  
}