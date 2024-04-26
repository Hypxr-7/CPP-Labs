#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    // part a
    cout << "Enter: ";
    int num;
    cin >> num;

    cout << boolalpha << [&num]{return bool(num%2);}() << endl;


    //part b
    vector<int> v = {1, 3, 8, 6, 4, 5, 7, 2, 0, 9};
    vector<int> v2 = {1, 3, 5, 9};

    cout << boolalpha << ::all_of(v.cbegin(), v.cend(), [](int i) { return i % 2 == 1; }) << endl;
    cout << boolalpha << ::all_of(v2.cbegin(), v2.cend(), [](int i) { return i % 2 == 1; }) << endl;

    return 0;
}