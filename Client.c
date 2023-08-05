import socket

def send_request():
	client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	server_addr = ('172.22.155.37', 5000)
	try:
		client_socket.connect(server_addr)
		print("Connected to server on port 5000")
		num1 = input("Enter the first number: ")
		num2 = input("Enter the second number: ")
		request = num1+ "," +num2
		client_socket.send(request.encode())
		response = client_socket.recv(1024).decode()
		print("Server response:\n" + response)
		client_socket.close()
	
	except socket.error as e:
		print("Could not connect to server: " + str(e))
	
send_request()
