#include <iostream>
#include "../../parser/sdk__om.h"




// Implement ordered Lists

int main()
{
    sdk::ordered_map<std::string>  Strings{};
    std::string macro;
    std::string def = "hello";
    Strings.add(macro, def);
    
    Strings.remove(0);
    // Prints garbage. Be careful!
    std::cout << Strings.size() << " Strings values " << Strings.findOf(macro);
}