#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;
    
    Node(int val){
        this->val = val;
        next = prev = NULL;
    }
};

void display(Node* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void tailDisplay(Node* tail){
    while(tail != NULL){
        cout << tail->val << " ";
        tail = tail->prev;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* tail = new Node(60);

    // forward
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = tail;

    // prev
    a->prev = head;
    b->prev = a;
    c->prev = b;
    d->prev = c; 
    tail->prev = d; 

    display(head);
    tailDisplay(tail);

    return 0;
}
