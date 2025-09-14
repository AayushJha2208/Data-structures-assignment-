#include <iostream>
#include <queue>
using namespace std;

int main() {
    string str;
    cout << "Input string: ";
    cin >> str;
    char ch=' ';
    queue<char> q;
    string result = "";
    for (int i = 0; str[i] != '\0'; i++) {
        if(str[i]==ch){
            result+= "-1";
        }
        else if (q.empty()) {
            q.push(str[i]);
            result += str[i];
        }
        else if (q.front() == str[i]) {
            ch =q.front();
            q.pop();
            if(q.empty() && str[i]==ch) result += "-1";
            else result+=q.front();
        }
        else {
            result += q.front();
            q.push(str[i]);
        }
    }

    cout << "Output string: " << result << endl;
    return 0;
}
