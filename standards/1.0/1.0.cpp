#include <fstream>
#include "grammar.h"



int main(int argc, char* * argv) {
    std::string file = argv[1];
    std::string buffer;
    std::string res;
    std::ifstream ifile(file);
    while (getline(ifile, buffer))
        res += buffer;

}