#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include "CardProcessor.h"

#ifdef PG_DATA_SOURCE	
#include "PGDataSource.h"
#endif		  

#ifdef MONGODB_DATA_SOURCE	
#include "MongoDBDataSource.h"
#endif		  

using namespace std;


int main ( int argc, char *argv[] )
{
    std::cout << "HECTOR RUNNING.\n";

    try
    {
      ServerSocket server (30000);

      while (true)
	{

	  ServerSocket new_sock;
	  server.accept (new_sock);

	  try
	    {
	      while (true)
		{
		  std::string data;
		  new_sock >> data;
		  
		  #ifdef PG_DATA_SOURCE	
		  PGDataSource *driver = new PGDataSource; 
		  #endif		  

		  #ifdef MONGODB_DATA_SOURCE	
		  MongoDBDataSource *driver = new MongoDBDataSource; 
		  #endif		  
	          
          std::string s          = data;
		  std::string delimiter  = "|";
          std::string service    = s.substr(0, s.find(delimiter));	
		  
		  unsigned pos           = s.find("|"); 
          std::string input_data = s.substr (pos + 1);  

		  if (service == "get_pan_by_token")
		  {
    		  CardProcessor *cp = new CardProcessor; 
		      cp->set_token(input_data);		      
 
		      if (!cp->validate_token_format(input_data)) {
		          new_sock << "Wrong token format";
  		      }	else {
		          new_sock << driver->get_pan_by_token(*cp);
		      }
		  }
		  else if (service == "get_token_by_pan")
		  {
    		      CardProcessor *cp = new CardProcessor; 
		      cp->set_pan(input_data);		      

		      if (!cp->validate_card_format()) {
		          new_sock << "Wrong credit card format";
  		      }	else {
		          new_sock << driver->get_token_by_pan(*cp);
 		      }
		  }
		  else if (service == "get_card_type_by_pan")
		  {
    		  CardProcessor *cp = new CardProcessor; 
		      cp->set_pan(input_data);		      

		      if (!cp->validate_card_format()) {
		          new_sock << "Wrong credit card format";
  		      }	else {
		          new_sock << driver->get_card_type_by_pan(*cp);
		      }
		  }
		  else if (service == "get_provider_by_pan")
		  {
    		  CardProcessor *cp = new CardProcessor; 
		      cp->set_pan(input_data);		      

		      if (!cp->validate_card_format()) {
		          new_sock << "Wrong credit card format";
  		      }	else {
		          new_sock << driver->get_provider_by_pan(*cp);
		      }
		  }
	  	  else if (service == "get_provider_by_token")
		  {
    		  CardProcessor *cp = new CardProcessor; 
		      cp->set_token(input_data);		      
		      new_sock << driver->get_provider_by_token(*cp);
		  }
	  	  else if (service == "get_count_tokens_by_masked_pan")
		  {
    		  CardProcessor *cp = new CardProcessor; 
		      cp->set_xxx_token(input_data);		      
		      new_sock << driver->get_count_tokens_by_masked_pan(*cp);
		  }
	  	  else if (service == "get_card_type_by_token")
		  {
    		  CardProcessor *cp = new CardProcessor; 
		      cp->set_token(input_data);		      
		      new_sock << driver->get_card_type_by_token(*cp);
		  }
	  	  else if (service == "get_masked_pan_by_token")
		  {
    		  CardProcessor *cp = new CardProcessor; 
		      cp->set_token(input_data);		      
		      new_sock << driver->get_masked_pan_by_token(*cp);
		  }
		  
	  	  else if (service == "get_tokens_by_masked_pan")
		  {
    		  CardProcessor *cp = new CardProcessor; 
		      cp->set_xxx_token(input_data);		      
		      new_sock << driver->get_tokens_by_masked_pan(*cp);
		  }
	          else if (service == "set_token_by_pan")
		  {
    		  CardProcessor *cp = new CardProcessor; 
		      cp->set_pan(input_data);		      

		      if (!cp->validate_card_format()) {
		          new_sock << "Wrong credit card format";
  		      }	else {
		          new_sock << driver->set_token_by_pan(*cp);
		      }
		  }
		  else 
		  {
		      new_sock << "No such service: " + service;
    	  }
	   }
	}
	  catch ( SocketException& ) {}
	}
    }
    catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

    return 0;
}
