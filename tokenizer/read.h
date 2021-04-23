// Raw token system.
// Find Macros In /tokenizer/macros/macrodef.h
// Find Functions in /parser/pdef & /util/struct.h
#ifndef SDK_L_READ_H
#define SDK_L_READ_H

#include <cstring>
#include <algorithm>
#include <iostream>
#include "../parser/wildcard.h"
#include "types.h"
#include "attrib.h"
#include "../state/cur.h"
#include "../parser/SDK_Postype.h"
#include "../parser/write.h"
#include "../parser/spaceremove.h"
#include <sstream>
class Function {
private:
    std::string contents;
public:
    explicit Function(const std::string& content) {
        contents = content;
    }
    std::string getParameters() {
        std::string contentsa  = contents.substr(0, ' ');
        std::string T = contentsa.substr(contentsa.find('(')+1, contentsa.find('|'));
        T.erase(std::remove(T.begin(), T.end(), ')'), T.end());
        return T;
    }
    void switchContent(const std::string& newcontent) {
        contents = newcontent;
    }
    std::string getName() {
        return contents.substr(0, contents.find('('));
    }
};
std::vector<std::string>charDefaults{};
/**
 * Returns a Corrected SDK DataType Holding Statement Return Information.
 * @param code
 */
SDK_Type eval(const std::string& code) {
    SDK_Type current_ReturnType = NONE;
    // get up to a space character.
    const std::string keyword = code.substr(0, ' ');
    if (keyword == "int" || keyword == "Integer") current_ReturnType = INTEGERVALUE;
    if (keyword == "string" || keyword == "String") current_ReturnType = STRING;
    if (keyword == "char" || keyword == "Character") current_ReturnType = SDK_Type::CHARACTER;
    if (keyword == "void" || keyword == "func") current_ReturnType = VOIDIDENTIFIER;
    if (keyword == ".call" || keyword == "vless") current_ReturnType = VOIDLESS;
    if (keyword == "null" || keyword == "nil") current_ReturnType = SDK_Type::NULLPOINTER;
    /**
     * IF the statment hasn't ended
     */
    if (code.find(';') == std::string::npos)
        std::cout << "Unexpected EOF When parsing. Expected ';' as EOS.\n";
    /**
     * If there's no callback methods
     * @see SDK.CallbackMethod<typename>
     */
    if (code.find('.') == std::string::npos)
        std::cout << "WARNING: No callback methods implemented. Nothing can be called.\n";
    return current_ReturnType;
}
// This Part returns certain parts of a Statement using different tokens.

/**
 * app:help() => app:help()
 * @param code
 * @return
 */
std::string getFirstKeyword(const std::string& code) {
    return code.substr(0, ' ');
}
/**
 * app:help() => app:help
 * @param code
 * @param ignoreSpaces
 * @return
 */
std::string getBeforeFunction(const std::string& code, bool ignoreSpaces) {

}
/**
 * app:help() => app
 * @param code
 * @return
 */
std::string getDataTable(const std::string& code) {
    return code.substr(0, ':');
}
/**
 * Callback methods are explicitly defined methods that define a allocated and run script snippet.
 * @code
 * .call main() -> true
 * call main() -> false
 * @endcode
 * @param snippet
 * @return
 */
bool isCallbackMethod(const std::string& snippet) {
    std::string first = getFirstKeyword(snippet);
    if (strcmp(".", first.c_str()) != 0) {
        if (first.find('(') != std::string::npos) {
            std::cout << "Function is not a callback method or a valid function. Returning.\n";
            return false;
        }
        else {
            return true;
        }
    }

    /**
     * Runtime Errors.
     */
    return false;
}

/**
 * Checks if the snippet given is a function (1), And Is an official SDK Function (2).
 * @param snippet
 * @return true if snippet given is a function and an official one.
 */
bool isActualFunction(const std::string& snippet) {
    if (snippet.find('(') != std::string::npos) {
        std::cout << "Function is not a valid function. Nor Is it a SDK.Func to begin with.\n";
        return false;
    }
    else {
        const std::string funcname = snippet.substr(0 , snippet.find('('));
        if (funcname == "assrt") {
            return true;
        }
        else if (funcname == "memst") return true;
        else if (funcname == "doc") return true;
        else return false;
    }
    return false;
}
void EvaluateFunctions(const std::string& snippet) {
    if (snippet.find('(') == std::string::npos) {
        std::cout << "\nFunction is not a valid function. Nor Is it a SDK.Func to begin with.\n";
    }
    else {
        std::string statement = snippet.substr(0, snippet.find(';'));
// If the EOL Is unavailable.
        if (snippet.find(';') == std::string::npos) return;
        while (statement == snippet.substr(snippet.find(';'))) {
            unsigned functionpos = statement.find('(');
            unsigned functionbodybeginpos = statement.find('(')+1;
            unsigned functionbodypos = statement.find(')');
            std::string function = statement.substr(0, functionpos);
            std::string functionbody = statement.substr(functionbodybeginpos, functionbodypos);
            if (function == "hello") {
                std::cout << "world! Body: " << functionbody;

            }
            else if (function == "end") {
                break;
            }
            statement = snippet.substr(0, snippet.find(';'));


        }
    }

}
/**
 * Runs the <script>.
 * @param script
 */
