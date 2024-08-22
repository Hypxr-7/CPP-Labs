#include <stack>
#include <iostream>
#include <string>

std::string convertToPostfix(std::string infix);
bool isOperator(char c);
int precedence(char op);

int main() {
    // std::string infix = "( 2 + ( ( 3 + 4 )* ( 5 * 6 )))";
    std::string infix = "( ( ( 5 + ( 7 * ( 1 + 1 )))* 3 )+ ( 2 * ( 1 + 1 )))";
    std::cout << convertToPostfix(infix) << std::endl;

    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

std::string convertToPostfix(std::string infix) {
    std::stack<char> s;
    std::string postfix;
    if (infix.front() != '(' || infix.back() != ')') {
        infix = '(' + infix + ')';
    }
    for (char c : infix) {
        if (isdigit(c)) {
            postfix += c;
            postfix += ' ';
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (isOperator(c)) {
            while (!s.empty() && s.top() != '(' && precedence(c) <= precedence(s.top())) {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.pop(); // discard '('
        }
    }
    return postfix;
}
