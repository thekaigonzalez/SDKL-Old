#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include "../../tokenizer/read.h"

std::string remove_indents(std::string TC) {
    unsigned pos = TC.find("(");
    std::string T = TC.substr(0, pos);
    T.erase(std::remove_if(T.begin(), T.end(), isspace), T.end());
    unsigned args = TC.find("(");
    unsigned arg1 = TC.find(")");
    std::string e = TC.substr(args, arg1);
    T += e;
    return T;
}
int main(int argc, char* * argv) {
    std::string file = argv[1];
    std::string buffer;
    std::string res;
    std::ifstream ifile(file);
    while (getline(ifile, buffer))
        res += buffer;

    std::string reso = skipEntryPoints(res, BODY);

    std::vector<std::string>FunctionsAlit(split(reso, "\n"));

    for (const auto& func : FunctionsAlit) {


        std::cout << remove_indents(func) << std::endl;
        evaluateTrueFunctionalities(func);
    }


}