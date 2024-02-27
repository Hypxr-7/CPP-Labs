#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    srand(time(0));
    int num = (rand() % 100) + 1;
    int guess = -1;
    while (guess != num){
        cout << "Enter guess: ";
        cin >> guess;
        if (guess > num)
            cout << "Too High" << endl;
        if (guess < num)
            cout << "Too Low" << endl;
    } 
    cout << "Correct!" << endl;
}