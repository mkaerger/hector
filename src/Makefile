INC := -I../include
INC_PGSQL := -I/var/www/pgsql/include
CC := g++
CFLAGS := -c
LIB := -L/var/www/pgsql/lib -lpq -lboost_regex -lcrypto

TARGET_SERVER := hector_server
TARGET_CLIENT := hector_client

TOKEN_SERVER_OBJECTS = ServerSocket.o Socket.o token_server.o CardProcessor.o PGDataSource.o
TOKEN_CLIENT_OBJECTS = ClientSocket.o Socket.o token_client.o

all: hector_server hector_client

$(TARGET_SERVER): $(TOKEN_SERVER_OBJECTS)
	@echo "Linking..."
	$(CC) -o $(TARGET_SERVER) $(TOKEN_SERVER_OBJECTS) $(INC) $(LIB)


$(TARGET_CLIENT): $(TOKEN_CLIENT_OBJECTS)
	@echo "Linking..."
	$(CC) -o $(TARGET_CLIENT) $(TOKEN_CLIENT_OBJECTS) $(INC) 


token_server.o: token_server.cpp
	$(CC) $(CFLAGS) $(INC) token_server.cpp
ServerSocket.o: ServerSocket.cpp
	$(CC) $(CFLAGS) $(INC) ServerSocket.cpp
Socket.o: Socket.cpp
	$(CC) $(CFLAGS) $(INC) Socket.cpp


token_client.o: token_client.cpp
	$(CC) $(CFLAGS) $(INC) token_client.cpp
ClientSocket.o: ClientSocket.cpp
	$(CC) $(CFLAGS) $(INC) ClientSocket.cpp


CardProcessor.o: CardProcessor.cpp
	$(CC) $(CFLAGS) $(INC) CardProcessor.cpp
PGDataSource.o: PGDataSource.cpp
	$(CC) $(CFLAGS) $(INC) $(INC_PGSQL) PGDataSource.cpp

clean:
	@echo "Cleaning..."; 
	rm -f *.o hector hector_cli
