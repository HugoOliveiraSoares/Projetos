 #include<SdFat.h>// Inclui a biblioteca "Sdfat.h" para leitura de cartão SD. Se você não tiver a biblioteca, faça o download e extraia na pasta "libraries" do Arduino
  #define sound 6    // Pino 6 com PWM, definido como "sound" (para saída analógica).
  const int chipSelect = 10;    // Pino 10 como "chip select" do cartão SD.
  
  SdFat sd;    // Definição para uso da biblioteca.
  SdFile myFile;     // Definição para uso da biblioteca.
  
  void setup() {
  
  Serial.begin(9600);    // Inicia a comunicação Serial.
  pinMode(sound, OUTPUT);     // Define o pino 6 como saída.
  
  TCCR0B = 0x01;     // Configura a frequência do PWM nos pinos 5 e 6 para 64KHz.
  
  if (!sd.init(SPI_FULL_SPEED, chipSelect)) sd.initErrorHalt();     // Inicia SdFat com máxima velocidade ou imprime mensagem de erro no "Serial Monitor".
  
  if (!myFile.open("test.wav", O_READ)) {     // Abre o arquivo chamado "test.wav" (o nome pode ser mudado), se não, imprime mensagem de erro no "Serial Monitor".
  sd.errorHalt("opening test.wav for read failed");
  }
  
  unsigned char data;     // Declara uma variável para armazenar os dados do arquivo.
  
  for(int count=0; count<46; count++) {     // Pula o cabeçalho do arquivo test.wav para acessar os dados(depois de 129 leituras). Este número pode variar para cada arquivo.
  data = myFile.read();     // Lê byte a byte até o final do cabeçalho.
  }
  
  while (data >=0) {     // Se o dado a ser lido for maior ou igual a zero (não nulo),
  
  data = myFile.read();     // Lê um byte do arquivo e armazena-o em "data".
  analogWrite(sound, data);     // Envia os dados para o pino 6 (pino ligado ao alto falante).
  delayMicroseconds(40);     // Espera um certo intervalo (em microssegundos) para a próxima amostragem (de acordo com a do arquivo .wav).
  
  // Este tempo de espera faz com que as amostragens sejam mais próximas à frequência de 8KHz do arquivo.
  }
  
  myFile.close();     // Fecha o arquivo.
  }
  
  void loop() {
  // Nada acontece aqui.
  }
