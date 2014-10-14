#include "CardProcessor.h"

using namespace boost;
using namespace std;

const boost::regex e("\\A(\\d{3,4})[- ]?(\\d{4})[- ]?(\\d{4})[- ]?(\\d{4})\\z");
const boost::regex t("\[A-Z0-9]{15,16}"); 
const std::string machine_format("\\1\\2\\3\\4");
const std::string human_format("\\1-\\2-\\3-\\4");

CardProcessor::CardProcessor() 
{
	//std::cout << "Constructor CardProcessor" << std::endl;
}

CardProcessor::~CardProcessor() 
{
	//std::cout << "Destructor CardProcessor" << pan << std::endl;
}

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


std::string CardProcessor::get_salted_sha256_string()
{
    unsigned char hash[SHA256_DIGEST_LENGTH];

    std::string time_salt;
    int t_salt;
    
    // get time with milli seconds 
    time_t now;
    struct tm *current;
    now = time(0);
    current = localtime(&now);
 
    struct timeval detail_time;
    gettimeofday(&detail_time,NULL);

    srand(current->tm_hour+current->tm_min+current->tm_sec+(detail_time.tv_usec/1000));
    t_salt = rand()/10;

    time_salt = boost::lexical_cast<string>(t_salt);

    SHA256_CTX sha256;
    SHA256_Init(&sha256);

    SHA256_Update(&sha256, this->pan.c_str(), this->pan.length());

    // salt the hash with randomized time
    SHA256_Update(&sha256, time_salt.c_str(), time_salt.length());

    SHA256_Final(hash, &sha256);

    std::string output = "";
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        output += this->to_hex(hash[i]);
    }
    return output;
}


std::string CardProcessor::to_hex(unsigned char s)
{
	stringstream ss;
    ss << hex << (int) s;
    return ss.str();
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
