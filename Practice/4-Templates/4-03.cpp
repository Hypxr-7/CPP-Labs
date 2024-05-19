#include <iostream>
#include <numeric>

template<typename T>
T sum(T* it_begin, T* it_end){
    T init{};
    return std::accumulate(it_begin, it_end, init);
}

int main(){
    const int i[5] = {1, 2, 3, 0, 1};
    const double d[3] = {1.0, 2.0, 3.3};

    std::cout << sum(&i[0], &i[5]) << "\n";
    std::cout << sum(&d[0], &d[3]) << "\n";

    return 0;
}