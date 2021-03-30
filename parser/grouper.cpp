//
// Created by seymo on 3/29/2021.
//

#include "pdef.h"
#include "regex.h"
#include "Sdk_State.h"


Sdk_Class<Sdk_State<int>>MyarrayClass{};


int main() {
    MyarrayClass.get(0).returnValue();
}