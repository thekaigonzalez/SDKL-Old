#include <iostream>
#include <fstream>
#include "tokenizer/read.h"

int main() {
    // Tests...
    // Separate functions like this
    std::ifstream file("index.sdk");
    std::string buffer;
    std::string resource;

    while (getline(file, resource)) {
        SDKL_STREAM << resource;
    };

    parsestream();//new stream :)




}
