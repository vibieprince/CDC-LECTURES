#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val):data(val),left(NULL),right(NULL){}
};


// 1st approach
void levelorderTraversal(Node* root){
    if(!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr==NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<curr->data<<" ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }  
    }
}

// 2nd approach 
void levelOrderTraversal(Node* root){
    if(!root) return;

    queue<Node*> q1,q2;
    q1.push(root);

    while(!q1.empty()){
        Node* curr = q1.front();
        q1.pop();

        cout<<curr->data<<" ";
        if(curr->left) q2.push(curr->left);
        if(curr->right) q2.push(curr->right);

        if(q1.empty()){
            cout<<endl;
            swap(q1,q2);
        }
    }
}

int main() {
    // Build the following binary tree:
    //          1
    //        /   \
    //       2     3
    //      / \   / \
    //     4   5 6   7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    levelorderTraversal(root);
    cout<<endl;
    levelOrderTraversal(root);

    return 0;
}