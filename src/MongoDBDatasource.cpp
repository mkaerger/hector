#include "mongo/client/dbclient.h"
#include <libpq-fe.h>
#include <string>

using namespace std;

std::string     token;
std::string     s1;
std::string     s2;
std::string     s3;


MongoDBDataSource::MongoDBDataSource() 
{
    mongo::DBClientConnection c;
    c.connect("localhost");
}


std::string MongoDBDataSource::get_pan_by_token(CardProcessor cp) 
{
        return;
}


std::string MongoDBDataSource::get_tokens_by_masked_pan(CardProcessor cp) 
{
    return;
}


std::string MongoDBDataSource::get_card_type_by_token(CardProcessor cp) 
{
    return;
}


std::string MongoDBDataSource::get_count_tokens_by_masked_pan(CardProcessor cp) 
{
    return;
}


std::string MongoDBDataSource::get_masked_pan_by_token(CardProcessor cp) 
{
    return;
}


std::string MongoDBDataSource::get_provider_by_token(CardProcessor cp) 
{
    return;
}


std::string MongoDBDataSource::get_card_type_by_pan(CardProcessor cp) 
{
    return;
}



std::string MongoDBDataSource::get_token_by_pan(CardProcessor cp) 
{
    return;
}


std::string MongoDBDataSource::get_provider_by_pan(CardProcessor cp) 
{
    return;
}


std::string MongoDBDataSource::set_token_by_pan(CardProcessor cp) 
{
    return;
}
