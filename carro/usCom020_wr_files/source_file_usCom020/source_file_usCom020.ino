/*
   Usina Info e WR Kits
   
   Receptor de Rádio com Arduino


   Autor: Eng. Wagner Rambo  Data: Janeiro de 2017
   
   www.wrkits.com.br | facebook.com/wrkits | youtube.com/user/canalwrkits
   
*/

// =============================================================================================================
// --- Bibliotecas ---
#include <LiquidCrystal.h>      //Biblioteca para o display LCD
#include <Wire.h>               //Biblioteca Wire para protocolo I2C
#include <TEA5767Radio.h>       //Biblioteca para o módulo TEA5767
 

// =============================================================================================================
// --- Declaração de Objetos ---
TEA5767Radio radio = TEA5767Radio();  //módulo FM
 
 
// =============================================================================================================
// --- Protótipo das Funções ---
void radioFM();                             //função para cálculo das frequencias


// =============================================================================================================
// --- Variáveis Globais --- 
double         frequencia = 87.5,              //armazena frequencia
               frequencia_ant = 87.5;          //armazena frequencia da antena
         

// =============================================================================================================
// --- Hardware do LCD ---
LiquidCrystal disp(8,  //RS no digital 8
                   7,  //EN no digital 7
                   5,  //D4 no digital 5
                   4,  //D5 no digital 4
                   3,  //D6 no digital 3
                   2); //D7 no digital 2


// =============================================================================================================
// --- Configurações Iniciais ---
void setup()
{

  Serial.begin(9600);            //monitor serial 9600 baud rate
  Wire.begin();                  //inicializa I2C
   

  disp.begin(16,2);                    //Inicializa LCD 16 x 2
  disp.clear();                        //Limpa LCD

    

  disp.setCursor(0,0);                 //posiciona cursor na coluna 1 linha 1
  disp.print("Radio FM Arduino");      //imprime
  
   
} //end setup


// =============================================================================================================
// --- Loop Infinito ---
void loop()
{
   
   radioFM(); //chama função do rádio
    
  
} //end loop



// =============================================================================================================
// --- Desenvolvimento das Funções ---

// =============================================================================================================
void radioFM()                              //função para cálculo das frequencias
{

  //Lê entrada analógica zero e armazena em dial
  int dial = analogRead(A0);

  //Calculo da frequencia
  frequencia = ((double)dial * (108.0 - 87.5)) / 1024.0 + 87.5;
  frequencia = ((int)(frequencia * 10)) / 10.0;

  //Se frequencia mudar, atualiza display 
  if (frequencia_ant != frequencia)
  {
    disp.setCursor(0, 1);
    disp.print("Freq: ");
    disp.setCursor(6, 1);
    disp.print("     MHz");
    disp.setCursor(6, 1);
    disp.print(frequencia, 1);
    Serial.print("Frequencia: ");
    Serial.println(frequencia);
    radio.setFrequency(frequencia);
    frequencia_ant = frequencia;
  
  } //end if

 
} //end radioFM






