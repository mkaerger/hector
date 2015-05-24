#include "ElasticsearchDataSource.h"

using namespace std;

// cUrl results
string elasticsearch_results; 

// the curl object
CURL* curl;

ElasticsearchDataSource::ElasticsearchDataSource() 
{
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
}


size_t ElasticsearchDataSource::write_callback(char* buf, size_t size, size_t nmemb, void* up)
{ 
    // buf is the pointer to the data that elasticsearch has
    // size*nmemb is the size of the buffer

    for (int c = 0; c < size*nmemb; c++)
    {
        elasticsearch_results.push_back(buf[c]);
    }
	//tell curl how many bytes we handled
    return size*nmemb; 
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


    // POST mit oder ohne id:   
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:9200/hector/pan/");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{ \"pan\" : \"666\", \"masked_pan\" : \"666XXX666\", \"token\" : \"jsdfkhhfksdjjfk\", \"issuer\" : \"VISA\", \"card_type\" : \"DEBIT\", \"date_created\" : \"12.1.\", \"date_last_access\" : \"2.3.\"}");

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &ElasticsearchDataSource::write_callback);
    //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress
    curl_easy_perform(curl);

    //cout << endl << elasticsearch_results << endl;

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return NULL;
}
