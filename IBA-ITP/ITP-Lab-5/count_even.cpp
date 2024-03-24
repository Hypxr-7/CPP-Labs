#include <iostream>
using namespace std;

int main(){
    // initializing size of array
    cout << "Total numbers to be entered: ";
    int size;
    cin >> size;
    int numArray[size];

    // entering nums in array
    for (int i = 0; i < size; i++){
        cout << "Number: ";
        cin >> numArray[i];
    }

    // counting even nums in array      
    int evenCount = 0;
    for (int i = 0; i < size; i++){
        if (numArray[i] % 2 == 0){
            evenCount++;
        }
    }
    cout << "There are " << evenCount << " even numbers";
}