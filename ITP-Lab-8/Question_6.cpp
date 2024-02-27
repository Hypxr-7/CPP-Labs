#include <iostream>
#include <vector>

bool vector_eq(std::vector<int> v1, std::vector<int> v2);

int main(){
    using std::vector;

    // vector<int> v1 = {1, 2, 5, 9};
    vector<int> v1 = {23, 54, 78, 9, 12, 45};
    // vector<int> v1 = {-1, 45, -9, -34, 23, 10};

    // vector<int> v2 = {1, 2, 5, 9};
    vector<int> v2 = {23, 54, 78, 9, 12, 45};
    // vector<int> v2 = {-1, 45, -9, -34, 23, 10};

    std::cout << std::boolalpha << vector_eq(v1, v2);

    return 0;
}

bool vector_eq(std::vector<int> v1, std::vector<int> v2){
    if (v1.size() == v2.size()){
        for (int i = 0; i < v1.size(); i++){
            if (v1[i] != v2[i]){
                return false;
            }
        }
    }
    else{
        return false;
    }
    return true;
}