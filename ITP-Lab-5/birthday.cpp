#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int n = 364;
    bool birthdayFlags[364]{};

    srand(time(0));
    int count = 0;
    while (true){
        count++;
        int birthday = (rand() % 364);
        if (birthdayFlags[birthday] == true){
            break;
        }
        else{
            birthdayFlags[birthday] = true;
        }
    }
    cout << "Tries: " << count << endl; 
}