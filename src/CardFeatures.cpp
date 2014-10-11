#include "CardFeatures.h"

using namespace std;
using boost::property_tree::ptree;

CardFeatures::CardFeatures() {}

void CardFeatures::load(const std::string &filename)
{
    read_xml(filename, pt);

    BOOST_FOREACH(const ptree::value_type &v, pt.get_child("iban_registry.acquirers"))
    {
	const ptree& child = v.second;
	
        std::string additional_values = get_additional_values(
			child.get<string>("bank"), 
			child.get<string>("card_type"));
	
        map.insert(unordered_map::value_type(
			child.get<string>("pan_range"), 
			additional_values
		));
    }
}


std::string CardFeatures::get_additional_values(const std::string bank, const std::string card_type) {
   
	std::string delimiter = "|"; 
    std::string ret = bank + delimiter + card_type;
    return ret;
}


void CardFeatures::search_issuer_by_pan(const std::string mypan)
{
    std::string mypan_grower;
    std::string bank_found;
    std::string card_type_found;
    
    BOOST_FOREACH(char ch, mypan)
    {
        mypan_grower += ch;
		//std::cout << mypan_grower << std::endl;
        unordered_map::iterator it = map.find(mypan_grower);
        if (it != map.end())
        {
			std::vector<std::string> v;
			boost::split(v, it->second, boost::is_any_of("|"));

		    bank_found 		= v[0];
		    card_type_found = v[1];
        	v.clear();
		}
    }
    this->bank = bank_found;
    this->card_type = card_type_found;
}
