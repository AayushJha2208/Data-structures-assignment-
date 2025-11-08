
#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode *prev, *next;
    DNode(int val){
        data = val;
        prev = next = NULL;
    }
};

int sizeDoubly(DNode* head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val){
        data = val;
        next = NULL;
    }
};

int sizeCircular(CNode* head){
    if(head == NULL) return 0;
    int count = 0;
    CNode* temp = head;
    do{
        count++;
        temp = temp->next;
    }while(temp != head);
    return count;
}

int main(){

    DNode* dhead = new DNode(10);
    dhead->next = new DNode(20);
    dhead->next->prev = dhead;

    cout << sizeDoubly(dhead) << endl;

    CNode* chead = new CNode(5);
    chead->next = new CNode(15);
    chead->next->next = chead;

    cout << sizeCircular(chead) << endl;

    return 0;
}
