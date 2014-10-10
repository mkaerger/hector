#include "CardProcessor.h"

using namespace boost;
using namespace std;

const boost::regex e("\\A(\\d{3,4})[- ]?(\\d{4})[- ]?(\\d{4})[- ]?(\\d{4})\\z");
const boost::regex t("\[A-Z0-9]{15,16}"); 
const std::string machine_format("\\1\\2\\3\\4");
const std::string human_format("\\1-\\2-\\3-\\4");

CardProcessor::CardProcessor() {}


void CardProcessor::set_pan(std::string pan)
{
   this->pan = pan;
}

void CardProcessor::set_card_type(std::string card_type)
{
   this->card_type = card_type;
}

void CardProcessor::set_iban(std::string iban)
{
   this->iban = iban;
}

void CardProcessor::set_token(std::string token)
{
   this->token = token;
}


void CardProcessor::set_xxx_token(std::string xxx_token)
{
   this->xxx_token = xxx_token;
}


bool CardProcessor::validate_card_format()
{
   return regex_match(this->pan, e);
}


bool CardProcessor::validate_token_format(const std::string token)
{
    //printf("%s\n", (char*)token.c_str());
    //printf("%i\n", token.length());
    //printf("%i\n", regex_match(token, t));
    return regex_match(token, t);
}


std::string CardProcessor::machine_readable_card_number() 
{
   return regex_replace(this->pan, e, machine_format, boost::match_default | boost::format_sed);
}


std::string CardProcessor::get_masked_pan()
{
    std::string s=this->machine_readable_card_number();
    std::string X = std::string(s.length()-10, 'x');
    s.replace(s.begin()+6,s.end()-4,X);

    return s;
}


std::string CardProcessor::create_random_string(int length)
{
    static string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result;
    result.resize(length);

    for (int i = 0; i < length; i++) {
        result[i] = charset[rand() % charset.length()];
    }

   return result;
}


std::string CardProcessor::create_token()
{
    std::string s=this->machine_readable_card_number();
    std::string X = std::string(this->create_random_string(s.length()-10));
    s.replace(s.begin()+6,s.end()-4, X);

    return s;
}


std::string CardProcessor::human_readable_card_number() 
{
   return regex_replace(this->pan, e, human_format, boost::match_default | boost::format_sed);
}
