#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node* next;

    Node(int val):data(val),left(NULL),right(NULL),next(NULL){}
};

Node* setNextPointers(Node* root){
    if(!root) return NULL;
    
    Node* leftNode = root;
    while(leftNode->left){
        Node* curr = leftNode;
        while(curr){
            curr->left->next = curr->right;
            if(curr->next) curr->right->next = curr->next->left;
            curr = curr->next;
        }
        leftNode = leftNode->left;
    }
    return root;
}

void printTree(Node* root) {
    Node* levelStart = root;

    // Print each level
    while (levelStart) {
        Node* current = levelStart;
        while (current) {
            cout << current->data << " -> "; // Print node value
            if (current->next) {
                cout << current->next->data; // Print the 'next' node value
            } else {
                cout << "NULL"; // End of the level, no next node
            }
            cout << " | "; // For separation between nodes in a level
            current = current->next; // Move to next node in the same level
        }
        cout << endl; // New line after each level
        levelStart = levelStart->left; // Move down to the next level
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

    root = setNextPointers(root);
    printTree(root);    

    return 0;
}