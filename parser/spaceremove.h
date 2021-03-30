//
// Created by seymo on 3/30/2021.
//

#ifndef SDK_L_SPACEREMOVE_H
#define SDK_L_SPACEREMOVE_H

#include <algorithm>
#include <string>
/**
 * Removes spaces of a string.
 * @param str
 */
void ridOfSpaces(std::string& str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}


#endif //SDK_L_SPACEREMOVE_H
