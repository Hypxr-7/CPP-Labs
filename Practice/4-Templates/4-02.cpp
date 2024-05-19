#include <iostream>
#include <cmath>

template <typename T>
T min3(T x, T y, T z){
    return std::min(std::min(x, y), z);
}

int main(){
    std::cout << "The min of 3, 5, 8 is << " << min3(3, 5, 8) << '\n';
    std::cout << "The min of 0.5, 0.9, 1.1 is << " << min3(0.5, 0.9, 1.1) << '\n';
    std::cout << "The min of d, f, a is << " << min3('d', 'f', 'a') << '\n';

    return 0;
}