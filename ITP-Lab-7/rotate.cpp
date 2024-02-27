#include <iostream>

int main(){
    using namespace std;

    cout << "Current Array: " << endl;
    int array[7] = {};
    for (int i = 0; i < size(array); i++){
        array[i] = i+1;
        cout << array[i] << " ";
    }
    cout << endl;

    int shift;
    cout << endl << "How may elements to shift by: ";
    cin >> shift;

    for (int i = 0; i < shift; i++){
        for (int j = 0; j < size(array)-1; j++){
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        }
    }
    
    cout << endl << "After Shifting: " << endl;
    for (int i = 0; i < size(array); i++){
        cout << array[i] << " ";
    }
}