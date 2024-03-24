#include <iostream>
#include <string>
#include <cmath>

using std::cout, std::cin, std::endl, std::string;

int str_to_int(string s);

int main() {
    string s;
    while (cin >> s) {
        cout << str_to_int(s) << endl;
    }
    return 0;
}

int str_to_int(string s){
    int num = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] >= '0' && s[i] <= '9'){
            num += pow(10, s.size() - i - 1) * (s[i] - 48);
        }
        else if (s[i] == '-'){
            continue;
        }
        else{
            return 0;
        }
    }
    if (s[0] == '-'){
        return -num;
    }
    else{
        return num;
    }
}