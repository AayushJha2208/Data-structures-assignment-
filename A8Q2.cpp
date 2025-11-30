#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* nodesearch(Node* root, int val) {
    if (root == nullptr || root->data == val) return root;
    if (val < root->data) return nodesearch(root->left, val);
    return nodesearch(root->right, val);
}

int findMax(Node* root){
    if (root == nullptr) return -1;
    while (root->right != nullptr) root = root->right;
    return root->data;
}

int findMin(Node* root){
    if (root == nullptr) return -1;
    while (root->left != nullptr) root = root->left;
    return root->data;
}

Node* successor(Node* root, Node* x){
    Node* succ;
    while(root != nullptr){
        if(x->data < root->data){
            succ = root;
            root = root->left;
        } else root = root->right;
    }
    return succ;
}

Node* predecessor(Node* root, Node* x){
    Node* pred;
    while(root != nullptr){
        if(x->data > root->data){
            pred = root;
            root = root->right;
        } else root = root->left;
    }
    return pred;
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    Node* r = nodesearch(root, 60);
    if (r != nullptr) cout << "Node Found" << endl;
    else cout << "Node not found" << endl;

    cout << "Maximum element: " << findMax(root) << endl;
    cout << "Minimum element: " << findMin(root) << endl;

    Node* temp = nodesearch(root, 60);

    Node* s = successor(root, temp);
    if(s) cout << "Successor of 60: " << s->data << endl;
    else cout << "No Successor exists" << endl;

    Node* p = predecessor(root, temp);
    if(p) cout << "Predecessor of 60: " << p->data << endl;
    else cout << "No Predecessor exists" << endl;

    return 0;
}
