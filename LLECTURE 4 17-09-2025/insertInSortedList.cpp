#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val) : data(val),next(NULL){}
};

void insertAtEnd(Node* &head,int val){
    Node * newNode = new Node(val);
    if(!head){
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next!=NULL) temp = temp->next;
    temp->next = newNode;
}

Node* insertInSorted(Node* head,int val){
    Node* newNode = new Node(val);
    if(!head || val < head->data){
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    while(temp->next!=NULL && temp->next->data < val)
        temp = temp->next;
    
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
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
    cout<<"Enter the Node data (enter -1 to stop) : ";
    while(true){
        cin>>val;
        if(val==-1) break;
        insertAtEnd(head,val);
    }

    cout<<"Original List : ";
    printList(head);
    cout<<endl;
    head = insertInSorted(head,100);

    cout<<"List after Inserting Node : ";
    printList(head);

}