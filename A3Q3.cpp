#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBalanced(const string& str) {
    stack<char> stk;

    for (char ch : str) {
        if (ch == '(') {
            stk.push(ch);
        } else if (ch == ')') {
            if (stk.empty()) return false;
            stk.pop();
        }
    }

    return stk.empty();
}

int main() {
    string userInput;
    cout << "Please enter a string: ";
    getline(cin, userInput);

    if (isBalanced(userInput)) {
        cout << "\nBalanced\n";
    } else {
        cout << "\nNot Balanced\n";
    }

    return 0;
}
