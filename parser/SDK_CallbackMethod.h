//
// Created by seymo on 3/30/2021.
//

#ifndef SDK_L_SDK_CALLBACKMETHOD_H
#define SDK_L_SDK_CALLBACKMETHOD_H

#include <vector>

/**
 * Implements a basic callback method.
 */
typedef class {
private:
    std::string namedef;
    std::vector<std::string>decls{};
    std::string operat;
public:
    void changeOperator(std::string operato) {
        operat = operato;
    }

} SDK_CALLBACK_DECL;

#endif //SDK_L_SDK_CALLBACKMETHOD_H
