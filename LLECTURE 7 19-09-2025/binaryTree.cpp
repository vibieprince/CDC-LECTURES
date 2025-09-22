#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val),left(NULL),right(NULL){}
};

Node* buildTree(){
    int val;
    cout<<"Enter data for root (-1 for NULL) : ";
    cin>>val;

    if(val==-1) return NULL;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        int leftVal,rightVal;
        cout<<"Enter left child of "<<curr->data<<" (-1 for NULL) : ";
        cin>>leftVal;

        if(leftVal != -1){
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }

        cout<<"Enter right child of "<<curr->data<<" (-1 for NULL) : ";
        cin>>rightVal;

        if(rightVal != -1){
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }  
    }
    return root;
}

void inorderTraversal(Node* root){
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void postorderTraversal(Node* root){
    if(root==NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

void preorderTraversal(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void printLeafNode(Node* root){
    if(!root) return;
    if(!root->left && !root->right) cout<<root->data<<" ";
    printLeafNode(root->left);
    printLeafNode(root->right);
}

int countNode(Node* root){
    if(!root) return 0;
    int x = countNode(root->left);
    int y = countNode(root->right);

    return x+y+1;
}

bool search(Node* root,int val){
    if(!root) return false;
    if(root->data == val) return true;
    return search(root->left,val) || search(root->right,val);
}

int main(){
    cout<<"Build your binary Tree"<<endl;
    Node * root = buildTree();

    cout<<"Inorder Traversal : ";
    inorderTraversal(root);
}