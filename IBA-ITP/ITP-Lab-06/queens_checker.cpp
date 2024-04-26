#include <iostream>

int main(){
    using namespace std;
    
    int n;
    cout << "Enter Max Number: ";
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++){
        cout << "Enter Number: ";
        cin >> array[i];
    }

    bool isValid = true;
    for (int i = 0; i < n; i++){

        for (int j = 0; j < n; j++){

            if (i < j){

                if ( array[i] == array[j] ){
                    isValid = false;
                    break;
                }

                if ( array[i] - array[j] == j - i){
                    isValid = false;
                    break;
                }

                if (array[j] - array[i] == j - i){
                    isValid = false;
                    break;
                }
            }
        }

        if (!isValid){
            break;
        }
    }

    if (isValid){
        cout << "Legal Placement" << endl;
    }
    else{
        cout << "Illegal Placement" << endl;
    }

}