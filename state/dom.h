//
// Created by seymo on 3/30/2021.
//

#ifndef SDK_L_DOM_H
#define SDK_L_DOM_H
enum TREE {
    EPARSE,
    RVALUE,
    EVAL,
    SEND
};

enum SYMBOL {
    SDKCOMMENT,
    SDK,
    SDK_OPENBRACKET,
    SDK_CLOSEDBRACKET,
    SDK_STATEMENT,
    SDK_REGEX,
    SDK_EXPRESSION
};

# define SDK_COMMENTBEGIN                ">>"
# define SDK_BLOCKCOMMENT                ">>[["
# define SDK_BLOCKCOMMENTCLOSE           "]]<<"

#endif //SDK_L_DOM_H
