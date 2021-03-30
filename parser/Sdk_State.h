/* Compiler State Definitions */

#ifndef SDK_L_SDK_STATE_H
#define SDK_L_SDK_STATE_H

#include <vector>
#include <string>
#include "Sdk_Class.h"
#include "../tokenizer/types.h"
/**
 * An SDK Parser Instance. For Parser Class Decorators view See also Below.
 * @see Sdk_Class.h
 * @tparam T
 */
template<typename T>
class Sdk_State {
private:

    Sdk_Class<T>Class;
    SDK_Type inner_value;
    SDK_Type returntype;
    T& operator=(T Temp) {
        inner_value = Temp;
    }
public:
    /**
     * Returns the private inner value
     * @return inner_value
     */
    T& returnValue() {
        return inner_value;
    }
    /**
     * Returns three. Useless feature.
     * @return 3
     */
    int run() {
        return 3;
    }
    /**
     * Lists Every Piece of the SDKClass.
     * @return
     */
    Sdk_Class<T>listAll() {
        return Class.ListAll();
    }
    /**
     * Gets the Return type of this State.
     * @return SDK_Type
     */
    SDK_Type getReturn() {
        return returntype;
    }
    /**
     * Sets the return type.
     * @brief The Previous API Doesn't allow changing in class definition, To change you must either make the function public, or use
     * setReturn() to set the return type to a specified value.
     * @param t
     * @return true if success
     */
    bool setReturn(SDK_Type t) {
        returntype = t;
        return true;
    };



};


#endif //SDK_L_SDK_STATE_H
