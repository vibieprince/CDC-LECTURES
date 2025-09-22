#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val):data(val),left(NULL),right(NULL){}
};
void spiralTraversal(Node* root){
    if(!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    bool reverse = false;
    vector<int> level;

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr==NULL){
            if(reverse) for(int i=level.size()-1;i>=0;i--) cout<<level[i]<<" ";
            else for(int i=0;i<level.size();i++) cout<<level[i]<<" ";
            cout<<endl;
            level.clear();

            if(!q.empty()) q.push(NULL);
            reverse = !reverse;
        }
        else{
            level.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
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

    spiralTraversal(root);

    return 0;
}