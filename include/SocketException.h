#ifndef SOCKETEXCEPTION_H
#define SOCKETEXCEPTION_H

class SocketException : public std::exception
{
	public:
  	  SocketException(const char* s): error_message(s) {};
  	  std::string description() { return error_message; }
	  const char* what() const throw() { return error_message; }

 	private:
	  const char* error_message;
};
#endif
