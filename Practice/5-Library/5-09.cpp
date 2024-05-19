#include <iostream>
#include <vector>
#include <algorithm>

int count_even(const std::vector<int>& v){
    int count = 0;
    std::for_each(v.begin(), v.end(), [&count](int n){
        if (n % 2 == 0)
            ++count;
    });
    return count;
}



int main(){
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "There are " << count_even(v) << " even numbers in this vector\n";

    return 0;
}
