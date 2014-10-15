#ifndef CARDFEATURES_H
#define CARDFEATURES_H

#include <boost/unordered_map.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>
#include "CardFeaturesException.h"

using namespace std;

//!  The CardFeatures class. 
/*!
  This class reads issuer data from xml to unordered_map.
  Get access to all the issuer data by card number.
*/
class CardFeatures
{
	public:
    CardFeatures();
    void load(const std::string &filename);
    void search_issuer_by_pan(const std::string);
	struct additional_card_info {
        std::string bank;
        std::string card_type;
    };

	public:
	std::string bank;
	std::string card_type;

    private:
	boost::property_tree::ptree pt;
    typedef boost::unordered_map<std::string, additional_card_info> unordered_map;
    unordered_map map;
};
#endif
