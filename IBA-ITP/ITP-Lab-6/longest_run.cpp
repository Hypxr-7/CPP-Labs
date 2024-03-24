#include <iostream>
using namespace std;

int main(){

    int nums[10] = {};
    for (int i = 0; i < size(nums); i++){
        cout << "Enter Number: ";
        cin >> nums[i];
    } 

    int current_num, max_repeat_num;
    int prev_num = nums[0], count = 1, max_count = 0;

    for (int i = 1; i < size(nums); i++){
        current_num = nums[i];

        if (current_num == prev_num){
            count++;
        }
        else{
            count = 1;
        }

        if (count > max_count){
            max_count = count;
            max_repeat_num = nums[i];
        }


        prev_num = current_num;
    }

    cout << "Longest Run: " <<max_count << " consecutive " << max_repeat_num << "s" << endl;

    return 0;
}