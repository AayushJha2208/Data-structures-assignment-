#include <iostream>
#include <string>
#include <stack>
using namespace std;

int evaluatePostfix(const string& postfix) {
    stack<int> stk;
    for (char ch : postfix) {
        if (ch >= '0' && ch <= '9') {
            stk.push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int val2 = stk.top(); stk.pop();
            int val1 = stk.top(); stk.pop();
            switch (ch) {
                case '+': stk.push(val1 + val2); break;
                case '-': stk.push(val1 - val2); break;
                case '*': stk.push(val1 * val2); break;
                case '/': stk.push(val1 / val2); break;
            }
        }
    }
    return stk.top();
}

int main() {
    string userInput;
    cout << "Please enter a postfix expression: ";
    getline(cin, userInput);

    int ans = evaluatePostfix(userInput);
    cout << "\nPostfix evaluation: " << ans << endl;
    return 0;
}
