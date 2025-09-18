#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val) : data(val),next(NULL){}
};

void insertAtEnd(Node * &head,int val){
    Node * newNode = new Node(val);
    if(!head){
        head = newNode;
        return;
    }

    Node *temp = head;
    while(temp->next)
       temp = temp->next;
    
    temp->next = newNode;
}

Node* reverseList(Node * curr,Node* prev=NULL,Node* fwd = NULL){
    if(curr==NULL) return prev;
    fwd = curr->next;
    curr->next = prev;
    prev = curr;
    curr = fwd;
    return reverseList(curr,prev,fwd);
}

void printList(Node* head){
    while(head!=NULL){
        cout<<head->data;
        if(head->next!=NULL) cout<<"->";
        head = head->next;
    }
}

int main(){
    Node* head = NULL;
    int val;
    cout<<"Enetr Node data (enter -1 to stop) : ";
    while(true){
        cin>>val;
        if(val==-1) break;
        insertAtEnd(head,val);
    }

    printList(head);
    cout<<endl;
    head = reverseList(head);
    printList(head);
}