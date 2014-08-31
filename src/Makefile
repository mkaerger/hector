CC := g++
CFLAGS := -c

INC := -I../include
INC_PGSQL := -I/var/www/pgsql/include

LIB := -lboost_regex -lcrypto
LIB_PGSQL := -L/var/www/pgsql/lib -lpq

TARGET_SERVER := hector_server
TARGET_CLIENT := hector_client

TOKEN_SERVER_OBJECTS = ServerSocket.o Socket.o token_server.o CardProcessor.o PGDataSource.o
TOKEN_CLIENT_OBJECTS = ClientSocket.o Socket.o token_client.o

all: hector_server hector_client

token_server.o ServerSocket.o Socket.o: token_server.cpp ServerSocket.cpp Socket.cpp
	$(CC) $(CFLAGS) $(INC) $^

token_client.o ClientSocket.o: token_client.cpp ClientSocket.cpp
	$(CC) $(CFLAGS) $(INC) $^

CardProcessor.o PGDataSource.o: CardProcessor.cpp PGDataSource.cpp
	$(CC) $(CFLAGS) $(INC) $(INC_PGSQL) $^


$(TARGET_SERVER): $(TOKEN_SERVER_OBJECTS)
	@echo "Linking server..."
	$(CC) -o $(TARGET_SERVER) $(TOKEN_SERVER_OBJECTS) $(INC) $(LIB) $(LIB_PGSQL)

$(TARGET_CLIENT): $(TOKEN_CLIENT_OBJECTS)
	@echo "Linking client..."
	$(CC) -o $(TARGET_CLIENT) $(TOKEN_CLIENT_OBJECTS) $(INC) 

clean:
	@echo "Cleaning..."; 
	rm -f *.o hector_*
