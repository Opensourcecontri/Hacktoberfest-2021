import threading
import socket

HOST = socket.gethostbyname(socket.gethostname())
PORT = 55555	

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))

server.listen()

clients = []
nicknames = []

def broadcast(message):
    for client in clients:
        client.send(message)
    

def handle(client):
    while True:
        try:
            message = client.recv(1024)
            broadcast(message)
        except:
            index = clients.index(client)
            clients.remove(client)
            client.close()
            nickname = nicknames[index]
            broadcast(f'{nickname} left the chat'.encode('ascii'))
            nicknames.remove(nickname)
            break 

def receive():
    while True:
        client, address = server.accept()
        print(f"conneted with {str(address)}")
        client.send('NICK'.encode('ascii'))
        nickname =  client.recv(1024).decode('ascii')
        nicknames.append(nickname)
        clients.append(client)

        print(f"nickname : {nickname}")
        broadcast(f"{nickname} joined".encode('ascii'))
        client.send('Connected to the server'.encode('ascii'))

        thread = threading.Thread(target=handle, args=(client,))
        thread.start()

print("server is listening ... ")
receive()