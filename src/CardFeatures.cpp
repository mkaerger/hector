#include "CardFeatures.h"

using namespace std;
using boost::property_tree::ptree;

CardFeatures::CardFeatures() {}

void CardFeatures::load(const std::string &filename)
{
    try
	{
		read_xml(filename, pt); 
	} 
	catch(const boost::property_tree::xml_parser::xml_parser_error& e) {
		throw CardFeaturesException(e.what());
	}

    BOOST_FOREACH(const ptree::value_type &v, pt.get_child("registry.issuers"))
    {
	const ptree& child = v.second;
	
		additional_card_info card_info;
        card_info.bank 		= child.get<string>("bank");
        card_info.card_type = child.get<string>("card_type");

        map.insert(unordered_map::value_type(
			child.get<string>("pan_range"), 
			card_info
		));
    }
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
		    bank_found 		= it->second.bank;
		    card_type_found = it->second.card_type;
		}
    }
    this->bank = bank_found;
    this->card_type = card_type_found;
}
