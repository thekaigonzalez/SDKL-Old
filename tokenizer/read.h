// Raw token system.
// Find Macros In /tokenizer/macros/macrodef.h
// Find Functions in /parser/pdef & /util/struct.h
#ifndef SDK_L_READ_H
#define SDK_L_READ_H

#include <cstring>
#include "../parser/wildcard.h"
#include "types.h"
#include "attrib.h"
#include "../state/cur.h"
class Function {
private:
    std::string contents;
public:
    explicit Function(const std::string& content) {
        contents = content;
    }
    std::string getParameters() {
        return contents.substr(contents.find('(')+1, contents.find(')');
    }
    void switchContent(const std::string& newcontent) {
        contents = newcontent;
    }
    std::string getName() {
        return contents.substr(0, contents.find('('));
    }
};
const std::vector<std::string>charDefaults{};
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
    if (code.find(';') != std::string::npos)
        std::cout << "Unexpected EOF When parsing. Expected ';' as EOS.\n";
    /**
     * If there's no callback methods
     * @see SDK.CallbackMethod<typename>
     */
    if (code.find('.') != std::string::npos)
        std::cout << "WARNING: No callback methods implemented. Nothing can be called.\n";
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
}

/**
 * Checks if the snippet given is a function (1), And Is an official SDK Function (2).
 * @param snippet
 * @return true if snippet given is a function and an official one.
 */
bool isActualFunction(const std::string& snippet) {
    if (snippet.find('(') != std::string::npos) {
        std::cout << "Function is not a valid function. Nor Is it a SDK.Func to begin with.\n";
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
}
void EvaluateFunctions(const std::string& snippet) {
    if (snippet.find('(') != std::string::npos) {
        std::cout << "Function is not a valid function. Nor Is it a SDK.Func to begin with.\n";
    }
    else {
        const std::string funcname = snippet.substr(0 , snippet.find('('));
        if (funcname == "assrt") {

        }
        else if (funcname == "memst") return true;
        else if (funcname == "doc") return true;
        else return false;
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
#endif //SDK_L_READ_H
