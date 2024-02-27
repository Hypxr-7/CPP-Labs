#include <iostream>
#include <vector>

double percent_even(std::vector<int> v);

int main() {
    using  std::vector, std::cout, std::endl;

    vector<int> v1 = {6, 2, 9, 11, 3};
    cout << percent_even(v1) << endl; // should prints 40
    vector<int> v2 = {6, 2, 9, 11, 4};
    cout << percent_even(v2) << endl; // should prints 60
    vector<int> v3 = {1, 3, 5, 7, 9};
    cout << percent_even(v3) << endl; // should prints 0

    return 0;
}

double percent_even(std::vector<int> v){
    double count = 0;
    for (int i = 0; i < v.size(); i++){
        if (v[i]%2 == 0){
            count++;
        }
    } 

    return count/v.size()*100;
}