#include <iostream>
using namespace std;

int main(){
    //initializing array
    cout << "Enter size of array: ";
    int size;
    cin >> size;
    int array[size];
    cout << endl;
    for (int i = 0; i < size; i++){
        cout << "Enter number: ";
        cin >> array[i];
    }

    // loop for checking each value
    int oneCount = 0, maxOneCount = 0;
    bool previousOne = false;
    for (int i = 0; i < size; i++){
        // if previous value is also one inc counter
        if (array[i] == 1 && previousOne == true){
            oneCount++;
        }
        // else ini to 1
        else if (array[i] == 1){
            oneCount = 1;
            previousOne = true;
        }
        else{
            previousOne = false;
        }
        if (maxOneCount < oneCount){
            maxOneCount = oneCount;
        }
    }

    cout << "Max Consecutive Ones: " << maxOneCount << endl;
}