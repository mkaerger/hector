#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>


using namespace std;
using namespace boost::algorithm;

int main(int argc, char *argv[] )
{
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " [1111-2222-3333-4444]" << std::endl;
		return 0;
	}

	std::string pan_in = argv[1];

	try
    {
		ClientSocket client_socket("localhost", 30000 );

		std::string service;
		std::string token;
		std::string tokens;
		std::string count_tokens;
		std::string masked_pan;
		std::string card_type;
		std::string issuer;
		std::string pan;
		std::string reply;

   		std::cout << "\t[TEST....:]\t" << "Run set_token_by_pan" << std::endl;
		service = "set_token_by_pan|" + pan_in;
		client_socket << service; 
		client_socket >> reply;
   		std::cout << "\t[RESULT for set_token_by_pan:]\t" << reply;
		std::cout << std::endl;
		std::cout << std::endl;


 		std::cout << "\t[TEST....:]\t" << "Run get_token_by_pan" << std::endl;
		service = "get_token_by_pan|" + pan_in;
		client_socket << service; 
		client_socket >> token;
   		std::cout << "\t[RESULT for get_token_by_pan:]\t" << reply;
		std::cout << std::endl;
		std::cout << std::endl;


 		std::cout << "\t[TEST....:]\t" << "Run get_pan_by_token" << std::endl;
		service = "get_pan_by_token|" + token;
	    client_socket << service; 
		client_socket >> reply;
   		std::cout << "\t[RESULT for get_pan_by_token:]\t" << reply;
		std::cout << std::endl;
		std::cout << std::endl;


   		std::cout << "\t[TEST....:]\t" << "Run get_masked_pan_by_token" << std::endl;
		service = "get_masked_pan_by_token|" + token;
	    client_socket << service; 
		client_socket >> masked_pan;
   		std::cout << "\t[RESULT..:]\t" << masked_pan;
		std::cout << std::endl;
		std::cout << std::endl;


   		std::cout << "\t[TEST....:]\t" << "Run get_issuer_by_token" << std::endl;
		service = "get_issuer_by_token|" + token;
	    client_socket << service; 
		client_socket >> issuer;
   		std::cout << "\t[RESULT..:]\t" << issuer;
		std::cout << std::endl;
		std::cout << std::endl;


   		std::cout << "\t[TEST....:]\t" << "Run get_card_type_by_token" << std::endl;
		service = "get_card_type_by_token|" + token;
	    client_socket << service; 
		client_socket >> card_type;
   		std::cout << "\t[RESULT..:]\t" << card_type;
		std::cout << std::endl;
		std::cout << std::endl;


   		std::cout << "\t[TEST....:]\t" << "Run get_card_type_by_pan" << std::endl;
		service = "get_card_type_by_pan|" + pan_in;
	    client_socket << service; 
		client_socket >> card_type;
   		std::cout << "\t[RESULT..:]\t" << card_type;
		std::cout << std::endl;
		std::cout << std::endl;


   		std::cout << "\t[TEST....:]\t" << "Run get_issuer_by_pan" << std::endl;
		service = "get_issuer_by_pan|" + pan_in;
	    client_socket << service; 
		client_socket >> issuer;
   		std::cout << "\t[RESULT..:]\t" << issuer;
		std::cout << std::endl;
		std::cout << std::endl;


   		std::cout << "\t[TEST....:]\t" << "Run get_count_tokens_by_masked_pan" << std::endl;
		service = "get_count_tokens_by_masked_pan|" + masked_pan;
	    client_socket << service; 
		client_socket >> count_tokens;
   		std::cout << "\t[RESULT..:]\t" << count_tokens;
		std::cout << std::endl;
		std::cout << std::endl;


   		std::cout << "\t[TEST....:]\t" << "Run get_tokens_by_masked_pan" << std::endl;
		service = "get_tokens_by_masked_pan|" + masked_pan;
	    client_socket << service; 
		client_socket >> tokens;
   		std::cout << "\t[RESULT..:]\t" << tokens;
		std::cout << std::endl;
		std::cout << std::endl;
    }


  	catch(SocketException& e )
    {
   		std::cout << "\t[ERR]\t" << e.description() << std::endl;;
    }
	return 0;
}
