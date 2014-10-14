#ifndef PGDATASOURCE_H
#define PGDATASOURCE_H

#include <libpq-fe.h>
#include "CardProcessor.h"

//! The PostgreSQL driver class. 
/*!
  This class is the interface to your PostgreSQL instance.
*/
class PGDataSource { 

  private:
  
  public: 
    PGDataSource();
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
