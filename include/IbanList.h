#include <boost/unordered_map.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

using namespace std;

class IbanList
{
    public:
        IbanList();
        void load(const std::string &filename);
        string search_acquirer_by_pan(const std::string);

    private:
        typedef boost::unordered_map<std::string, std::string> unordered_map;
        unordered_map map;
};

