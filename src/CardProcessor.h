#include <boost/regex.hpp>
#include "openssl/sha.h"
#include <boost/lexical_cast.hpp>
#include <sys/time.h>


class CardProcessor { 

  private:
    std::string to_hex(unsigned char s);
  
  public: 
    CardProcessor(const std::string s);
    bool validate_card_format(); 
    bool validate_token_format(std::string token); 
    std::string machine_readable_card_number();
    std::string human_readable_card_number();
    std::string get_salted_sha256_string();
    std::string get_masked_pan();
    
  public: 
    std::string pan; 
    std::string token; 
}; 


