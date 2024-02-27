#include <iostream>
#include <fstream>
#include <map>
#include <string>

using std::cout, std::cin, std::endl, std::ifstream, std::string, std::map;



int main(){
    map<string, string> rep_words;

    ifstream ifs("misspell.txt");

    string mis_word;
    string cor_word;
    
    while(ifs >> mis_word >> cor_word){
        rep_words[mis_word] = cor_word;
        // cout << mis_word << " " << cor_word << "\n";
    }

    string user_word;
    cout << "Enter word: ";
    cin >> user_word;

    if (rep_words.find(user_word) == rep_words.end()){
        cout << "Word is correct or does not have a replacement";
    }
    else{
        cout << rep_words[user_word];
    }

    return 0;
}