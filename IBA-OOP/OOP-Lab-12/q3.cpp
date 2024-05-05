#include "Stack.h"
#include <iostream>
#include <string>

std::string convertToPostfix(std::string infix);
bool isOperator(char c);
int precedence(char op);

int main() {
    std::string infix = "(6 + 2) * 5 - 8 / 4";
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
    Stack s;
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
