#include "CardProcessor.h"

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>


//! The MySQL driver class. 
/*!
  This class is the interface to your MySQL instance.
*/
class MySQLDataSource { 

  private:
  
  public: 
    MySQLDataSource();
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
