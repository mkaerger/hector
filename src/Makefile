CC := g++
CFLAGS := -c
LIB := -L/var/www/pgsql/lib -lpq -lboost_regex -lcrypto
INC := -I../include
INC_PGSQL := -I/var/www/pgsql/include

TARGET_SERVER := hector_server
TARGET_CLIENT := hector_client

SERVER_OBJECTS = ServerSocket.o Socket.o token_server.o CardProcessor.o PGDataSource.o
CLIENT_OBJECTS = ClientSocket.o Socket.o token_client.o

all: hector_server hector_client

token_server.o: token_server.cpp
	$(CC) $(CFLAGS) $(INC) token_server.cpp
ServerSocket.o: ServerSocket.cpp
	$(CC) $(CFLAGS) $(INC) ServerSocket.cpp
token_client.o: token_client.cpp
	$(CC) $(CFLAGS) $(INC) token_client.cpp
CardProcessor.o: CardProcessor.cpp
	$(CC) $(CFLAGS) $(INC) CardProcessor.cpp
PGDataSource.o: PGDataSource.cpp
	$(CC) $(CFLAGS) $(INC) $(INC_PGSQL) PGDataSource.cpp
Socket.o: Socket.cpp
	$(CC) $(CFLAGS) $(INC) Socket.cpp
ClientSocket.o: ClientSocket.cpp
	$(CC) $(CFLAGS) $(INC) ClientSocket.cpp


$(TARGET_SERVER): $(SERVER_OBJECTS)
	@echo "Linking..."
	$(CC) -o $(TARGET_SERVER) $^ $(INC) $(LIB)

$(TARGET_CLIENT): $(CLIENT_OBJECTS)
	@echo "Linking..."
	$(CC) -o $(TARGET_CLIENT) $^ $(INC) 

clean:
	@echo "Cleaning..."; 
	rm -f *.o hector_*
