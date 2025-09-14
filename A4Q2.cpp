#include <iostream>
using namespace std;

int fr = -1, rr = -1;

class Queue {
    int q[5];

public:
    void enqueue() {
        if (isFull()) {
            cout << "OVERFLOW!!" << endl;
            return;
        }
        int val;
        cout << "Enter the value to insert in the queue: ";
        cin >> val;
        if (fr == -1) fr = 0;
        rr++;
        q[rr%5] = val;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "UNDERFLOW!!" << endl;
            return;
        }
        int val = q[fr%5];
        cout << "Removed element is " << val << endl;
        fr++;
        return;
    }
    bool isFull(){
        if(rr-fr == 4){
            return 1;
        }
        return 0;

    }
    bool isEmpty(){
        if(fr == -1 || fr > rr) return 1;
        return 0; 
    }
    void display(){
        if(isEmpty()){
            cout<<"No elements"<<endl;
            return;
        }
        cout<<"\nfront end"<<endl;
        for(int i=fr;i<=rr;i++){
            cout<<q[i%5]<<endl;
        }
        cout<<"rear end"<<endl;
    }
    void peek(){
        if(isEmpty()){
            cout<<"No elements"<<endl;
            return;
        }
        cout<<q[fr%5]<<endl;
    }
    


};

int main() {
    Queue q;
    int ch;

    do {
        cout << "\n-------MENU-------" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Full Check" << endl;
        cout << "4. Empty Check" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: q.enqueue(); break;
            case 2: q.dequeue(); break;
            case 3: 
                if(q.isFull()) cout<<"Queue is full"<<endl;
                else cout<<"Queue not Full"<<endl;
                break;
            case 4: 
                if(q.isEmpty()) cout<<"Queue is empty"<<endl;
                else cout<<"Queue not empty"<<endl;
                break;
            case 5: q.display(); break;
            case 6: q.peek(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n"; break;
        }

    } while (ch != 7);

    return 0;
}