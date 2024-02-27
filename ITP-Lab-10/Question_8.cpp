#include <iostream>
#include <string>
#include <cctype>

using std::cin, std::cout, std::string;

bool isAnagram(string s1, string s2);
string removeNonAlpha(string s);
string sortString(string s);

int main(){
    cout << "Enter String 1: ";
    string s1;
    std::getline(cin, s1);
    cout << "Enter String 2: ";
    string s2;
    std::getline(cin, s2);
    
    cout << "They are " << (isAnagram(s1, s2) ? "same" : "different");

    return 0;
}

bool isAnagram(string s1, string s2){
    s1 = removeNonAlpha(s1);
    s2 = removeNonAlpha(s2);

    s1 = sortString(s1);
    s2 = sortString(s2);

    if (s1 == s2)
        return true;
    return false;
}

string removeNonAlpha(string s){
    string returnString = "";
    for (int i = 0; i < s.length(); i++)
        if (isalpha(s[i]))
            returnString += tolower(s[i]);
    return returnString;
}

string sortString(string s){
    int n = s.length();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (s[j] > s[j + 1]) {
                char temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    return s;
}