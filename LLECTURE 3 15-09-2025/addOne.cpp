#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtEnd(Node* &head,int data){
    Node* newNode = new Node(data);
    if(!head){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newNode;
}

void printList(Node * head){
    while(head != NULL) {
        cout << head->data;
        if(head->next != NULL) cout << "->";
        head = head->next;
    }
    cout << endl;
}

Node * addOne(Node* &head){
    if(!head) return new Node(1);
    Node* start = NULL;
    Node* end = head;
    while(end!=NULL){
        if(end->data != 9) start = end;
        end = end->next;
    }
    if(start==NULL){
        start = new Node(1);
        start->next = head;
        head = start;
    }
    else start->data++;

    start = start->next;
    while(start!=NULL){
        start->data = 0;
        start = start->next;
    }
    return head;
}

int main(){
    Node * head = NULL;
    int val;

    cout<<"Enter node data (enter -1 to stop) : ";
    while(true){
        cin>>val;
        if(val==-1) break;
        insertAtEnd(head,val);
    }

    cout<<"Original List : ";
    printList(head);

    cout<<"List after adding one : ";
    printList(addOne(head));

    return 0;
}