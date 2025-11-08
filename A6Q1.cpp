#include <iostream>
using namespace std;

/********** CIRCULAR LINKED LIST **********/
class CNode{
public:
    int data;
    CNode* next;
    CNode(int val){
        data = val;
        next = NULL;
    }
};

CNode* chead = NULL;

void displayCLL(){
    if(chead == NULL){
        cout << "List is empty\n";
        return;
    }
    CNode* temp = chead;
    cout << "head->";
    do{
        cout << temp->data << "->";
        temp = temp->next;
    }while(temp != chead);
    cout << "head\n";
}

void insertCLL(int pos, int val){
    CNode* newNode = new CNode(val);

    if(chead == NULL){
        newNode->next = newNode;
        chead = newNode;
        return;
    }

    if(pos == 1){
        CNode* temp = chead;
        while(temp->next != chead)
            temp = temp->next;
        newNode->next = chead;
        temp->next = newNode;
        chead = newNode;
        return;
    }

    CNode* temp = chead;
    for(int i = 1; i < pos - 1 && temp->next != chead; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteCLL(int val){
    if(chead == NULL){
        cout << "List empty\n";
        return;
    }

    CNode* temp = chead;
    CNode* prev = NULL;

    if(chead->data == val){
        while(temp->next != chead)
            temp = temp->next;
        temp->next = chead->next;
        CNode* del = chead;
        chead = chead->next;
        delete del;
        cout << "Node Deleted\n";
        return;
    }

    temp = chead;
    do{
        prev = temp;
        temp = temp->next;
        if(temp->data == val){
            prev->next = temp->next;
            delete temp;
            cout << "Node Deleted\n";
            return;
        }
    }while(temp != chead);

    cout << "Node not found\n";
}

void searchCLL(int val){
    if(chead == NULL){
        cout << "List empty\n";
        return;
    }
    CNode* temp = chead;
    int pos = 1;
    do{
        if(temp->data == val){
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }while(temp != chead);
    cout << "Not found\n";
}


/********** DOUBLY LINKED LIST **********/
class DNode{
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val){
        data = val;
        prev = next = NULL;
    }
};

DNode* dhead = NULL;

void displayDLL(){
    if(dhead == NULL){
        cout << "List is empty\n";
        return;
    }
    DNode* temp = dhead;
    cout << "NULL<->";
    while(temp != NULL){
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void insertDLL(int pos, int val){
    DNode* newNode = new DNode(val);

    if(pos == 1){
        newNode->next = dhead;
        if(dhead) dhead->prev = newNode;
        dhead = newNode;
        return;
    }

    DNode* temp = dhead;
    for(int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    newNode->next = temp->next;
    if(temp->next) temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteDLL(int val){
    if(dhead == NULL){
        cout << "List empty\n";
        return;
    }

    DNode* temp = dhead;

    if(temp->data == val){
        dhead = temp->next;
        if(dhead) dhead->prev = NULL;
        delete temp;
        cout << "Node Deleted\n";
        return;
    }

    while(temp && temp->data != val)
        temp = temp->next;

    if(temp == NULL){
        cout << "Not found\n";
        return;
    }

    if(temp->next) temp->next->prev = temp->prev;
    if(temp->prev) temp->prev->next = temp->next;
    delete temp;
    cout << "Node Deleted\n";
}

void searchDLL(int val){
    DNode* temp = dhead;
    int pos = 1;
    while(temp != NULL){
        if(temp->data == val){
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found\n";
}


/********** MAIN MENU **********/
int main(){
    int choice, val, pos, listType;

    while(true){
        cout << "\nChoose Linked List Type:\n1. Circular LL\n2. Doubly LL\n3. Exit\n";
        cin >> listType;

        if(listType == 3) break;

        while(true){
            cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Back to Main Menu\n";
            cin >> choice;

            if(choice == 5) break;

            switch(choice){
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    cout << "Enter position: ";
                    cin >> pos;
                    if(listType == 1) insertCLL(pos, val);
                    else insertDLL(pos, val);
                    break;

                case 2:
                    cout << "Enter value to delete: ";
                    cin >> val;
                    if(listType == 1) deleteCLL(val);
                    else deleteDLL(val);
                    break;

                case 3:
                    cout << "Enter value to search: ";
                    cin >> val;
                    if(listType == 1) searchCLL(val);
                    else searchDLL(val);
                    break;

                case 4:
                    if(listType == 1) displayCLL();
                    else displayDLL();
                    break;

                default:
                    cout << "Invalid\n";
            }
        }
    }
    return 0;
}
