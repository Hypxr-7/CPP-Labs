#include <iostream>
#include <stack>

bool wellBracketed(std::string str);

int main() {
    // std::string brackets = "[()]{}{[()()]()}";
    std::string brackets = "[(])";
    std::cout << std::boolalpha << wellBracketed(brackets) << '\n';

    return 0;
}

bool wellBracketed(std::string str) {
    std::stack<char> stk;
    for (auto c : str) {
        if (c == '[' || c == '{' || c == '('){
            stk.push(c);
        }
        if (c == ']' || c == '}' || c == ')') {
            if (stk.empty()) {
                break;
            }
            char cur_c = stk.top();
            stk.pop();
            if (c == ']' && cur_c == '['){
                break;
            }
            else if (c == '}' && cur_c == '{') {
                break;
            }
            else if (c == ')' && cur_c == '(') {
                break;
            }
        }
    }
    return !stk.empty(); 
}