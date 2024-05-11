#include <iostream>
#include <string>
#include <stack>

bool isInLanguage(const std::string& str){
    std::stack<int> stack;
    char push_word;
    char pop_word;
    for (const char& c : str){
        if ((tolower(c) == 'a') && stack.empty()) {
            push_word = 'a';
            pop_word = 'b';
        }
        if ((tolower(c) == 'b') && stack.empty()) {
            push_word = 'b';
            pop_word = 'a';
        }

        if (tolower(c) == push_word) stack.push(1);
        if (tolower(c) == pop_word) stack.pop();
    }

    return stack.empty();
}

int main(){
    std::cout << isInLanguage("ABABAB") << '\n';
    std::cout << isInLanguage("AAABBBB") << '\n';

    return 0;
}