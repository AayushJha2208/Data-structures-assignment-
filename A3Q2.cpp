#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string userInput;
    userInput="DataStructure";
    stack<char> stk;
    int n=userInput.length();
    int i;
    for(i=0;i<n;i++){
        stk.push(userInput[i]);
    }
    for(i=0;i<n;i++){
        userInput[i]=stk.top();
        stk.pop();
    }
    cout << "\nReversed String: " << userInput << endl;
    return 0;
}