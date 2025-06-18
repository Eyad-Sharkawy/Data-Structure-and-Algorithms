//
// Created by eyadd on 2025-04-19.
//

#ifndef CALC_H
#define CALC_H
#include "Linked_Stack.hpp"

using namespace std;

bool piority(char c1, char c2) {
    if ((c1 == '(' ) || ((c1 == '*' || c1 == '/') && c2 != '(') || (c1 == '+' || c1 == '-') && (c2 != '(' && c2 != '/' && c2 != '*')) {
        return true;
    }

    return false;
}

string infix_to_postfix (const string &str) {
    Stack<char> ope;
    string result;
    result;

    for (size_t i = 0; i < str.size(); ++i) {
        if (isdigit(str.at(i))) {
            string temp;
            while (i < str.size() && isdigit(str.at(i))) {
                temp += str.at(i);
                ++i;
            }
            result = result + ' ' + temp;
            if (i >= str.size()) break;
        }

        if (str.at(i) == ')') {
            while (ope.get_top() != '(') {
                result = result + ' ' + ope.get_top();
                ope.pop();
            }
            ope.pop();
            continue;
        }
        if (!ope.empty() && piority(ope.get_top(), str.at(i)) && !isspace(str.at(i)) && ope.get_top() != '(') {
            result = result + ' ' + ope.get_top();
            ope.pop();
        }
        if (!isspace(str.at(i))) {
            ope.push(str.at(i));
        }
        }

    result.erase(result.begin());

    while (!ope.empty()) {
        result = result + ' ' + ope.get_top();
        ope.pop();
    }
    return result;
}

long expression_evaluation(string str) {
    Stack<long int> opa;

    for (size_t i = 0; i < str.size(); ++i) {
        if (isdigit(str.at(i))) {
            while (i < str.size() && isdigit(str.at(i))) {
                opa.push(str.at(i) - '0');
                ++i;
            }
            if (i >= str.size()) break;
        }
        switch (str.at(i)) {
            long num1, num2;

            case '+':
                opa.pop(num1);
                opa.pop(num2);
                opa.push(num1 + num2);
                ++i;
                break;

            case '-':
                opa.pop(num1);
                opa.pop(num2);
                opa.push(num1 - num2);
                ++i;
                break;

            case '*':
                opa.pop(num1);
                opa.pop(num2);
                opa.push(num1 * num2);
                ++i;
                break;

            case '/':
                opa.pop(num1);
                opa.pop(num2);
                opa.push(num1 / num2);
                ++i;
                break;
        }
    }

    return opa.get_top();
}
#endif //CALC_H
