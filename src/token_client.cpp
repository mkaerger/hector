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
			cout << "ENTER SERVICE:\n>";
      		getline(cin, myin);
	  		client_socket << myin; 
	  		client_socket >> reply;
		}
      	catch(SocketException&){}
      	std::cout << reply << "\n";;
    }
  	catch(SocketException& e )
    {
   		std::cout << "\t[ERR]\t" << e.description() << std::endl;;
    }
	return 0;
}
