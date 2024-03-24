#include <iostream>
#include <vector>

bool canBalance(std::vector<int> v);

int main(){
    using std::vector, std::cout;
    
    vector<int> v1 = {1, 1, 1, 2, 1};
    vector<int> v2 = {2, 1, 1, 2, 1};
    vector<int> v3 = {10, 10};

    cout << std::boolalpha << canBalance(v1) << std::endl;
    cout << std::boolalpha << canBalance(v2) << std::endl;
    cout << std::boolalpha << canBalance(v3) << std::endl;

    return 0;
}

bool canBalance(std::vector<int> v){
    int totalSum = 0;
    int leftSum = 0;

    for (int num : v) {
        totalSum += num;
    }

    for (int i = 0; i < v.size(); i++) {
        leftSum += v[i];
        if (leftSum == totalSum - leftSum) {
            return true;  
        }
    }

    return false; 
}
