#include <iostream>
#include <string>
#include <cctype>

using std::cout, std::cin, std::string;

string removeX(string s);

int main(){
    cout << "Enter string: ";
    string s;
    std::getline(cin, s);
    cout << "Final string: " << removeX(s);

    return 0;
}

string removeX(string s) {
    if (s == "") 
        return "";
    if (s[0] == 'x')
        return removeX(s.substr(1));
    return s[0] + removeX(s.substr(1));
}