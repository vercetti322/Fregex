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
    Fregex::init_symbol_hash(Fregex::hash);

    for (const auto& pair : Fregex::get_hash()) 
    {
        std::cout << pair.first << " --> " << static_cast<int>(pair.second) << std::endl;
    }

    return 0;
}