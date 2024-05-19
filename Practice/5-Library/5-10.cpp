#include <iostream>
#include <vector>
#include <algorithm>

int find_first_negative(const std::vector<int>& v){
    auto it = std::find_if(v.begin(), v.end(), [](int n){ return n < 0; });

    return (it != v.end()) ? static_cast<int>(std::distance(v.begin(), it)) : -1;
}

int main(){
    std::vector<int> v {1, 2, 3, 4, -2, 6, 7, 8, 9};

    std::cout << "Negative number at index " << find_first_negative(v);

    return 0;
}