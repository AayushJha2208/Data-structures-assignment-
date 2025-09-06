#include <iostream>
#include <string>
#include <stack>
using namespace std;
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}
string infixToPostfix(const string& infix) {
    stack<char> stk;
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        }
        
        else if (ch=='(') {
            stk.push(ch);
        }
        else if (ch==')') {
            while (!stk.empty() && stk.top() != '(') {
                postfix += stk.top();
                stk.pop();
            }
            if (!stk.empty()) stk.pop();
        }
        else {
            while (!stk.empty() && precedence(stk.top()) >= precedence(ch)) {
                postfix += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }
    while (!stk.empty()) {
        postfix += stk.top();
        stk.pop();
    }

    return postfix;
}

int main() {
    string userInput;
    cout << "Please enter an infix expression: ";
    getline(cin, userInput);
    string postfix = infixToPostfix(userInput);
    cout << "\nPostfix: " << postfix << endl;

    return 0;
}
