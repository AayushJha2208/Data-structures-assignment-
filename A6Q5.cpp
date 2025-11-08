#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

bool isCircular(Node* head){
    if(head == NULL) return false;
    Node* temp = head->next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }
    return (temp == head);
}

int main(){
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(5);
    
    // head->next->next->next->next->next = head; 

    if(isCircular(head))
        cout << "It is a Circular Linked List";
    else
        cout << "It is NOT a Circular Linked List";

    return 0;
}
