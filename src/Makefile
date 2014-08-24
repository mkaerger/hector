token_server_objects = ServerSocket.o Socket.o token_server.o CardProcessor.o
token_client_objects = ClientSocket.o Socket.o token_client.o


all: token_server token_client


token_server: $(token_server_objects)
	g++ -g -o ../bin/hector $(token_server_objects) -L/var/www/pgsql/lib -lpq -lboost_regex -lcrypto 

token_client: $(token_client_objects)
	g++ -o ../bin/hector_cli $(token_client_objects) 

token_server.o: token_server.cpp
	g++ -c -I/var/www/pgsql/include token_server.cpp

ServerSocket.o: ServerSocket.cpp
	g++ -c -I/var/www/pgsql/include ServerSocket.cpp

Socket.o: Socket.cpp
	g++ -c Socket.cpp

token_client.o: token_client.cpp
	g++ -c  token_client.cpp

ClientSocket.o: ClientSocket.cpp
	g++ -c -I/var/www/pgsql/include ClientSocket.cpp

CardProcessor.o: CardProcessor.cpp
	g++ -c  CardProcessor.cpp

clean:
	rm -f *.o ../bin/hector ../bin/hector_cli
