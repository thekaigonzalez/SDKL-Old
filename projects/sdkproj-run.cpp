#include <rapidxml_utils.hpp>


#include <string>
#include <iostream>
int main(int argc, char * * argv) {
    std::string path;
    std::string direct;

    try {
        path = argv[1];
        direct = argv[2];
    }
    catch (std::logic_error&) {
        path = "sdkSourceDir.xml";
    }
}