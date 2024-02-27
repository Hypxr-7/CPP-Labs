#include <iostream>
#include <cstdlib>

int main(){
    using namespace std;

    srand(time(0));

    int n;
    cout << "Enter Size of Array: ";
    cin >> n;

    int array[n] = {};  
    for (int i = 0; i < n; i++){
        array[i] = rand() % 100;
    }

    cout << "Before: " << endl;
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }

    for (int i = 0; i < n; i++){
        int min = array[i];
        int minIndex = -1;
        for (int j = i+1; j < n; j++){
            if (array[j] < min){
                min = array[j];
                minIndex = j;
            }  
        }
        if (minIndex != -1){
            int temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }
        
        
    }
    
    cout << endl << endl << "After:" << endl;
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }

    return 0;
}