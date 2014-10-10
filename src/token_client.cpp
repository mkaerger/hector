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


			string line;
          	std::ifstream myfile("pans_in");
          	if (myfile.is_open())
          	{
              	while ( getline (myfile,line) )
              	{
              		//cout << line << endl;
	          		client_socket << "set_token_by_pan|" + line; 
	          		client_socket >> reply;
              	}
          	myfile.close();
          	}
	  
/*
		cout << "ENTER SERVICE:\n>";
      	getline(cin, myin);
	  	client_socket << myin; 
	  	client_socket >> reply;
  */ 		

		}
      	catch(SocketException&){}
      	std::cout << reply << "\n";;
    }
  	catch(SocketException& e )
    {
   		std::cout << "Exception was caught:" << e.description() << "\n";
    }
	return 0;
}
