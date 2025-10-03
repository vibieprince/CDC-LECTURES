#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val),left(NULL),right(NULL){}
};

bool isCompleteBinaryTree(Node* root){
    queue<Node*> q;
    q.push(root);
    bool foundNull = false;

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(!curr) foundNull = true;

        else{
            if(foundNull) return false;
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return true;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    // root->left->right = new Node(5);
    root->right->left = new Node(6);
    // root->right->right = new Node(7);

    if(isCompleteBinaryTree(root)) cout<<"Yes";
    else cout<<"NO";
    return 0;
}