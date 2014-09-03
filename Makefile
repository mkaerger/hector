VPATH = %.cpp src

CC := g++
CFLAGS := -c
BIN := bin/
INC := -Iinclude
INC_PGSQL := -I/var/www/pgsql/include

LIB := -lboost_regex -lcrypto
LIB_PGSQL := -L/var/www/pgsql/lib -lpq

TARGET_SERVER := hector
TARGET_CLIENT := hector_cli

TOKEN_SERVER_OBJECTS = ServerSocket.o Socket.o token_server.o CardProcessor.o PGDataSource.o
TOKEN_CLIENT_OBJECTS = ClientSocket.o Socket.o token_client.o

all: hector hector_cli

$(TARGET_SERVER): $(TOKEN_SERVER_OBJECTS)
	@echo "Linking server..."
	$(CC) -o $(BIN)$(TARGET_SERVER) $(TOKEN_SERVER_OBJECTS) $(INC) $(LIB) $(LIB_PGSQL)

$(TARGET_CLIENT): $(TOKEN_CLIENT_OBJECTS)
	@echo "Linking client..."
	$(CC) -o $(BIN)$(TARGET_CLIENT) $(TOKEN_CLIENT_OBJECTS) $(INC) 

clean:
	@echo "Cleaning..."; 
	rm -f *.o $(BIN)*

token_server.o ServerSocket.o Socket.o: token_server.cpp ServerSocket.cpp Socket.cpp
	$(CC) $(CFLAGS) $(INC) $^

token_client.o ClientSocket.o: token_client.cpp ClientSocket.cpp
	$(CC) $(CFLAGS) $(INC) $^

CardProcessor.o PGDataSource.o: CardProcessor.cpp PGDataSource.cpp
	$(CC) $(CFLAGS) $(INC) $(INC_PGSQL) $^



