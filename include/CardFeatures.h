#include <boost/unordered_map.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;

//!  The CardFeatures class. 
/*!
  This class reads issuer data from xml to unorderep_map.
  Get access to all the issuer data by card number.
*/
class CardFeatures
{
	public:
    CardFeatures();
    void load(const std::string &filename);
    void search_issuer_by_pan(const std::string);
	void set_bank(std::string);
	
	public:
	std::string bank;
	std::string card_type;

    private:
	boost::property_tree::ptree pt;
    typedef boost::unordered_map<std::string, std::string> unordered_map;
    unordered_map map;
	std::string get_additional_values(
		const std::string bank, 
		const std::string card_type);
};
