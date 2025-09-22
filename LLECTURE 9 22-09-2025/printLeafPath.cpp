#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val),left(NULL),right(NULL){}
};

void printPath(Node* root,vector<int> &arr){
    if(root==NULL) return;
    arr.push_back(root->data);
    if(!root->left && !root->right){
        for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    else{
        printPath(root->left,arr);
        printPath(root->right,arr);
    }
    arr.pop_back();
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

    vector<int> arr;
    cout << "All root-to-leaf paths:\n";
    printPath(root, arr);

    return 0;
}


