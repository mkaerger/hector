#include "MongoDBDataSource.h"

using namespace std;

mongo::DBClientConnection c;


MongoDBDataSource::MongoDBDataSource() 
{
    try {
        c.connect("localhost");
    } catch(const mongo::DBException &e) {
		std::cout << "Caught " << e.what() << std::endl;
    }
}


std::string MongoDBDataSource::get_pan_by_token(CardProcessor cp) 
{
    return c.findOne("hector.cc_data", 
		QUERY("token"<<cp.token)).getStringField("pan");
}


std::string MongoDBDataSource::get_tokens_by_masked_pan(CardProcessor cp) 
{
    return NULL;
}


std::string MongoDBDataSource::get_card_type_by_token(CardProcessor cp) 
{
    return c.findOne("hector.cc_data", 
		QUERY("token"<<cp.token)).getStringField("card_type");
}


std::string MongoDBDataSource::get_count_tokens_by_masked_pan(CardProcessor cp) 
{
    return NULL;
}


std::string MongoDBDataSource::get_masked_pan_by_token(CardProcessor cp) 
{
    return c.findOne("hector.cc_data", 
		QUERY("token"<<cp.token)).getStringField("masked_pan");
}


std::string MongoDBDataSource::get_issuer_by_token(CardProcessor cp) 
{
    return c.findOne("hector.cc_data", 
		QUERY("token"<<cp.token)).getStringField("issuer");
}


std::string MongoDBDataSource::get_card_type_by_pan(CardProcessor cp) 
{
    return c.findOne("hector.cc_data", 
		QUERY("pan"<<cp.machine_readable_card_number())).getStringField("card_type");
}


std::string MongoDBDataSource::get_token_by_pan(CardProcessor cp) 
{
    return c.findOne("hector.cc_data", 
		QUERY("pan"<<cp.machine_readable_card_number())).getStringField("token");
}


std::string MongoDBDataSource::get_issuer_by_pan(CardProcessor cp) 
{
    return c.findOne("hector.cc_data", 
		QUERY("pan"<<cp.machine_readable_card_number())).getStringField("issuer");
}


std::string MongoDBDataSource::set_token_by_pan(CardProcessor cp) 
{
	// time in sql now() format
	time_t     now = time(0);
    struct tm  tstruct;
    char       now_time[80];
    tstruct = *localtime(&now);
    strftime(now_time, sizeof(now_time), "%Y-%m-%d.%X", &tstruct);

	std::string hash = cp.create_token();

	mongo::BSONObj p = mongo::BSONObjBuilder().genOID()
		.append("pan",cp.machine_readable_card_number())
        .append("masked_pan",cp.get_masked_pan())
        .append("token",hash)
        .append("issuer",cp.iban)
        .append("card_type",cp.card_type)
        .append("date_created", now_time)
        .append("date_last_access", now_time)
        .obj();

        c.insert("hector.cc_data", p);
        string err = c.getLastError();
		
	std::cout<< cp.iban << std::endl;;
	std::cout<< err;

    return hash;
}
