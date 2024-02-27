#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>

using std::cout, std::cin, std::endl, std::ifstream, std::string, std::map;

int commaPosn(string s);


int main(){
    map<string, string> rep_words;

    ifstream ifs("misspellings.txt");

    string word;

    while(getline(ifs, word)){

        int comma_posn = commaPosn(word);
        
        string mis_word = word.substr(0, comma_posn);
        string cor_word = word.substr(comma_posn+1, word.length()-comma_posn);
        cout << mis_word << " " << cor_word << endl;
        rep_words[mis_word] = cor_word;

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

int commaPosn(string s){
    int i = 0;
    while (s[i] != ','){
        i++;
    }
    return i;
}