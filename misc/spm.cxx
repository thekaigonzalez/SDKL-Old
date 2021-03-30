// Install scripts from github or other sites.

# define p                0





int size             =   10;
const char* cpexpr             =   "";

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <fstream>
#include "../structinfo/support.h"
std::string system_silent(const std::string& cmd) {
    system((cmd + " > log.txt").c_str());
    std::string result;
    std::ifstream cfile("log.txt");
    char buffer[4000];
    while (cfile >> buffer)
        result += buffer;
    remove("log.txt");
    return result;
}


// main


int main(int argc, char* * argv)
{
    std::string arg1 = argv[1];

    if (arg1 == "install" || arg1 == "i") {
        try {
            std::cout << "Getting " << argv[2] << ".. . .\n\n";
            sleepf(1000);
            std::cout << "[ - ] : Installing " << argv[2] << "#main\n" << std::flush;
            sleepf(600);
            std::string repo = argv[2];
            std::cout << "[ - - ] : Doing my magic. . .\n" << std::flush;
            sleepf(3000);

            std::cout << "Attempted to install git repository " << repo << "." << std::endl;
            try {
                std::string ifisflag = argv[3];
                if (ifisflag == "--git-output")
                    std::cout << system_silent("git clone https://www.github.com/Kai-Builder/Myno");
            }
            catch (std::logic_error&) {
                std::cout << "To get git outputs, Next time say --git-output.\n";
            }

        }
        catch (std::logic_error&) {
            std::cout << "Fatal Error: No repository given." << std::flush;
        }
    }
}