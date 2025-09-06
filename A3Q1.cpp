#include <iostream>
using namespace std;
int i = 0;
class stack
{
public:
    int stk[5];
    int el;
    void push()
    {
        cout << "\nEnter element: ";
        cin >> el;
        stk[i] = el;
        i++;
    }
    void pop()
    {
        i = i - 1;
    }
    bool isEmpty()
    {
        if (i == 0)
        {
            return 1;
        }
        return 0;
    }
    bool isFull()
    {
        if (i == 5)
        {
            return 1;
        }
        return 0;
    }
    void display()
    {
        int j = i - 1;
        while (j > -1)
        {
            cout << "\n"
                 << stk[j];
            j--;
        }
    }
    void peek()
    {
        cout << "\nPeak Element: " << stk[i - 1];
    }
};
int main()
{
    char nex = 'y';
    while (nex == 'y' || 'Y')
    {
        cout << "\n-------MENU-------";
        cout << "\n1)PUSH";
        cout << "\n2)POP";
        cout << "\n3)ISEMPTY";
        cout << "\n4)ISFULL";
        cout << "\n5)DISPLAY";
        cout << "\n6)PEEK";
        int ch = 0;
        cout << "\nEnter your choice (1-6)";
        cin >> ch;
        stack stk;
        switch (ch)
        {
        case 1:
            if (stk.isFull())
            {
                cout << "\nOVERFLOW!!";
                break;
            }
            stk.push();
            break;
        case 2:
            if (stk.isEmpty())
            {
                cout << "\nUNDERFLOW!!";
                break;
            }
            stk.pop();
            break;
        case 3:
            stk.isEmpty();
            break;
        case 4:
            stk.isFull();
            break;
        case 5:
            stk.display();
            break;
        case 6:
            if (stk.isEmpty())
            {
                cout << "\nUNDERFLOW!!";
                break;
            }
            stk.peek();
            break;
        default:
            cout << "\n invalid input";
            break;
        }
        cout << "\nDo you want more operations(y/n)? ";
        cin >> nex;
    }
}