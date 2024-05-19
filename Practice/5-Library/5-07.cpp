#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> v1 {2, 4, 3, 6, 8};
    std::vector<int> v2 {8, 2, 8, 4, 6};

    if (std::all_of(v1.begin(), v1.end(), [](int a){ return a%2 == 0; }))
        std::cout << "All even\n";
    else
        std::cout << "All not even\n";

    if (std::all_of(v2.begin(), v2.end(), [](int a){ return a%2 == 0; }))
        std::cout << "All even\n";
    else
        std::cout << "All not even\n";

    return 0;
}