#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include "CardProcessor.h"
#include "CardFeatures.h"
#include "CardFeaturesException.h"

#ifdef PG_DATA_SOURCE	
#include "PGDataSource.h"
#endif		  

#ifdef MONGODB_DATA_SOURCE	
#include "MongoDBDataSource.h"
#endif		  

#ifdef MYSQL_DATA_SOURCE	
#include "MySQLDataSource.h"
#endif		  

#ifdef ELASTICSEARCH_DATA_SOURCE	
#include "ElasticsearchDataSource.h"
#endif		  

using namespace std;


int main ( int argc, char *argv[] )
{
	std::cout << "\t[...]\thector starting." << std::endl;
	std::cout << "\t[...]\tLoading creditcard registry." << std::endl;

	// Load card features from xml file
	CardFeatures *cardfeatures = new CardFeatures;
	try 
	{
    	cardfeatures->load("../share/xml/iban_registry.xml");
	}
	catch(CardFeaturesException& e) {
      	std::cout << "\t[ERR]\t" << e.description();
		exit (EXIT_FAILURE);
	}

	std::cout << "\t[OK ]" << std::endl;

	try
    {
    	ServerSocket server(30000);
		std::cout << "\t[...]\thector running, waiting for requests..." << std::endl;

      	while (true)
		{

	  		ServerSocket new_sock;
	  		server.accept (new_sock);
			std::cout << "\t\tConnection between client and server established." << std::endl;

	  		try
	    	{
	      		while (true)
				{
		  			std::string data;
		  			new_sock >> data;
		  
					std::cout << "\t" << data << std::endl;
		  			

					#ifdef PG_DATA_SOURCE	
				  	PGDataSource *DataSource = new PGDataSource; 
				  	#endif		  

				  	#ifdef MONGODB_DATA_SOURCE	
				  	MongoDBDataSource *DataSource = new MongoDBDataSource; 
				  	#endif		  
					
				  	#ifdef MYSQL_DATA_SOURCE	
				  	MySQLDataSource *DataSource = new MySQLDataSource; 
				  	#endif		  
				  	
				  	#ifdef ELASTICSEARCH_DATA_SOURCE	
				  	ElasticsearchDataSource *DataSource = new ElasticsearchDataSource; 
				  	#endif		  

					// Explode client input data by "|"
					std::vector<std::string> v;
				  	boost::split(v, data, boost::is_any_of("|"));
				  	std::string service    = v[0];	
				  	std::string input_data = v[1];  
				  	v.clear();	


					// Process services
					if (service == "get_pan_by_token")
				  	{
					  	CardProcessor *cp = new CardProcessor; 
					  	cp->set_token(input_data);		      
 
					  	if (!cp->validate_token_format(input_data)) {
						  	new_sock << "Wrong token format";
					  	} else {
						  	new_sock << DataSource->get_pan_by_token(*cp);
					  	}
				  	} 
					else if (service == "get_token_by_pan")
				  	{
						CardProcessor *cp = new CardProcessor; 
					  	cp->set_pan(input_data);		      

					  	if (!cp->validate_card_format()) {
						  	new_sock << "Wrong credit card format";
					  	} else {
						  	new_sock << DataSource->get_token_by_pan(*cp);
					  	}
				  	} 
					else if (service == "get_card_type_by_pan")
				  	{
					  	CardProcessor *cp = new CardProcessor; 
					  	cp->set_pan(input_data);		      

					  	if (!cp->validate_card_format()) {
						  	new_sock << "Wrong credit card format";
					  	} else {
						  	new_sock << DataSource->get_card_type_by_pan(*cp);
					  	}
				  	} 
					else if (service == "get_issuer_by_pan")
				  	{
					  	CardProcessor *cp = new CardProcessor; 
					  	cp->set_pan(input_data);		      

					  	if (!cp->validate_card_format()) {
						  	new_sock << "Wrong credit card format";
					  	} else {
						  	new_sock << DataSource->get_issuer_by_pan(*cp);
					  	}
				  	} 
					else if (service == "get_issuer_by_token")
				  	{
					  	CardProcessor *cp = new CardProcessor; 
					  	
						if (!cp->validate_token_format(input_data)) {
						  	new_sock << "Wrong token format";
					  	} else {
							cp->set_token(input_data);		      
					  		new_sock << DataSource->get_issuer_by_token(*cp);
					  	}
				  	} 
					else if (service == "get_count_tokens_by_masked_pan")
				  	{
					  	CardProcessor *cp = new CardProcessor; 
					  	cp->set_xxx_token(input_data);		      
					  	new_sock << DataSource->get_count_tokens_by_masked_pan(*cp);
				  	} 
					else if (service == "get_card_type_by_token")
				  	{
					  	CardProcessor *cp = new CardProcessor; 
					  	
						if (!cp->validate_token_format(input_data)) {
						  	new_sock << "Wrong token format";
					  	} else {
							cp->set_token(input_data);		      
					  		new_sock << DataSource->get_card_type_by_token(*cp);
				  		}
					} 
					else if (service == "get_masked_pan_by_token")
				  	{
					  	CardProcessor *cp = new CardProcessor; 
					  	cp->set_token(input_data);		      
					  	new_sock << DataSource->get_masked_pan_by_token(*cp);
				  	}
				  	else if (service == "get_tokens_by_masked_pan")
				  	{
					  	CardProcessor *cp = new CardProcessor; 
					  	cp->set_xxx_token(input_data);		      
					  	new_sock << DataSource->get_tokens_by_masked_pan(*cp);
				  	}
					else if (service == "set_token_by_pan")
				  	{
					  	//std::cout << "In Function set_token_by_pan" << std::endl;

						CardProcessor *cp = new CardProcessor; 
					  	cp->set_pan(input_data);		      
					 
						// fetch additional credit card information 
					  	cardfeatures->search_issuer_by_pan(cp->machine_readable_card_number());  
					  	cp->set_iban(cardfeatures->bank);		      
					  	cp->set_card_type(cardfeatures->card_type);		      

					  	if (!cp->validate_card_format()) {
					      	new_sock << "Wrong credit card format";
					  	}	
						else {
						  	new_sock << DataSource->set_token_by_pan(*cp);
					  	}
				  	} 
					else 
					{
		      			new_sock << "No such service: " + service;
    	  			}
	   			}
			}
	  		catch (SocketException&) {}
			}
    	}
    	catch (SocketException& e)
    	{
      	std::cout << "\t[SocketException]: " << e.description();
    }
    return 0;
}
