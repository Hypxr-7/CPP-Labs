#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>

#include "RightLeaningRedBlackBST.hpp"

// Make sure to uncomment the assert(check()) in RightLeaningRedBlackBST.hpp at line 142 and line 177 when running tests
// Comment it again for general use to prevent slow execution

int main() {
    RightLeaningRedBlackBST<int, std::string>::testRightLeaningRedBlackBST();
    std::cout << "All tests passed\n";

    return 0;
}
