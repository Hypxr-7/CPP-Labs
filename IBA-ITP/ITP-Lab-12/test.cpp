#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string replace_is(string s) {
    string temp;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'i' && s[i+1] == 's' && !isalpha(s[i-1]) && !isalpha(s[i+2])){
            temp += "is not";
            i++;
        }
        else{
            temp += s[i];
        }
    }
    return temp;
}

int main(){
    string s;
    getline(cin, s);
    cout << replace_is(s);
}