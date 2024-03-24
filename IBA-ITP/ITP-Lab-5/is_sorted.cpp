#include <iostream>
using namespace std;

int main(){
    // different arrays and their size

    // double array[1] = {0};
    // int size = 1;
    double array[4] = {16.1, 12.3, 22.2, 14.4};
    int size = 4;
    // double array[6] = {1.5, 4.3, 7.0, 19.5, 25.1, 46.2};
    // int size = 6;

    // checking if sorted
    bool isSorted = true;
    for (int i = 0; i < size-1; i++){
        if (array[i] > array[i+1]){
            isSorted = false;
            break;
        }
    }
    if (isSorted == true){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
}