void run(const std::string& script) {
    /**
     * Checks if the script has a `main` Entry point.
     * Usually defined as .call main(), In the standard.
     */
     if (script.substr(0, '(') == ".call main") {
         // Now we write our code
         const std::string statement = script.substr(script.find('{')+1, script.find('}'));

         while (true) {
             EvaluateFunctions(statement);
             break;
         }
     }
}

/**
 * Allow NULL Keyword Checking
 * Returns true if the keyword returns a NULL Value / Has zero bytes associated.
 *
 * @code
 *
 * IsNullValue("null") -> true
 *
 * IsNullValue("egg") -> false
 */
 bool IsNullValue(const std::string& DWORD) {
     if (DWORD.substr(0, ' ') == "null" || DWORD.substr(0, ' ')== "nil")
         return true;
     else
         return false;
 }

 /**
  * Skips the entry points and returns the value specified in the PosType POSITION
  * @code
  * string = [
  * .call main() {
  *     assrt(5);
  * }
  * ]
  * skipEntryPoints(string, SDK_Postype::BODY) -> assrt(5);
  * skipEntryPoints(string, SDK_Postype::MAIN) -> main();
  * @endcode
  * @param code : string
  * @param Position : SDKPositionType
  * @return SDKPositionType ||
  */
std::string skipEntryPoints(const std::string& code, SDK_Postype  Position) {
    std::string entry;
    std::string main;
    std::string winMainParams;
    std::string lXMain;
    std::string statements;
    // checks if the given entry is a callback method.
     unsigned first = code.find('.');
     unsigned last = code.find(' ');

    entry = code.substr(first, last);
    if (entry == ".call") {
        // checks if it's the main() branch.
        unsigned firstx = code.find(' ');
        unsigned lastx = code.find('(');
        main = code.substr(firstx, lastx-firstx);
        ridOfSpaces(main);

        if (main == "main") {

            // gets the statements
            unsigned firstxf = code.find('{')+1;
            unsigned lastxf = code.find('}');
            statements = code.substr(firstxf, lastxf-firstxf);
        }

    }
    else if (entry == "win") {
        // checks if it's the main() branch.
        unsigned firstx = code.find(' ');
        unsigned lastx = code.find('(');
        unsigned et = code.find('(');
        unsigned etx = code.find(')');

        main = code.substr(firstx, lastx-firstx);
        ridOfSpaces(main);
        if (main == "main") {

            // gets the statements
            unsigned firstxf = code.find('{')+1;
            unsigned lastxf = code.find('}');
            statements = code.substr(firstxf, firstxf-lastxf );
        }

    }
    if (Position == MAIN)
        return main;
    if (Position == BODY)
        return statements;
    if (Position == ENTRY)
        return entry;
    if (Position == WINMAINPARAMS)
        return winMainParams;
    else
        return "NONE";
}
std::stringstream csdkin;
/**
 * Returns the true parameters of first instance of SDK.Function().
 *
 * @param code
 * @return
 */
std::string getTrueParameters(const std::string& code) {
    unsigned firstx = code.find('(')+1;
    unsigned lastx = code.find(')');
    return code.substr(firstx, lastx-firstx);
}
/**
 * Evaluates a standard function. Core Modules aren't in standards.
 * @breif Standards implement their own modules,
 */
