#include <iostream>
using namespace std;

int main(){
    // Taking string input
    cout << "Enter sentence: ";
    string words;
    getline(cin, words);    // for taking string with multiple words as input
    
    // generating the ---- bar
    string bars = "";
    for (int i; i <= words.length() + 1; i++){
        bars += "-";
    }

    // output the words in correct format
    cout << "+" << bars << "+" << endl;
    cout << "| " << words << " |" << endl;
    cout << "+" << bars << "+" << endl;
}