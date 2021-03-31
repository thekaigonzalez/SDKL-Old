#include <iostream>
#include <fstream>
#include "tokenizer/read.h"

int main() {
    // Tests...
    // Separate functions like this
    std::ifstream file("idiots.sdk");
    std::string buffer;
    std::string resource;

    while (getline(file, resource)) {
        buffer += resource;
    };
    std::cout << "Buffeval = " << buffer << ", Evaluating All entries\n";
        std::string body = skipEntryPoints(buffer, BODY);

        std::cout << "Main Body:: " << body << std::endl;
    std::string entry = skipEntryPoints(buffer, ENTRY);

    std::cout << "Main Entry:: " << entry << std::endl;
    std::string minap = getTrueParameters(buffer);

    std::cout << "Main PARAMETERS:: " << minap << std::endl;
    std::string minf = skipEntryPoints(buffer, MAIN);

    std::cout << "Main function:: " << minf << std::endl;




}
