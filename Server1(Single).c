import socket

def handle_client(client_socket):
	request = client_socket.recv(1024).decode()
	numbers = request.split(",")
	num1 = int(numbers[0])
	num2 = int(numbers[1])
	response = "Addition: " + str(num1 + num2) + "\n"
	response += "Substraction: " + str(num1 - num2) + "\n"
	response += "Multiplication: " + str(num1 * num2) + "\n"
	try:
		response += "Division: " + str(num1/num2) + "\n"
	except ZeroDivisionError:
		response += "Division: undefinerd (division by zero)\n"
	client_socket.send(response.encode())
	client_socket.close()
	
def start_server():
	server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	server_addr = ('172.22.155.37', 5000)
	server_socket.bind(server_addr)
	server_socket.listen(1)
	print("Server is listening on port 5000...")
	while True:
		try:
			client_socket, client_address = server_socket.accept()
			handle_client(client_socket)
		
		except socket.error as e:
			client_socket.send("The server is busy. Try again later.".encode())
			client_socket.close()
		
start_server()
