#include <iostream>
#include <string>

int count_vowels(std::string s);

int main(){
    using namespace std;
    string s;
    cout << "Enter your string: ";
    getline(cin, s);
    int count = count_vowels(s);
    cout << "There were " << count << " vowels in your string" << endl;

    return 0;
}

int count_vowels(std::string s){
    int count = 0;
    for (int i = 0; i < s.size(); i++){
        if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u'){
            count++;
        }
    }
    return count;
}