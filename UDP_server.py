import socket

UDP_IP_ADDRESS = "127.0.0.1"
UDP_PORT_NO = 8080

serverSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
serverSock.bind((UDP_IP_ADDRESS, UDP_PORT_NO))

print("UDP server up and listening")

while True:
    data, addr = serverSock.recvfrom(1024)
    print("Received message: ", data.decode())
