#include <iostream>
#include <string>
#include <iomanip>

int main(){
    using namespace std;

    cout << "How many words will you enter: ";
    int wordCount;
    cin >> wordCount;

    int letterCount = 0, maxLetterCount = 0;
    string words[wordCount] = {};
    for (int i = 0; i < wordCount; i++){
        cout << "Enter word: ";
        cin >> words[i];
        for (int j = 0; j < size(words[i]); j++){
            letterCount++;
        }
        if (letterCount > maxLetterCount){
            maxLetterCount = letterCount;
        }
        letterCount = 0;
    }

    string starBar = "****";
    for (int i = 0; i < maxLetterCount; i++){
        starBar += "*";
    }

    cout << starBar << endl;
    for (int i = 0; i < wordCount; i++){
        cout << "* " << setw(maxLetterCount) << left << words[i] << " *" << endl;
    }
    cout << starBar << endl;

    return 0;
}