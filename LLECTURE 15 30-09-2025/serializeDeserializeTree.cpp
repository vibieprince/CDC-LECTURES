#include<iostream>
#include<queue>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;

    Node(char val) : data(val),left(NULL),right(NULL){}
};

string treeToString(Node* root){
    string result = "";
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(!curr){
            result += '$';
            continue;
        }
        result += curr->data;
        q.push(curr->left);
        q.push(curr->right);
    }
    return result;
}

Node* stringToTree(string str,int n,int i){
    if(i>=n) return NULL;
    if(str[i]=='$') return NULL;
    Node* r = new Node(str[i]);
    r->left = stringToTree(str,n,2*i+1);
    r->right = stringToTree(str,n,2*i+2);
    return r;
}

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

int main(){
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');

    root->left->right = new Node('D');
    root->right->left = new Node('E');
    root->right->left->left = new Node('G');
    root->right->right = new Node('F');

    string result = treeToString(root);
    int n = result.length();
    Node* rootnew = stringToTree(result,n,0);
    levelorderTraversal(rootnew);
    return 0;
}