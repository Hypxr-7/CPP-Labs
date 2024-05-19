#include <iostream>

template<std::size_t N>
struct Factorial{
    static constexpr std::size_t value  = N * Factorial<N-1>::value;
};

template<>
struct Factorial<0>{
    static constexpr std::size_t value = 1;
};

int main(){
    std::cout << "Factorial of 5 is " << Factorial<5>::value << '\n';
    std::cout << "Factorial of 0 is " << Factorial<0>::value << '\n';

    return 0;
}