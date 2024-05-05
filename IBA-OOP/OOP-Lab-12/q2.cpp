#include "Stack.h"
#include <iostream>
#include <string>
#include <cmath>

int evaluatePostFixExpression(const std::string& exp);
int calculate(int op1, char operand, int op2);

int main(){
    std::string expression = "62+5*84/-";
    std::cout << evaluatePostFixExpression(expression) << '\n';

    return 0;
}

int evaluatePostFixExpression(const std::string& exp){
    Stack s;
    for (char c : exp){
        if (c >= '0' && c <= '9'){
            s.push(static_cast<char>(c - '0'));
        }
        else{
            s.push(static_cast<char>(calculate(static_cast<int>(s.pop()), c, static_cast<int>(s.pop()))));
        }
    }

    return static_cast<int>(s.pop());
}

int calculate(int op1, char operand, int op2){
    if (operand == '/') return op1 / op2;
    if (operand == '-') return op1 - op2;
    if (operand == '+') return op1 + op2;
    if (operand == '*') return op1 * op2;
    if (operand == '%') return op1 % op2;
    if (operand == '^') return static_cast<int>(pow(op1, op2));
    throw;
}
