#include <iostream>
#include <queue>
using namespace std;

int i = -1;

class stk {
public:
    queue<int> q;
    void Push(int el) {
        q.push(el);
        i++;
        for (int j = 0; j < i; j++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    int Pop() {
        if (q.empty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int el = q.front();
        q.pop();
        i--;
        return el;
    }
};


class stk2 {
public:
    queue<int> q1;
    queue<int> q2;

    void Push(int el) {
        q2.push(el);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int Pop() {
        if (q1.empty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int el = q1.front();
        q1.pop();
        return el;
    }
};

int main() {
    cout << "Testing stk (one queue):\n";
    stk s1;
    s1.Push(10);
    s1.Push(20);
    s1.Push(30);
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;

    cout << "\nTesting stk2 (two queues):\n";
    stk2 s2;
    s2.Push(100);
    s2.Push(200);
    s2.Push(300);
    cout << s2.Pop() << endl; 
    cout << s2.Pop() << endl; 
    cout << s2.Pop() << endl; 

    return 0;
}
