#include <iostream>
#include <cstdlib>

int main(){
    using namespace std;

    srand(time(0));

    int n;
    cout << "Enter Max Number: ";
    cin >> n;

    int freq_array[n] = {};

    for (int i = 0; i < 1000000; i++){
        int r_num = (rand() % n);
        freq_array[r_num]++;
    }

    for (int i = 0; i < n; i++){
        cout << i+1 << " appeared " << freq_array[i] << " times" << endl;
    }
}