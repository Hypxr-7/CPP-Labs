#include <iostream>
#include <string>
using namespace std;

int main(){
    // size of array
    cout << "Enter length of array: ";
    int size;
    cin >> size;
    string stringArray[size];

    // initializing array
    cout << endl;
    for (int i = 0; i < size; i++){
        cout << "Enter word: ";
        cin >> stringArray[i];
    }

    // display current array
    cout << endl << "Initial Array: " << endl;
    for (int i = 0; i < size; i++){
        cout << stringArray[i] << endl;
    }

    // reversing array
    for (int i = 0; i < size/2; i++){
        string temp = stringArray[i];
        stringArray[i] = stringArray[size-i-1];
        stringArray[size-i-1] = temp; 
    }
    // display reverse array
    cout << endl << "Reversed Array: " << endl;
    for (int i = 0; i < size; i++){
        cout << stringArray[i] << endl;
    }
}