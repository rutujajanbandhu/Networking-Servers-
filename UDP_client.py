import socket

UDP_IP_ADDRESS = "127.0.0.1"
UDP_PORT_NO = 8080
MESSAGE = "Hello, server!"

clientSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
clientSock.sendto(MESSAGE.encode(), (UDP_IP_ADDRESS, UDP_PORT_NO))

print("Message sent")
