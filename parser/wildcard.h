//
// Created by seymo on 3/30/2021.
//

#ifndef SDK_L_WILDCARD_H
#define SDK_L_WILDCARD_H
#include "../parser/Sdk_Class.h"
#include "../parser/Sdk_State.h"
template<typename T>
class SDK_wildcard {
private:
    Sdk_State<T>States;
    Sdk_Class<T>Classes;
    void operator=(Sdk_State<T> * State) {
        States = State;
    }
    void operator=(Sdk_Class<T> * state) {
        Classes = state;
    }
};


#endif //SDK_L_WILDCARD_H
