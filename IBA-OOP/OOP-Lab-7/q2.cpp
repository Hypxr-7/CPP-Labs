#include <iostream>

using namespace std;

template <typename T>
T sum(T *first, T *last){
    T sum = 0;
    for (T *p = first; p != last; p++)
        sum += *p;
    return sum;
}

// int main(){
//     int a[] = {1, 2, 3, 4, 5};
//     double b[] = {1.1, 2.2, 3.3, 4.4, 5.5};
//     cout << sum(a, a + 5) << endl;
//     cout << sum(b, b + 5) << endl;
//     return 0;
// }

int main() {
    int iarr[] = {1, 2, 3, 4, 5};
    double darr[] = {1.2, 2.3, 4.9, 5.1};
    cout << sum(iarr, iarr+5) << endl; // 15
    cout << sum(darr, darr+4) << endl; // 13.5
    return 0;
}