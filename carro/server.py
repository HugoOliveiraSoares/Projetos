from socket import *
import serial

HOST = ''
PORT = 30800

ser = serial.Serial("/dev/ttyUSB0", 9600)
resposta = ser.readline()
print(resposta)

server = socket(AF_INET, SOCK_STREAM)


try:
    server.bind((HOST, PORT))
    server.listen(2)

    print("Esperando conexao na porta: ", PORT)
    (obj,cliente) = server.accept()
    print("Cliente conectado:", cliente[0])

    while True:
        msg = obj.recv(1026)
        if not msg:
            print("Desconectado")
            break
        ser.write(msg)
        #print("Enviado ", msg)
        obj.send(b'Enviado ' + msg)
        resposta = ser.readline()
        print(resposta)
        obj.send(resposta)

    server.close()

except Exception as e:
    print(e)
    server.close()
