#ifndef CARDFEATURESEXCEPTION_H
#define CARDFEATURESEXCEPTION_H

class CardFeaturesException : public std::exception
{
	public:
  	  CardFeaturesException(const char* s): error_message(s) {};
  	  std::string description() { return error_message; }
	  const char* what() const throw() { return error_message; }

 	private:
	  const char* error_message;
};
#endif