void evaluateTrueFunctionalities( std::string code) {
    unsigned name = code.find('(');
    unsigned param1 = code.find('(')+1;
    unsigned param2 = code.find(')');

    std::string function = code.substr(0, name);

std::string parameters = code.substr(param1, param2-param1);


    ridOfSpaces(function);
    if (function == ".println") {
        std::cout << parameters << std::endl;
    }
    else if (function == ".fwd") {
        std::cout << parameters << ":" << __TIME__ << std::endl;
    }
}
/*
std::string split implementation by using delimeter as an another string
*/
std::vector<std::string> split(std::string stringToBeSplitted, std::string delimeter)
{
    std::vector<std::string> splittedString;
    int startIndex = 0;
    int  endIndex = 0;
    while( (endIndex = stringToBeSplitted.find(delimeter, startIndex)) < stringToBeSplitted.size() )
    {
        std::string val = stringToBeSplitted.substr(startIndex, endIndex - startIndex);
        splittedString.push_back(val);
        startIndex = endIndex + delimeter.size();
    }
    if(startIndex < stringToBeSplitted.size())
    {
        std::string val = stringToBeSplitted.substr(startIndex);
        splittedString.push_back(val);
    }
    return splittedString;
}
std::stringstream SDKL_STREAM;
std::stringstream SDKL_TEMPSTREAM;
std::stringstream SDKL_MACHINESTREAM;
std::stringstream SDKL_SUBFUNCSTREAM;
std::stringstream SDKL_FUNCTEMPSTREAM;
std::stringstream SDKL_INCLUSIONSTREAM;
void add_tostream(std::string Content)
{
    SDKL_STREAM << Content << std::endl;
}
void pexec_preset()
{
    std::string keyword;
    SDKL_TEMPSTREAM >> keyword;

    if (keyword == "EXTENSION")
    {
        std::string funcname;
        getline(SDKL_TEMPSTREAM,funcname, '(');
        funcname.erase(std::remove_if(funcname.begin(), funcname.end(), isspace), funcname.end());
        std::string funcparams;
        getline(SDKL_TEMPSTREAM,funcparams, ')');

        std::string statements;
        std::string statements_op;
        getline(SDKL_STREAM,statements_op, '{');
        getline(SDKL_STREAM,statements, '}');
        std::cout << "Precaching " << statements << " with funcname:" << funcname;
        SDKL_FUNCTEMPSTREAM << statements;
        if (funcname == "init")
        {
            std::cout << "INIT\n";
            std::string function;
            std::string parameters;

            while (getline(SDKL_TEMPSTREAM, function,'(') && getline(SDKL_TEMPSTREAM, parameters, ')'))
            {
                std::cout << function;
                function.erase(std::remove_if(function.begin(), function.end(), isspace), function.end());
                if (function == "println")
                {
                    std::cout << parameters << std::endl;
                }
                else if (function == "dump")
                {
                    char buffer[std::stoi(parameters)];
                    std::cout << buffer << std::endl;
                }
                else if (function == "return")
                {
                    return;
                }
                else if (function == "system")
                {
                    system(parameters.c_str());
                }
                else if (function == "Print")
                {
                    csdkin << parameters;
                    std::cout <<parameters;
                }
                else if (function == "OBLog")
                {
                    csdkin << parameters;
                    std::cout << parameters << std::endl;
                }
                else if (function == "resolve")
                {
                    if (parameters == "garbage")
                    {
                        std::cout << SDKL_STREAM.str() << std::endl;
                    }
                    else if (parameters == "pi")
                    {
                        std::cout << "3.14" << std::endl;
                    }
                    else if (parameters == "csdkout")
                    {
                        std::cout << csdkin.str() << std::endl;
                    }
                }
                else {
                    std::ifstream include("scripts/" + function + ".sdk");
                    if (!include) {
                        std::cout << "WARN: Function not in interpreter library. Checking for functions from the local script.\n"
                                     "err: scripts\\" << function << ".sdk not found.\n";
                        break;
                    }
                    else {
                        std::string res;
                        while (getline (include, res))
                        {
                            SDKL_TEMPSTREAM << res << std::endl;
                        }


                    }


                }
            }
            SDKL_TEMPSTREAM.clear();

        }
        else
        {
            SDKL_INCLUSIONSTREAM << funcname;

        }
    }

}
void parsestream();

void send_funcstream()
{
    std::string function;
    std::string parameters;

    while (getline(SDKL_SUBFUNCSTREAM, function,'(') && getline(SDKL_SUBFUNCSTREAM, parameters, ')'))
    {
        function.erase(std::remove_if(function.begin(), function.end(), isspace), function.end());
        if (function == "println")
        {
            std::cout << parameters << std::endl;
        }
        else if (function == "dump")
        {
            char buffer[std::stoi(parameters)];
            std::cout << buffer << std::endl;
        }
        else if (function == "return")
        {
            break;
        }
        else if (function == "system")
        {
            system(parameters.c_str());
        }
        else if (function == "Print")
        {
            csdkin << parameters;
            if (parameters == "%arg%")
            {

            }
            std::cout <<parameters;
        }

        else if (function == "machine-def")
        {

        }
        else {
           std::ifstream include("scripts/" + function + ".sdk");
           if (!include) {
               std::cout << "WARN: Function not in interpreter library. Checking for functions from the local script.\n"
                            "err: scripts\\" << function << ".sdk not found.\n";
               return;
           }
           else {
               std::string res;
                while (getline (include, res))
                {
                    SDKL_TEMPSTREAM << res << std::endl;
                }
                pexec_preset();

           }


        }
    }
    SDKL_SUBFUNCSTREAM.clear();

}
void parsestream()
{
    std::string keyword;
    SDKL_STREAM >> keyword;
    if (keyword == ".call" || keyword == "void")
    {
        std::string funcname;
        getline(SDKL_STREAM,funcname, '(');
        funcname.erase(std::remove_if(funcname.begin(), funcname.end(), isspace), funcname.end());
        std::string funcparams;
        getline(SDKL_STREAM,funcparams, ')');

        std::string statements;
        std::string statements_op;
        getline(SDKL_STREAM,statements_op, '{');
        getline(SDKL_STREAM,statements, '}');

        if (funcname == "main")
        {
            SDKL_SUBFUNCSTREAM << statements;//send the functions to the function stream.
            send_funcstream();//execute them

        }
        else
        {
            SDKL_INCLUSIONSTREAM << funcname;

        }
    }
}
void eval_function(const std::string& function)
{
    SDKL_FUNCTEMPSTREAM << function;
    send_funcstream();
}
#endif //SDK_L_READ_H
