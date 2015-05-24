#include "ElasticsearchDataSource.h"

using namespace std;



ElasticsearchDataSource::ElasticsearchDataSource() 
{
}


std::string ElasticsearchDataSource::get_pan_by_token(CardProcessor cp) 
{
	return NULL;
}


std::string ElasticsearchDataSource::get_tokens_by_masked_pan(CardProcessor cp) 
{
    return NULL;
}


std::string ElasticsearchDataSource::get_card_type_by_token(CardProcessor cp) 
{
	return NULL;
}


std::string ElasticsearchDataSource::get_count_tokens_by_masked_pan(CardProcessor cp) 
{
    return NULL;
}


std::string ElasticsearchDataSource::get_masked_pan_by_token(CardProcessor cp) 
{
    return NULL;
}


std::string ElasticsearchDataSource::get_issuer_by_token(CardProcessor cp) 
{
    return NULL;
}


std::string ElasticsearchDataSource::get_card_type_by_pan(CardProcessor cp) 
{
    return NULL;
}


std::string ElasticsearchDataSource::get_token_by_pan(CardProcessor cp) 
{
    return NULL;
}


std::string ElasticsearchDataSource::get_issuer_by_pan(CardProcessor cp) 
{
    return NULL;
}


std::string ElasticsearchDataSource::set_token_by_pan(CardProcessor cp) 
{
	// time in sql now() format
	time_t     now = time(0);
    struct tm  tstruct;
    char       now_time[80];
    tstruct = *localtime(&now);
    strftime(now_time, sizeof(now_time), "%Y-%m-%d.%X", &tstruct);

	std::string hash = cp.create_token();

	//std::cout<< cp.iban << std::endl;;
	//std::cout<< err;

    return NULL;
}
