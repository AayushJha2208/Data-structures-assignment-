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

int main(){
    DNode* dhead = new DNode(10);
    dhead->next = new DNode(20);
    dhead->next->prev = dhead;
    dhead->next->next = new DNode(20);
    dhead->next->next->prev = dhead->next;
    dhead->next->next->next = new DNode(10);
    dhead->next->next->next->prev = dhead->next->next;

    DNode* fp = dhead;
    DNode* sp = dhead;

    
    while(fp && fp->next){
        sp = sp->next;
        fp = fp->next->next;
    }
    if(fp == NULL) fp = sp->prev;
    else fp = sp;

    while(fp && sp && fp->data == sp->data){
        fp = fp->prev;
        sp = sp->next;
    }

    if(!fp && !sp) cout << "List is palindrome" << endl;
    else cout << "List is not palindrome" << endl;

    return 0;
}
