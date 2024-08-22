#include <stack>
#include <iostream>
#include <string>
#include <cmath>

int evaluatePostfix(std::string expression);
int evaluateExpression(int num1, int num2, char op);
bool isOperator(char c);

int main() {
    // std::string expression = "1 2 3 4 5 * + 6 * * +";
    // std::string expression = "7 16 16 16 * * * 5 16 16 * * 3 16 * 1 + + +";
    std::string expression = "7 16 * 5 + 16 * 3 + 16 * 1 +";
    std::cout << "Answer: " << evaluatePostfix(expression) << '\n';

    return 0;
}

int evaluatePostfix(std::string expression) {
    std::stack<int> stk;

    for (int i = 0; i < expression.length(); ++i) {
        if (isdigit(expression[i])) {
            std::string str {expression[i]};
            while (expression[i+1] != ' ') {
                i++;
                str += expression[i];
            }
            int num = std::stoi(str);
            stk.push(num);
        }
        else if (isOperator(expression[i])) {
            int num1 = stk.top();
            stk.pop();
            int num2 = stk.top();
            stk.pop();

            stk.push(evaluateExpression(num1, num2, expression[i]));
        }
    }
    return stk.top();
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int evaluateExpression(int num1, int num2, char op) {
    int num;
    switch (op) {
    case '+':
        num = num1 + num2;
        break;
    case '-':
        num = num1 - num2;
        break;
    case '*':
        num = num1 * num2;
        break;
    case '/':
        num = num1 / num2;
        break;
    case '^':
        num = pow(num1, num2);
        break;
    }
    
    return num;
}
