#include <iostream>
#include <string>
using namespace std;

int main(){

    string str, word, l_word;
    string s_word = "A very long placeholder string for smallest string";
    cout << "Enter Sentence: ";
    getline(cin, str);
    bool prev_space = false;

    for (int i = 0; i < size(str) + 1; i++){
        char c;
        if (i < size(str)){
            c = str[i];
        }
        else{
            c = ' ';
        }

        if (c == ' ' && prev_space){

            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) && size(word) > size(l_word)) {
                l_word = word;
            }
            if (size(word) < size(s_word)) {
                s_word = word;
            }

            word = "";
            prev_space = false;
        }
        
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            word += c;
            prev_space = true;
        }
    }  

    cout << endl;
    cout << "Smallest Word: " << s_word << endl;
    cout << "Largest Word: " << l_word << endl;

    return 0;
}

