from tkinter import *
import serial

janela = Tk()

#Configura a serial e a velocidade de transmissao
ser = serial.Serial("/dev/ttyUSB0", 9600)


lb = Label(janela, text = "")
lb.place(x = 100, y = 100)

resposta = ser.readline()
print(resposta)
lb["text"] = resposta

janela.geometry("400x300+200+200")
janela.mainloop()
