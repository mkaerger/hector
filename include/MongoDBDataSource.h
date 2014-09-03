#include <string>
#include "CardProcessor.h"

class MongoDBDataSource { 

  private:
  
  public: 
    MongoDBDataSource();
    std::string get_pan_by_token(CardProcessor);
    std::string get_tokens_by_masked_pan(CardProcessor);
    std::string get_card_type_by_token(CardProcessor);
    std::string get_count_tokens_by_masked_pan(CardProcessor);
    std::string get_masked_pan_by_token(CardProcessor);
    std::string get_provider_by_token(CardProcessor);
    std::string get_card_type_by_pan(CardProcessor);
    std::string get_token_by_pan(CardProcessor);
    std::string get_provider_by_pan(CardProcessor);
    std::string set_token_by_pan(CardProcessor);
}; 
