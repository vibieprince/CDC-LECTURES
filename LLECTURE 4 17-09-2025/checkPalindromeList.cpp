#include<iostream>
using namespace std;

struct Node{
    char data;
    Node * next;

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

bool checkPalindrome(Node* head){
    if(!head || !head->next || !head->next->next) return true;
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* curr = slow->next;
    slow->next = NULL;
    Node* prev = NULL;
    while(curr!=NULL){
        fast = curr->next;
        curr->next = prev;
         
        prev = curr;
        curr = fast;
    }

    while(head && prev){
        if(head->data  != prev->data) return false;
        prev = prev->next;
        head = head->next;
    }

    return true;
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
    char val;
    cout<<"Enter the Node Data(press - to stop) : ";
    while(true){
        cin>>val;
        if(val=='-') break;
        insertAtEnd(head,val);
    }

    if(checkPalindrome(head)) cout<<"Given List is a Palindrome ";
    else cout<<"Given list is not a palindrome";
}