#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[] )
{
	std::string myin ="";

	try
    {
		ClientSocket client_socket("localhost", 30000 );
      	std::string reply;

      	try 
      	{
			string credit_card_number;
          	std::ifstream myfile("pans_in");
          	if (myfile.is_open())
          	{
              	while(getline(myfile, credit_card_number))
              	{
	          		client_socket << "set_token_by_pan|" + credit_card_number; 
	          		client_socket >> reply;
      				std::cout << credit_card_number << "|" << reply << std::endl;
              	}
          	myfile.close();
          	}
		}
      	catch(SocketException&){}
    }
  	catch(SocketException& e )
    {
   		std::cout << "\t[ERR]\t" << e.description() << std::endl;;
    }
	return 0;
}
