#include <iostream>

template<typename T>
T sum(T value){
    return value;
}

template<typename T, typename... Args>
T sum(T first, Args... rest){
    return first + sum(rest...);
}

int main(){
    std::cout << "The sum of 1, 2, 4 is " << sum(1, 2, 4) << '\n';
    std::cout << "The sum of 2.0, 1.0, 1.0, 0.5 is " << sum(2.0, 1.0, 1.0, 0.5) << '\n';

    return 0;
}