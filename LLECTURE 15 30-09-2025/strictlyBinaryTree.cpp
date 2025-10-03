#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val),left(NULL),right(NULL){}
};

bool isStrictlyBinaryTree(Node* root){
    if(!root) return true;
    if(!root->left && !root->right) return true;
    if(!root->left || !root->right) return false;
    return isStrictlyBinaryTree(root->left) && isStrictlyBinaryTree(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7); 

    if(isStrictlyBinaryTree(root)) cout<<"Yes";
    else cout<<"NO";
    return 0;
}