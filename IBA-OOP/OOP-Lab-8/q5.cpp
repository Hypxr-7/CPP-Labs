#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void transform_quadratic(vector<int>& v, double a, double b, double c) {
    transform(v.begin(), v.end(), v.begin(), [&a, &b, &c] (int x) {return a * x * x + b * x + c;});
}

int main(){
    //part a
    int a, b, c;
    cin >> a >> b >> c;

//    auto ungabunga = ([&a, &b, &c] (int x) {return a * x * x + b * x + c;});
//
//    cout << ungabunga(1) << endl;
//    cout << ungabunga(2) << endl;

    // part b
    vector<int> v = {-2, -1, 0, 1, 2};

    transform_quadratic(v, a, b, c);
     for (auto c : v)
         cout << c << endl;





    return 0;
}