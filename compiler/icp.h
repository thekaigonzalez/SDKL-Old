//
// Created by seymo on 3/31/2021.
//

#ifndef SDK_L_ICP_H
#define SDK_L_ICP_H

#include <string>
#include <iostream>
#include <cstring>
#include "../parser/SDK_CallbackMethod.h"
#include "../parser/compile.h"


SDK_CALLBACK_DECL compile(const std::string& code) {
    SDKL::Compiler<SDK_CALLBACK_DECL> *mycompiler;

    /**
     * Checks if the Beginning keyword is a comment.
     */
    if (code.substr(0, ' ') == ">>") return mycompiler->comment();
    /**
     * Checks if the beginning keyword is a Block comment.
     */
    else if (strcmp(code.substr(0, ' ').c_str(), ">>[[") != 0) return mycompiler->null();
    /**
     * Else, Continue.
     */
    else {
        std::string body = mycompiler->skipEntryPoints(code, ENTRY);

    }
}
#endif //SDK_L_ICP_H
