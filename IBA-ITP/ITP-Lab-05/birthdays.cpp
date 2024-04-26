#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int n = 364;
    bool birthdayFlags[364];

    cout << "How many times shoud the experiment be repeated: ";
    int expCount;
    cin >> expCount;

    srand(time(0));
    int tryCount = 0, trySum = 0;
    for (int i = 0; i < expCount; i++){
        for (int i = 0; i < n; i++){
        birthdayFlags[i] = false;
        }
        while (true){
            tryCount++;
            int birthday = (rand() % 364);
            if (birthdayFlags[birthday] == true){
                break;
            }
            else{
                birthdayFlags[birthday] = true;
            }
        }
        trySum += tryCount;
        tryCount = 0;
    }
    cout << "Average Tries : " << double(trySum) / expCount << endl; 
}