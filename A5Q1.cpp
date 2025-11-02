#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int data){
			this->data=data;
			this->next=NULL;
		}
		Node(int data, Node* ptr){
			this->data=data;
			this->next=ptr;
		}
};
void display(Node* head){
	
	Node* temp=head;
	cout<<"head->";
	while(temp->next){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<temp->data<<"->";
	cout<<"x";
}
void InsertAtBeg(Node* &head,int val){
	Node* temp = new Node(val,head);
	head=temp;
	cout<<"\nLinked List after adding "<<val<<" in the beginning"<<endl;
	display(temp);
}
void InsertAtEnd(Node* head,int val){
	Node* temp = head;
	while(temp->next){
		temp=temp->next;
		
	}
	temp->next=new Node(val);
	cout<<"\nLinked List after adding "<<val<<" in the end"<<endl;
	display(head);
}
void InsertAfterVal(int vl, int val,Node* head){
    Node* temp = head;
    while(temp->data!=vl && temp->next!=NULL){
        temp=temp->next;
    }
    if(temp->next==NULL){
        temp->next = new Node(val);
    }
    else{
        Node* nd = new Node(val);
        nd->next = temp->next;
        temp->next=nd;
    }
    cout<<"\nLinked List after adding "<<val<<" after value "<<vl<<endl;
	display(head);

}
void delbeg(Node* &head){
    Node* temp=head;
    head=head->next;
    cout<<"\nLinked List after deleting from beginning "<<endl;
    delete temp;
	display(head);
}
void delend(Node* &head){
	Node* temp = head;
	if(!temp->next){
		head=NULL;
	}
	else{
		while(temp->next->next){
			temp=temp->next;
		}
		delete temp->next;
		temp->next=NULL;
	}
	cout<<"\nLinked List after deleting from end "<<endl;
    display(head);
	
}
void delnode(Node* &head,int val){
	Node* temp = head;
	if(!temp) return;
    while(temp->next!=NULL && temp->next->data!=val){
        temp=temp->next;
    }
	if(!temp->next) return;
	cout<<"\nLinked List after deleting "<<temp->next->data<<endl;
	temp->next=temp->next->next;
	display(head);
}
void tellpos(Node* &head,int val){
	int cnt=0;
	Node* temp = head;
	while(temp && temp->data!=val){
		temp=temp->next;
		cnt++;
	}
	cout<<"\nNode "<<val<<" is "<<cnt<<" position ahead of head ";
}
int main(){
	Node* head= new Node(10);
	head->next= new Node(20);
	Node* temp=head->next;
	temp->next=new Node(30);
	temp=temp->next;
	temp->next=new Node(40);
	temp=temp->next;
	temp->next=NULL;
	display(head);
	InsertAtBeg(head,60);
	InsertAtEnd(head,50);
    InsertAfterVal(30,45,head);
    delbeg(head);
	delend(head);
	delnode(head,45);
	tellpos(head,30);
    return 0;
}
