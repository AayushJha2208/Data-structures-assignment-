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

void insertEl(Node*& root, int val){
    if(root == nullptr){
        root = new Node(val);
        return;
    }

    if(val == root->data){
        cout << "Duplicate not allowed\n";
        return;
    }

    if(val > root->data)
        insertEl(root->right, val);
    else
        insertEl(root->left, val);
}

Node* deleteEl(Node* root, int val){
    if(root == nullptr) return root;

    if(val < root->data)
        root->left = deleteEl(root->left, val);
    else if(val > root->data)
        root->right = deleteEl(root->right, val);
    else {
        if(root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp=root->right;
        Node* pre=nullptr;
        while(temp->left != nullptr){
            pre = temp;
            temp = temp->left;
        }
        root->data=temp->data;
        if(!pre) root->right=temp->right;
        else pre->left=temp->right;
        delete temp;
    }
    return root;
}

int maxDepth(Node* root){
    if(root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root){
    if(root == nullptr) return 0;
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    Node* root = nullptr;

    insertEl(root, 35);
    insertEl(root, 10);
    insertEl(root, 50);
    insertEl(root, 20);
    insertEl(root, 5);
    insertEl(root, 40);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    deleteEl(root, 10);

    cout << "After Deletion (10 removed): ";
    inorder(root);
    cout << endl;

    cout << "Maximum Depth: " << maxDepth(root) << endl;
    cout << "Minimum Depth: " << minDepth(root) << endl;

    return 0;
}
