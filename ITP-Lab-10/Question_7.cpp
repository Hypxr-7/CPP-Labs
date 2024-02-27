#include <iostream>
#include <string>
#include <cctype>

using std::cout, std::string;

bool isValid(string s);
bool lengthCheck(string s);
bool digitLetterCheck(string s);
bool minDigitCheck(string s);
bool minLetterCheck(string s);

int main(){
    cout << "Enter Password: ";
    string password;
    getline(std::cin, password);
    cout << "Password is " << (isValid(password) ? "valid" : "invalid");

    return 0;
}

bool isValid(string s){
    if (lengthCheck(s) && digitLetterCheck(s) && minDigitCheck(s) && minLetterCheck(s))
        return true;
    return false;
}

bool lengthCheck(string s){
    if (s.length() >= 10)
        return true;
    return false;
}

bool digitLetterCheck(string s){
    for (int i = 0; i < s.length(); i++)
        if (!isalnum(s[i]))
            return false;
    return true;
}

bool minDigitCheck(string s){
    int count = 0;
    for (int i = 0; i < s.length(); i++){
        if (isdigit(s[i])){
            count++;
            if (count >= 2)
                return true;
        } 
    }
    return false;
}

bool minLetterCheck(string s){
    for (int i = 0; i < s.length(); i++)
        if (isalpha(s[i]))
            return true;
    return false;
}