import threading
import socket

HOST = '127.0.0.1' #Change this to your server IP
PORT = 55555 #Change thi to you Server PORT

nickname = input("Enter a nickname : ")

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((HOST, PORT))


def receive():
    while True:
        try:
            message = client.recv(1024).decode('ascii')
            if message == "NICK":
                client.send(nickname.encode('ascii'))
            else:
                print(message)
        except:
            print("error occurred")
            client.close()
            break


def write():
    while True:
        message = f'{nickname} : {input("")}'
        client.send(message.encode('ascii'))


receiveThread = threading.Thread(target=receive)
receiveThread.start()

writeThread = threading.Thread(target=write)
writeThread.start()
