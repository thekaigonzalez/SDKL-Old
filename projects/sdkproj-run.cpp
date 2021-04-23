#ifdef UNIX
#include "../structinfo/support.h"
#include <rapidxml/rapidxml_utils.hpp>

#include <string>
#include <iostream>

bool v = false;
bool recursive_parsing = false;

int main(int argc, char **argv) {
    std::string path = "sdkSourceDir.xml";


    rapidxml::file<> file(path.c_str());
    rapidxml::xml_document<> doc;
    doc.parse<0>(file.data());

    auto project_source = doc.first_node();


    std::string projname = project_source->first_attribute("name")->value();

    std::cout << "-- Compiling and running " << projname << " project.\n\n";

    sleepf(10000);

    std::string compiler = project_source->first_node("if")->first_node("set")->value();
    std::string setting = project_source
            ->first_node("if")
            ->first_node("set")
            ->first_attribute("type")->value();
    std::string dep = project_source->first_node("dependencies")->value();
    auto scriptTR = project_source->first_node("script");
    std::string depcheck = project_source->first_node("dependenciescheck")->first_attribute("on")->value();
    std::string srcdir = project_source->first_node("sourcedir")->value();
    std::string index_main = project_source->first_node("index")->value();
    std::string secset = project_source->first_node("if")->next_sibling("if")
            ->first_node("set")->value();
    std::string secsettype = project_source->first_node("if")->next_sibling("if")
            ->first_node("set")->first_attribute("type")->value();
    sleepf(10000);
    if (setting == "COMPILER-DIR") {
        std::cout << "-- The GNU Compiler Identification is " << compiler << ".\n\n";
        sleepf(10000);
        if (secsettype == "SYSTEM-COMMAND") {
            std::cout << "-- Running the Configured System Command. This is required for every Script.\n\n";
            system(secset.c_str());
            std::cout << "-- Checking for an SDK Compiler Path . . .\n\n";
            std::string compiler_t = project_source->first_node("set-compiler-dir")->value();
            std::ifstream cm(compiler_t);
            if (!cm) {
                std::cout
                        << "Failed to gain knowledge about an __SDK_COMPILER!\n\tAt <set-compiler-dir> XML : Requires A Valid Compiler to be present.\n\n";

            } else {
                std::cout << "-- The SDK Compiler Is present.\n\n";
                std::cout << "-- Patching Up Build. . . \n\n";
                std::cout << "-- Done! tool.json Package Configurations have been made.";
                std::ofstream fiile("tool.json");
                fiile << "{\n"
                         "  \"tool-config\": {\n"
                         "    \"package\": [\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\"\n"
                         "    ],\n"
                         "    \"package-t\": [\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\"\n"
                         "    ],\n"
                         "    \"packageC\": [\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\"\n"
                         "    ],\n"
                         "    \"packageK\": [\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\"\n"
                         "    ],\n"
                         "    \"package-v\": [\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\",\n"
                         "      \"asndiw maj028nhsa as dadd asiu dyuasd7 6asdyw7au h92h9h1982hn 1wdonw1d1273931mn2wuidy12u 2e281nwd9o1i2n\"\n"
                         "    ],\n"
                         "    \"recurENGINE\": {\n"
                         "      \"name\": \"main\",\n"
                         "      \"script\":\"index.sdk\"\n"
                         "    }\n"
                         "  }\n"
                         "}\n";
                fiile.close();

                std::cout << "-- Process Complete. Exiting.\n\n";
                return 2;
            }
        }
    }
}
#endif

#ifndef WINDOWS
#warning Windows Is currently Incompatible with the SDK Project & Tool.json Genenerator.
#endif