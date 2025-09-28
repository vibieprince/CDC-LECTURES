#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;

    Node(int val) : data(val),next(NULL){}
};

Node* mergeSortedLists(Node* h1,Node* h2){
    if(!h1) return h2;
    if(!h2) return h1;

    Node * head;
    if(h1->data < h2->data){
        head = h1;
        h1 = h1->next;
    }
    else{
        head = h2;
        h2 = h2->next;
    }

    Node* tail = head;
    while(h1 && h2){
        if(h1->data < h2->data){
            tail->next = h1;
            h1 = h1->next;
        }
        else{
            tail->next = h2;
            h2 = h2->next;
        }
        tail = tail->next;
    }

    if(!h1) tail->next = h2;
    else tail->next = h1;
    return head;
}

void printList(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() { // Written by ChatGPT
    // Creating first sorted list: 1->3->5
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    // Creating second sorted list: 2->4->6->8
    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);
    list2->next->next->next = new Node(8);

    // Merge the lists
    Node* mergedList = mergeSortedLists(list1, list2);

    // Print merged list
    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}