#include <iostream>
#include <string>
#include <cctype>

using std::cout, std::cin, std::string;

bool pallindrome(string s);

int main(){
    cout << "Enter Word: ";
    string word;
    cin >> word;
    cout << "The word " << (pallindrome(word) ? "is" : "is not") << " a pallindrome";

    return 0;
}

bool pallindrome(string s){
    if (s.length() <= 1){
        return true;
    }
    if (tolower(s[0]) != tolower(s[s.length()-1])){
        return false;
    }
    else{
        return pallindrome(s.substr(1, s.length()-2));
    }
}