/*
        UNO-----MEGA
  CS----10------53
  MOSI---11-----51
  MISO---12-----50
  SCK----13-----52
  
  */
 #include <SPI.h>
 #include <SD.h> // Inclui a biblioteca "Sd.h" para leitura de cartão SD. 
  #define sound 6  // Pino 6 com PWM, definido como "sound" (para saída analógica).
  const int chipSelect = 10;    // Pino 10/53 como "chip select" do cartão SD.
  Sd2Card card;    // Definição para uso da biblioteca.
  File  myFile;     // Definição para uso da biblioteca.
  void setup() {
      Serial.begin(57600);    // Inicia a comunicação Serial.
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
    pinMode(sound, OUTPUT);     // Define o pino 6 como saída.
     Serial.print("Initializing SD card...");
    if (!SD.begin(10)) {
        Serial.println("falha na leitura!");
      return;
      }    
  Serial.println("initialization done.");
    
    TCCR0B = 0x01;     // Configura a frequência do PWM nos pinos 5 e 6 para 64KHz.
    
   if (!card.init(SPI_FULL_SPEED, chipSelect)) 
   
   myFile = SD.open("test.wav",FILE_READ);
  
  unsigned char data; // Declara uma variável para armazenar dados
    
    for(int count=0; count<46; count++) {     // Pula o cabeçalho do arquivo test.wav para acessar os dados(depois de 129 leituras). Este número pode variar para cada arquivo.
    data = myFile.read();     // Lê byte a byte até o final do cabeçalho.
    }
   while (data >=0) {     // Se o dado a ser lido for maior ou igual a zero (não nulo),
    
    data = myFile.read();     // Lê um byte do arquivo e armazena-o em "data".
    digitalWrite(sound, data);     // Envia os dados para o pino 6 (pino ligado ao alto falante).
    delayMicroseconds(40);     // Espera um certo intervalo (em microssegundos) para a próxima amostragem (de acordo com a do arquivo .wav).
    
    // Este tempo de espera faz com que as amostragens sejam mais próximas à frequência de 8KHz do arquivo.
    }
    
    myFile.close();     // Fecha o arquivo.
  }
  
  void loop() {
    
  }
