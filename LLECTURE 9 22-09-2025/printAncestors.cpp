#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val),left(NULL),right(NULL){}
};

bool printAncestors(Node* root,int val){
    if(!root) return false;
    if(root->data==val) return true;

    if(printAncestors(root->left,val)||printAncestors(root->right,val)){
        cout<<root->data<<" ";
        return true;
    }

    return false;
}

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    int val = 5;
    cout << "Ancestors of " << val << ": ";
    printAncestors(root, val);
    cout << endl;

    return 0;
}