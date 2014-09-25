#include "mongo/client/dbclient.h"
#include "MongoDBDataSource.h"
#include "CardProcessor.h"
#include <string>

using namespace std;

mongo::DBClientConnection c;
std::string     token;
std::string     s1;
std::string     s2;
std::string     s3;


MongoDBDataSource::MongoDBDataSource() 
{
    try {
        c.connect("localhost");
        std::cout << "Connection established." << std::endl;
    } catch( const mongo::DBException &e ) {
        std::cout << "caught " << e.what() << std::endl;
    }
}


std::string MongoDBDataSource::get_pan_by_token(CardProcessor cp) 
{

    return NULL;
}


std::string MongoDBDataSource::get_tokens_by_masked_pan(CardProcessor cp) 
{
    return NULL;
}


std::string MongoDBDataSource::get_card_type_by_token(CardProcessor cp) 
{
    return NULL;
}


std::string MongoDBDataSource::get_count_tokens_by_masked_pan(CardProcessor cp) 
{
    return NULL;
}


std::string MongoDBDataSource::get_masked_pan_by_token(CardProcessor cp) 
{
    return NULL;
}


std::string MongoDBDataSource::get_provider_by_token(CardProcessor cp) 
{
    return NULL;
}


std::string MongoDBDataSource::get_card_type_by_pan(CardProcessor cp) 
{
    return NULL;
}


std::string MongoDBDataSource::get_token_by_pan(CardProcessor cp) 
{
    
    cout<< c.findOne("tokenizer.cc_data", QUERY("pan"<<cp.machine_readable_card_number()));
}


std::string MongoDBDataSource::get_provider_by_pan(CardProcessor cp) 
{
    return NULL;
}


std::string MongoDBDataSource::set_token_by_pan(CardProcessor cp) 
{
    return NULL;
}
