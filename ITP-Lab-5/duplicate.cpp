#include <iostream>
using namespace std;

int main(){
    int size = 10;
    // hard coded int arrays
    // comment/uncomment to use 
    // int array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array[size] = {1, 2, 5, 8, 9, 7, 5, 10, 4, 3};

    // checking array
    bool isSame{};
    for (int i = 0; i < size; i++){
        for (int j = i+1; j < size; j++){
            if (array[i] == array[j]){
                isSame = true;
                break;
            }
        }
        if (isSame == true){
            break;
        }
    }

    if (isSame == true){
        cout << "True";
    }
    else{
        cout << "False";
    }
}