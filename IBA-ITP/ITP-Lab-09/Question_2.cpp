#include <iostream>
#include <vector>

using std::vector;

vector<int> notAlone(vector<int> v, int n);

int main(){
    vector<int> v1 = notAlone({1, 2, 3}, 2); // returns {1, 3, 3}
    vector<int> v2 = notAlone({1, 2, 3, 2, 5, 2}, 2); // returns {1, 3, 3, 5, 5, 2}
    vector<int> v3 = notAlone({3, 4}, 3); // returns {3, 4}

    for (int i = 0; i < v1.size(); i++){
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < v2.size(); i++){
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < v3.size(); i++){
        std::cout << v3[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

vector<int> notAlone(vector<int> v, int n){
   for (int i = 1; i < v.size()-1; i++){
    if (v[i] == n){
        if (v[i-1] > v[i+1]){
            v[i] = v[i-1];
        }
        else{
            v[i] = v[i+1];
        }
    }
   }
   return v;
}