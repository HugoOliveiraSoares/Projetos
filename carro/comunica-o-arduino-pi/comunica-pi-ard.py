#import RPi.GPIO as GPIO
import time
import serial

#Configura a serial e a velocidade de transmissao
ser = serial.Serial("/dev/ttyUSB0", 9600)

buf = 1

print(ser.readline())
while (buf != '0' ):
    print("w: frente | s: tras | a: esquerdo | d: direito | f: OFF | 0: sai do programa")
    buf = str(input("Digite o comando: "))

    ser.write(buf)
    resposta = ser.readline()
    print(resposta)
    
    time.sleep(0.5)
