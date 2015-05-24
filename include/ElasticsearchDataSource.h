#ifndef ELASTICSEARCHDATASOURCE_H
#define ELASTICSEARCHDATASOURCE_H

#include "CardProcessor.h"

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

#include <curl/curl.h>


//! The Elasticsearch driver class based on curl. 
/*!
  This class is the interface to your Elasticsearch instance.
*/
class ElasticsearchDataSource { 

  private:
  
  public: 
    ElasticsearchDataSource();
    std::string get_pan_by_token(CardProcessor);
    std::string get_tokens_by_masked_pan(CardProcessor);
    std::string get_card_type_by_token(CardProcessor);
    std::string get_count_tokens_by_masked_pan(CardProcessor);
    std::string get_masked_pan_by_token(CardProcessor);
    std::string get_issuer_by_token(CardProcessor);
    std::string get_card_type_by_pan(CardProcessor);
    std::string get_token_by_pan(CardProcessor);
    std::string get_issuer_by_pan(CardProcessor);
    std::string set_token_by_pan(CardProcessor);
};
#endif 
