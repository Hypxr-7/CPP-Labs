#include <iostream>
#include <cstdlib>

int main(){
    using namespace std;

    srand(time(0));

    int n;
    cout << "Enter Num of People: ";
    cin >> n;

    int found = 0;

    for (int j = 0; j < 1000; j++){

        int glass_initial[n] = {};
        int glass_return[n] = {};

        for (int i = 0; i < n; i++){
            glass_initial[i] = i;
            glass_return[i] = i;
        }

        for (int i = 0; i < n; i++){
            int swap_index = (rand() % (n-i) + i);
            int temp = glass_return[i];
            glass_return[i] = glass_return[swap_index];
            glass_return[swap_index] = temp;
        }

        bool match_found = false;
        for (int i = 0; i < n; i++){
            if (glass_initial[i] == glass_return[i]){
                match_found = true;
                break;
            }
        }

        if (match_found){
            found++;
        }
    }

    cout << found << " out of 1000 times same glass was found" << endl;

}