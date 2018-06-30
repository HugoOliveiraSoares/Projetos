from functools import partial
from tkinter import *
from socket import *

#===================================================
def bt_click(botao):

    if (botao["text"] == "Frente"):
        sockobj.send(b'w')
    elif (botao["text"] == "Tras"):
        sockobj.send(b's')
    elif (botao["text"] == "Esquerda"):
        sockobj.send(b'a')
    elif (botao["text"] == "Direita"):
        sockobj.send(b'd')
    elif (botao["text"] == "OFF"):
        sockobj.send(b'f')

    #resposta do server
    data = sockobj.recv(1024)
    #print("Resposta: ", data)
    lb["text"] = data
    data = sockobj.recv(1024)
    #print("Resposta: ", data)
    lb["text"] = data
#===================================================

#serverHOST = '192.168.0.21'
serverHOST = '192.168.0.21'
serverPORT = 30800
#msg = [b'w']

sockobj = socket(AF_INET, SOCK_STREAM)
sockobj.connect((serverHOST, serverPORT))

janela = Tk()

#===================================================
lb = Label(janela, text="", font=("Verdana", "10"))
lb.place(x=100, y= 200)

bt1 = Button(janela, width=10, text="Frente")
bt1["command"] = partial(bt_click, bt1)
bt1.place(x=100,y=100)

bt2 = Button(janela, width=10, text="Tras")
bt2["command"] = partial(bt_click, bt2)
bt2.place(x=100,y=150)

bt3 = Button(janela, width=10, text="Esquerda")
bt3["command"] = partial(bt_click, bt3)
bt3.place(x=0,y=126)

bt4 = Button(janela, width=10, text="Direita")
bt4["command"] = partial(bt_click, bt4)
bt4.place(x=190,y=126)

bt5 = Button(janela, width=10, text="OFF")
bt5["command"] = partial(bt_click, bt5)
bt5.place(x=0,y=50)
#====================================================

janela.geometry("300x300+200+200")
janela.mainloop()
sockobj.close()
