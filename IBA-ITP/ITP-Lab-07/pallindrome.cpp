#include <iostream>
#include <string>

int main(){
    using namespace std;

    string word;
    cout << "Enter Word: ";
    cin >> word;

    bool isPallindrome = true;
    for (int i = 0; i < int(size(word)/2); i++){
        if  (word[i] != word[size(word)-i-1]){
            isPallindrome = false;
            break;
        }
    }

    if (isPallindrome){
        cout << "Word is Pallindrome" << endl;
    }
    else{
        cout << "Word is not Pallindrome" << endl;
    }

    return 0;
}