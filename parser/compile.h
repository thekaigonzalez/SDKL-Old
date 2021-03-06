//
// Created by seymo on 3/31/2021.
//
# define sullptr_t                0

#ifndef SDK_L_COMPILE_H
#define SDK_L_COMPILE_H
#include <typeinfo>
#include <vector>
#include "../parser/parse.h"
#include "../tokenizer/types.h"
template<typename T>
class BaseCompilerProfile {
public:
    /**
* Returns a Corrected SDK DataType Holding Statement Return Information.
* @param code
*/
    SDK_Type eval(const std::string &code) {
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
         * IF the statement hasn't ended
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
    std::string getFirstKeyword(const std::string &code) {
        return code.substr(0, ' ');
    }

/**
 * app:help() => app:help
 * @param code
 * @param ignoreSpaces
 * @return
 */
    std::string getBeforeFunction(const std::string &code, bool ignoreSpaces) {

    }

/**
 * app:help() => app
 * @param code
 * @return
 */
    std::string getDataTable(const std::string &code) {
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
    bool isCallbackMethod(const std::string &snippet) {
        std::string first = getFirstKeyword(snippet);
        if (strcmp(".", first.c_str()) != 0) {
            if (first.find('(') != std::string::npos) {
                std::cout << "Function is not a callback method or a valid function. Returning.\n";
                return false;
            } else {
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
    bool isActualFunction(const std::string &snippet) {
        if (snippet.find('(') != std::string::npos) {
            std::cout << "Function is not a valid function. Nor Is it a SDK.Func to begin with.\n";
        } else {
            const std::string funcname = snippet.substr(0, snippet.find('('));
            if (funcname == "assrt") {
                return true;
            } else if (funcname == "memst") return true;
            else if (funcname == "doc") return true;
            else return false;
        }
    }

    void EvaluateFunctions(const std::string &snippet) {
        if (snippet.find('(') == std::string::npos) {
            std::cout << "\nFunction is not a valid function. Nor Is it a SDK.Func to begin with.\n";
        } else {
            std::string statement = snippet.substr(0, snippet.find(';'));
// If the EOL Is unavailable.
            if (snippet.find(';') == std::string::npos) return;
            while (statement == snippet.substr(snippet.find(';'))) {
                unsigned functionpos = statement.find('(');
                unsigned functionbodybeginpos = statement.find('(') + 1;
                unsigned functionbodypos = statement.find(')');
                std::string function = statement.substr(0, functionpos);
                std::string functionbody = statement.substr(functionbodybeginpos, functionbodypos);
                if (function == "hello") {
                    std::cout << "world! Body: " << functionbody;

                } else if (function == "end") {
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
    void run(const std::string &script) {
        /**
         * Checks if the script has a `main` Entry point.
         * Usually defined as .call main(), In the standard.
         */
        if (script.substr(0, '(') == ".call main") {
            // Now we write our code
            const std::string statement = script.substr(script.find('{') + 1, script.find('}'));

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
    bool IsNullValue(const std::string &DWORD) {
        if (DWORD.substr(0, ' ') == "null" || DWORD.substr(0, ' ') == "nil")
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
    std::string skipEntryPoints(const std::string &code, SDK_Postype Position) {
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
            main = code.substr(firstx, lastx - firstx);
            ridOfSpaces(main);

            if (main == "main") {

                // gets the statements
                unsigned firstxf = code.find('{');
                unsigned lastxf = code.find('}');
                statements = code.substr(firstxf, lastxf);
            }

        } else if (entry == "win") {
            // checks if it's the main() branch.
            unsigned firstx = code.find(' ');
            unsigned lastx = code.find('(');
            unsigned et = code.find('(');
            unsigned etx = code.find(')');

            main = code.substr(firstx, lastx - firstx);
            ridOfSpaces(main);
            if (main == "wdls") {

                // gets the statements
                unsigned firstxf = code.find('{');
                unsigned lastxf = code.find('}');
                statements = code.substr(firstxf, lastxf);
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

/**
 * Returns the true parameters of first instance of SDK.Function().
 *
 * @param code
 * @return
 */
    std::string getTrueParameters(const std::string &code) {
        unsigned firstx = code.find('(') + 1;
        unsigned lastx = code.find(')');
        return code.substr(firstx, lastx - firstx);
    }
};
namespace SDKL {


    template<typename C>
    class Compiler : public BaseCompilerProfile<std::string>{
    private:
        int direct{};
        char32_t cha{};
        C DIR;
        std::vector<C> *NewList{};
        SDK_CALLBACK_DECL decl;
        SDK_CALLBACK_DECL cmnt;
        SDK_CALLBACK_DECL nullptrt;
        SDK_CALLBACK_DECL fullptr;

    public:
        C type;

        void ssdDi(C newvalue) {
            DIR = newvalue;
        }

        C languageImplements() {
            return typeid(C);
        }

        C addListDir(C T) {
            NewList->push_back(T);
        }

        SDK_CALLBACK_DECL comment() {
            return cmnt;
        }

        int keyword() {
            return 2;
        }

        SDK_CALLBACK_DECL null() {
            return nullptrt;
        }


    };

}

#endif //SDK_L_COMPILE_H
