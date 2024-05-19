#include <iostream>

template<typename T>
T minimum(T value){
    return value;
}

template<typename T, typename... Args>
T minimum(T first, Args... rest){
    return std::min(first, minimum(rest...));
}

int main(){
    std:: cout << "The minimum of 6, 5, 4, 3, 2 is " << minimum(6, 5, 4, 3, 2) << '\n';
    std:: cout << "The minimum of 2.0, 1.0, 1.0, 0.5 is " << minimum(2.0, 1.0, 1.0, 0.5) << '\n';

    return 0;
}