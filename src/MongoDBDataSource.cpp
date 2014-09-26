#include "mongo/client/dbclient.h"
#include "MongoDBDataSource.h"
#include "CardProcessor.h"
#include <string>
#include <time.h>

using namespace std;

mongo::DBClientConnection c;


MongoDBDataSource::MongoDBDataSource() 
{
    try {
        c.connect("localhost");
        std::cout << "Connection established." << std::endl;
    } catch(const mongo::DBException &e) {
        std::cout << "Caught " << e.what() << std::endl;
    }
}


std::string MongoDBDataSource::get_pan_by_token(CardProcessor cp) 
{
    return c.findOne("tokenizer.cc_data", QUERY("token"<<cp.token)).getStringField("pan");
}


std::string MongoDBDataSource::get_tokens_by_masked_pan(CardProcessor cp) 
{
    return NULL;
}


std::string MongoDBDataSource::get_card_type_by_token(CardProcessor cp) 
{
    return c.findOne("tokenizer.cc_data", QUERY("token"<<cp.token)).getStringField("card_type");
}


std::string MongoDBDataSource::get_count_tokens_by_masked_pan(CardProcessor cp) 
{
    return NULL;
}


std::string MongoDBDataSource::get_masked_pan_by_token(CardProcessor cp) 
{
    return c.findOne("tokenizer.cc_data", QUERY("token"<<cp.token)).getStringField("masked_pan");
}


std::string MongoDBDataSource::get_provider_by_token(CardProcessor cp) 
{
    return c.findOne("tokenizer.cc_data", QUERY("token"<<cp.token)).getStringField("provider");
}


std::string MongoDBDataSource::get_card_type_by_pan(CardProcessor cp) 
{
    return c.findOne("tokenizer.cc_data", QUERY("pan"<<cp.machine_readable_card_number())).getStringField("card_type");
}


std::string MongoDBDataSource::get_token_by_pan(CardProcessor cp) 
{
    return c.findOne("tokenizer.cc_data", QUERY("pan"<<cp.machine_readable_card_number())).getStringField("token");
}


std::string MongoDBDataSource::get_provider_by_pan(CardProcessor cp) 
{
    return c.findOne("tokenizer.cc_data", QUERY("pan"<<cp.machine_readable_card_number())).getStringField("provider");
}


std::string MongoDBDataSource::set_token_by_pan(CardProcessor cp) 
{

	time_t now = time(0);

	tm* localtm = localtime(&now);

	std::string hash = cp.create_token();

	mongo::BSONObj p = mongo::BSONObjBuilder().genOID()
		.append("pan",cp.machine_readable_card_number())
        .append("masked_pan",cp.get_masked_pan())
        .append("token",hash)
        .append("provider",3)
        .append("card_type",4)
        .append("date_created", asctime(localtm))
        .append("date_last_access", asctime(localtm))
        .obj();

        c.insert("tokenizer.cc_data", p);
        //string err = c.getLastError();

    return hash;
}
