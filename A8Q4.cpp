#include <iostream>
#include <climits>
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

bool isBSTUtil(Node* root, int minVal, int maxVal){
    if(root == nullptr) return true;

    if(root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

int main(){
    Node* root = new Node(40);
    root->left = new Node(30);
    root->right = new Node(50);
    root->left->left = new Node(20);
    root->left->right = new Node(35);

    if(isBSTUtil(root, INT_MIN, INT_MAX)) cout << "Tree is BST\n";
    else cout << "Tree is NOT BST\n";

    return 0;
}
