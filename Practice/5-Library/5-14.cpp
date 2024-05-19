#include <iostream>
#include <iomanip>

template<typename T>
void output(std::ostream& os, T value){
    os << value;
}

template<typename T, typename... Args>
void output(std::ostream& os, T first, Args... rest){
    os << first;
    output(os, rest...);
}

int main(){
    // Output "Hello, World!\n".
    output(std::cout, "Hello, World!\n");

    // Output "1\n".
     output(std::cout, 1, "\n");

    // Output "Hello World!\n".
    output(std::cout, "Hello ", "World!", "\n");

    // Output "Testing***1***2***3\n"
    output(std::cout,
    std::setfill('*'),
    "Testing",
    std::setw(4), 1,
    std::setw(4), 2,
    std::setw(4), 3,
    "\n");

    return 0;
}