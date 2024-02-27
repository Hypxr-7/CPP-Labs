#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    int level = 0;
    bool lvl_change = false;
    cout << "Enter Expression: ";
    getline(cin, str);

    for (char c: str){
        if (c == '('){
            level++;
            lvl_change = true;
        }
        else if (c == ')'){
            level--;
            lvl_change = true;
        }
        if (lvl_change){
            cout << "Level " << level << endl;
            lvl_change = false;
        }
        if (level < 0){
            break;
        }
    }

    if (level == 0){
        cout << "Well-bracketed expression" << endl;
    }
    else if (level > 0){
        cout << "Unmatched '('" << endl;
    }
    else{
        cout << "Unmatched ')'" << endl;
    }

    return 0;
}