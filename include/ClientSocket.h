#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include "Socket.h"

//!  The ClientSocket class. 
/*!
  Client class to talk to socket client.
*/
class ClientSocket : private Socket
{
  public:
  ClientSocket(std::string host, int port);
  virtual ~ClientSocket(){};

  const ClientSocket& operator << (const std::string&) const;
  const ClientSocket& operator >> (std::string&) const;
};
#endif
