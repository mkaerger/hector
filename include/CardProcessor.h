#ifndef Included_NameModel_H
#define Included_NameModel_H

#include <boost/regex.hpp>
#include "openssl/sha.h"
#include <boost/lexical_cast.hpp>
#include <sys/time.h>

//!  The CardProcessor class. 
/*!
  This class processes creditcard data. All the work is done here like 
  validation, tokenization and so on.
*/
class CardProcessor { 

  private:
    std::string create_random_string(int length);
  
  public: 
	//! Constructor.
    /*!
      Create your object by calling the constructor.
    */
    CardProcessor();
    void set_pan(const std::string pan); 
    void set_iban(const std::string iban); 
    void set_card_type(const std::string card_type); 
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
	//! pan.
    /*!
      pan is the creditcard number.
    */
    std::string pan; 
	
	//! iban.
    /*!
      iban is the issuer, means bank.
    */
    std::string iban; 
	
	//! card_type.
    /*!
      card_type can be either C or D (Credit or Debit).
    */
    std::string card_type; 
	
	//! token.
    /*!
      token is the tokenized creditcard number.
    */
	std::string token; 
	
	//! xxx_token.
    /*!
      xxx_token represents a credit card number in a masked version.
    */
    std::string xxx_token; 
}; 
#endif
