/*
* Author: Jatin Jindal
* Github: vercetti322
* 
* The main entry point of the program where regex will be
* parsed against the tokens to get correct pairs.
*/

#include "FregAlgo.h"
#include "FregStructs.h"

int main() {
    std::cout << "Init build successful!!" << std::endl;
    std::string regex = "((((b)|((a)(b)))+)|((((b)|((a)(b)))*)(a)))";
    Fregex::insert_explicit_concat(regex);
    std::cout << regex << std::endl;
    std::string postfix = Fregex::infix_to_postfix(regex, Fregex::operand_set);
    std::cout << postfix << std::endl;
    return 0;
}