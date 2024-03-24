#include <iostream>

using std::cout;

using IntPtrType = int*;

int main(){

    IntPtrType ptr_a = nullptr, ptr_b = nullptr;
    IntPtrType *ptr_c = nullptr;

    ptr_a = new int;
    *ptr_a = 3;
    ptr_b = ptr_a;
    cout << *ptr_a << " " << *ptr_b << "\n";
    // 3 3

    ptr_b = new int;
    *ptr_b = 9;
    cout << *ptr_a << " " << *ptr_b << "\n";
    // 3 9

    *ptr_b = *ptr_a;
    cout << *ptr_a << " " << *ptr_b << "\n";
    // 3 3

    delete ptr_a;
    ptr_a = ptr_b;
    cout << *ptr_a << " " << *&*&*&*&*ptr_b << "\n";

    ptr_c = &ptr_a;
    cout << *ptr_c << " " << **ptr_c << "\n";

    delete ptr_a;
    ptr_a = nullptr;

    return 0;
}