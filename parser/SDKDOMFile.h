
# define dom


/**
* Simplified DOM XML Parser.
*/

#include <rapidxml_utils.hpp>


namespace sdk {

    class Domfile {
        std::string name;
        rapidxml::xml_document<> doc;
    public:
        Domfile(std::string names) {
            name = names;
        }
        void setName(std::string nam) {
            name = nam;
        }
        void parse () {
            rapidxml::file<> xmlFile(name.c_str());

            doc.parse<0>(xmlFile.data());
        }
        rapidxml::xml_node<> * firstNode() {
            return doc.first_node();
        }
        std::string firstNodeValue() {
            return doc.first_node()->value();
        }

    };
}