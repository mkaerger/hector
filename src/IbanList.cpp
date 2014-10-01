#include "IbanList.h"

using namespace std;

IbanList::IbanList() {}

void IbanList::load(const std::string &filename)
{
    using boost::property_tree::ptree;
    ptree pt;

    read_xml(filename, pt);

    BOOST_FOREACH(const ptree::value_type &v, pt.get_child("iban_registry.acquirers"))
    {
        const ptree& child = v.second;
        map.insert(unordered_map::value_type(
			child.get<string>("pan_range"), 
			child.get<string>("bank")
		));
    }
}

string IbanList::search_acquirer_by_pan(const std::string mypan)
{
    std::string mypan_grower;
    std::string bank_found;

    BOOST_FOREACH(char ch, mypan)
    {
        mypan_grower += ch;

        unordered_map::iterator it = map.find(mypan_grower);
        if (it != map.end())
        {
            bank_found = it->second;
        }
    }
    return bank_found;
}
