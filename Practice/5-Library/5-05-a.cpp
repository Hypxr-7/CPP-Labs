#include <iostream>
#include <cstdlib>

int main(){
    // drand48() not on Windows :(

    auto getRandom = [](){ return rand(); };

    for (int i = 0; i < 100; ++i)
        std::cout << getRandom() << ' ';
    std::cout << '\n';

    return 0;
}