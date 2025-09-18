#include<iostream>
#include<climits>
using namespace std;

struct Node{
    int data;
    Node * next;

    Node(int val):data(val),next(NULL){}
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

Node * reverseNList(Node* head,int n,int m){
    if(!head || n==0) return head;
    
    Node* curr = head;
    int i = 0;
    while(curr && i<m-1){
        curr = curr->next;
        i++;
    }

    if(!curr || !curr->next) return head;

    Node* start = curr->next;
    Node* prev = NULL;
    Node* fwd = NULL;
    i = 0;

    while(start && i<n){
        fwd = start->next;
        start->next = prev;
        prev = start;
        start = fwd;
        i++;
    }

    curr->next = prev;

    if(head){
        Node* tail = curr->next;
        while(tail && tail->next) tail = tail->next;
        tail->next = reverseNList(start,n,m);
    }

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
    cout<<"Enter the Node Data(enter -1 to stop) : ";
    while(true){
        cin>>val;
        if(val==-1) break;
        insertAtEnd(head,val);
    }

    printList(head);
    cout<<endl;
    head = reverseNList(head,3,2);
    printList(head);
}