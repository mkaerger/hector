bin_PROGRAMS = hector hector_cli hector_importer hector_test

if MONGODB
DATASOURCE = MONGODB_DATA_SOURCE

hector_SOURCES = \
ServerSocket.cpp \
Socket.cpp \
token_server.cpp \
CardProcessor.cpp \
CardFeatures.cpp \
MongoDBDataSource.cpp \
CardProcessor.h \
CardFeatures.h \
ClientSocket.h  \
MongoDBDataSource.h \
ServerSocket.h \
SocketException.h \
CardFeaturesException.h \
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
CardFeatures.cpp \
PGDataSource.cpp \
CardProcessor.h \
CardFeatures.h \
ClientSocket.h  \
PGDataSource.h \
ServerSocket.h \
SocketException.h \
CardFeaturesException.h \
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
CardFeatures.cpp \
MySQLDataSource.cpp \
CardProcessor.h \
CardFeatures.h \
ClientSocket.h  \
MySQLDataSource.h \
ServerSocket.h \
SocketException.h \
CardFeaturesException.h \
Socket.h

hector_LDADD = -L/usr/lib -lmysqlcppconn -lboost_regex -lcrypto
hector_CPPFLAGS = -D$(DATASOURCE) -I$(top_srcdir)/include -I/usr/include/cppconn
hector_LDFLAGS = -pthread
endif


if ELASTICSEARCH
DATASOURCE = ELASTICSEARCH_DATA_SOURCE

hector_SOURCES = \
ServerSocket.cpp \
Socket.cpp \
token_server.cpp \
CardProcessor.cpp \
CardFeatures.cpp \
ElasticsearchDataSource.cpp \
CardProcessor.h \
CardFeatures.h \
ClientSocket.h  \
ElasticsearchDataSource.h \
ServerSocket.h \
SocketException.h \
CardFeaturesException.h \
Socket.h

hector_LDADD = -L/usr/lib -lcurl -lboost_regex -lcrypto
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

hector_importer_SOURCES = \
ServerSocket.cpp \
Socket.cpp \
token_importer.cpp \
ClientSocket.cpp  \
ClientSocket.h  \
SocketException.h \
Socket.h
hector_importer_CPPFLAGS = -I$(top_srcdir)/include
hector_importer_LDFLAGS = -pthread

hector_test_SOURCES = \
ServerSocket.cpp \
Socket.cpp \
hector_test.cpp \
ClientSocket.cpp  \
ClientSocket.h  \
SocketException.h \
Socket.h
hector_test_CPPFLAGS = -I$(top_srcdir)/include
hector_test_LDFLAGS = -pthread


