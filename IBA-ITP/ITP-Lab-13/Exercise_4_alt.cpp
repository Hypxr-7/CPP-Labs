#include <iostream>

using std::cout, std::endl;

bool is_smaller(char *s1, char *s2);
int stringLength(char *s);

int main() {
    char s1[] = "hello";
    char s2[] = "world";
    cout << is_smaller(s1, s2) << endl; // prints 1
    cout << is_smaller(s2, s1) << endl; // prints 0
    cout << is_smaller(s1, s1) << endl; // prints 0
    return 0;
}

bool is_smaller(char *s1, char *s2){
    int len1 = stringLength(s1);
    int len2 = stringLength(s2);
    int len = (len1 <= len2) ? len1 : len2;
    for (int i = 0; i < len; i++){
        if (*(s1+i) > *(s2+i)){
            return false;
        }
        else if (*(s1+i) < *(s2+i)){
            return true;
        }
    }
    return false;
}

int stringLength(char *s){
    int i = 0;
    while (*(s+i) != '\0'){
        i++;
    }
    return i;
}