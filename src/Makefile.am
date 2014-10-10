bin_PROGRAMS = hector hector_cli

if MONGODB
DATASOURCE = MONGODB_DATA_SOURCE

hector_SOURCES = \
ServerSocket.cpp \
Socket.cpp \
token_server.cpp \
CardProcessor.cpp \
IbanList.cpp \
MongoDBDataSource.cpp \
CardProcessor.h \
IbanList.h \
ClientSocket.h  \
MongoDBDataSource.h \
ServerSocket.h \
SocketException.h \
Socket.h

hector_LDADD = -lmongoclient -lboost_thread -lboost_filesystem -lboost_regex -lboost_program_options -lboost_system -lssl -lcrypto
hector_CPPFLAGS = -D$(DATASOURCE) -I$(top_srcdir)/include
hector_LDFLAGS = -pthread
endif


if POSTGRESQL
DATASOURCE = PG_DATA_SOURCE

hector_SOURCES = \
ServerSocket.cpp \
Socket.cpp \
token_server.cpp \
CardProcessor.cpp \
IbanList.cpp \
PGDataSource.cpp \
CardProcessor.h \
IbanList.h \
ClientSocket.h  \
PGDataSource.h \
ServerSocket.h \
SocketException.h \
Socket.h

hector_LDADD = -L/var/www/pgsql/lib -lpq -lboost_regex -lcrypto
hector_CPPFLAGS = -D$(DATASOURCE) -I$(top_srcdir)/include -I/var/www/pgsql/include
hector_LDFLAGS = -pthread
endif


if MYSQL
DATASOURCE = MYSQL_DATA_SOURCE

hector_SOURCES = \
ServerSocket.cpp \
Socket.cpp \
token_server.cpp \
CardProcessor.cpp \
IbanList.cpp \
MySQLDataSource.cpp \
CardProcessor.h \
IbanList.h \
ClientSocket.h  \
PGDataSource.h \
ServerSocket.h \
SocketException.h \
Socket.h

hector_LDADD = -L/usr/lib -lmysqlcppconn -lboost_regex -lcrypto
hector_CPPFLAGS = -D$(DATASOURCE) -I$(top_srcdir)/include -I/usr/include/cppconn
hector_LDFLAGS = -pthread
endif


hector_cli_SOURCES = \
ServerSocket.cpp \
Socket.cpp \
token_client.cpp \
ClientSocket.cpp  \
ClientSocket.h  \
SocketException.h \
Socket.h
hector_cli_CPPFLAGS = -I$(top_srcdir)/include
hector_cli_LDFLAGS = -pthread

