#ifndef MONGODBDATASOURCE_H
#define MONGODBDATASOURCE_H

#include "CardProcessor.h"
#include "mongo/client/dbclient.h"

//! The MongoDB driver class. 
/*!
  This class is the interface to your MongoDB instance.
*/
class MongoDBDataSource { 

  private:
  
  public: 
    MongoDBDataSource();
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
