#include <iostream>

template<typename T>
class IsVoid{
public:
    using ValueType = bool;
    static constexpr ValueType value = false;
};

template<>
class IsVoid<void>{
public:
    using ValueType = bool;
    static constexpr ValueType value = true;
};

template<>
class IsVoid<const void>{
public:
    using ValueType = bool;
    static constexpr ValueType value = true;
};

template<>
class IsVoid<volatile void>{
public:
    using ValueType = bool;
    static constexpr ValueType value = true;
};

template<>
class IsVoid<const volatile void>{
public:
    using ValueType = bool;
    static constexpr ValueType value = true;
};

int main(){
    std::cout << std::boolalpha
    << IsVoid<void>::value << "\n"
    << IsVoid<const void>::value << "\n"
    << IsVoid<volatile void>::value << "\n"
    << IsVoid<const volatile void>::value << "\n"
    << IsVoid<int>::value << "\n"
    << IsVoid<const double>::value << "\n"
    << IsVoid<volatile char>::value << "\n"
    << IsVoid<const volatile long long>::value << "\n"
    << IsVoid<void (*)(int, int)>::value << "\n";
}