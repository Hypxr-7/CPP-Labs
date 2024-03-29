#include <iostream>
#include <math.h>

using namespace std;

template <typename T>
T min3(T x, T y, T z){
    return min(min(x, y), z);
}

int main(){
    cout << min3(1, 2, 3) << endl;
    cout << min3(1.1, 0.1, 3.3) << endl;
    cout << min3('a', 'b', 'c') << endl;
    return 0;
}