#ifndef Included_NameModel_H
#define Included_NameModel_H

#include <boost/regex.hpp>
#include "openssl/sha.h"
#include <boost/lexical_cast.hpp>
#include <sys/time.h>


class CardProcessor { 

  private:
    std::string create_random_string(int length);
  
  public: 
    CardProcessor();
    void set_pan(const std::string pan); 
    void set_iban(const std::string iban); 
    void set_token(const std::string token); 
    void set_xxx_token(const std::string xxx_token); 
    bool validate_card_format(); 
    bool validate_token_format(std::string token); 
    std::string machine_readable_card_number();
    std::string human_readable_card_number();
    std::string get_salted_sha256_string();
    std::string create_token();
    std::string get_masked_pan();
    
  public: 
    std::string pan; 
    std::string iban; 
    std::string token; 
    std::string xxx_token; 
}; 
#endif
