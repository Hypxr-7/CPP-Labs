#include <iostream>
#include <cstdlib>

int main(){
    using namespace std;

    srand(time(0));
    int n;
    cout << "Enter Max Number: ";
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++){
        array[i] = i;
    }

    for (int i = 0; i < n; i++){
        int rand_index = (rand() % (n - i) + i);
        int temp = array[rand_index];
        array[rand_index] = array[i];
        array[i] = temp;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (array[j] == i){
                cout << "Q ";
            }
            else{
                cout <<  "* ";
            }
        }
        cout << endl;
    }

    cout << endl << "Array: " << endl;
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }

    return 0;
}