#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <cctype>

using std::cout, std::cin, std::endl, std::ifstream, std::string, std::set;

bool lengthCheck(string s);
bool wordInSet(string s, set<string> dic);
string removeDigits(string s);
bool wordInSetAndNoNum(string s, set<string> dic);
bool notTwoWords(string s);

int main() {
    ifstream ifs("words.txt");
    string line;

    set<string> words;
    while(getline(ifs, line)) {
        words.insert(line);
    }

    string user_word;
    cout << "Enter Password: ";
    cin >> user_word;

    if (lengthCheck(user_word) && wordInSet(user_word, words) && wordInSetAndNoNum(user_word, words) && notTwoWords(user_word)){
        cout << "Password is valid";
    }
    else{
        cout << "Password is not valid";
    }

    return 0;
}

bool lengthCheck(string s){
    return (s.length() >= 8);
}

bool wordInSet(string s, set<string> dic){
    if (dic.find(s) == dic.end())
        return true;
    return false;
}

string removeDigits(string s){
    string return_s = "";
    for (char c: s)
        if (!isdigit(c))
            return_s += c; 
    return return_s;
}

bool wordInSetAndNoNum(string s, set<string> dic){
    s = removeDigits(s);
    return wordInSet(s, dic);
}

bool notTwoWords(string s){
    bool numAppeared = false;
    for (int i = 0; i < s.length(); i++){
        if (isdigit(s[i])){
            numAppeared = true;
            continue;
        }
        if (numAppeared && isalpha(s[i]))
            return false;
    }
    return true;
}