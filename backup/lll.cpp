#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

void evaluate(stack<int>& operands, stack<char>& operators);
int precedence(char op);
int calculate(string expression) {
    stack<int> operands;
    stack<char> operators;

    for (int i = 0; i < expression.size(); ++i) {
        if (isdigit(expression[i])) {
            int operand = 0;
            while (i < expression.size() && isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            operands.push(operand);
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                evaluate(operands, operators);
            }
            operators.push(expression[i]);
        } else if (expression[i] == '(') {
            operators.push(expression[i]);
        } else if (expression[i] == ')') {
            while (operators.top() != '(') {
                evaluate(operands, operators);
            }
            operators.pop();
        }
    }

    while (!operators.empty()) {
        evaluate(operands, operators);
    }

    return operands.top();
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

void evaluate(stack<int>& operands, stack<char>& operators) {
    int operand2 = operands.top();
    operands.pop();
    int operand1 = operands.top();
    operands.pop();
    char op = operators.top();
    operators.pop();
    if (op == '+') {
        operands.push(operand1 + operand2);
    } else if (op == '-') {
        operands.push(operand1 - operand2);
    } else if (op == '*') {
        operands.push(operand1 * operand2);
    } else if (op == '/') {
        operands.push(operand1 / operand2);
    }
}

int main() {
    string expression = "3 + 5 * (2 - 4)";
    int result = calculate(expression);
    cout << "Result: " << result << endl;
    return 0;
}
