#include<bits/stdc++.h>
using namespace std;
int len = 0;
class Node{
  public:
   int data;
   Node* next;
   Node(int data){
    this->data = data;
    next = NULL;
   }
};
Node* mergeNodes(Node* head) {
        Node* a = head;
        Node* b = head->next;
        Node* c = new Node(-1);
        Node* temp =c;
        int sum=0;
        while(b!=NULL){
            if(b->data!=0){
                sum+=b->data;
                b=b->next;
            }
            else{
                Node* t = new Node(sum);
                temp->next = t;
                temp = temp->next;
                a=b;
                b=b->next;
                sum=0;
            }
        }
        return c->next;
    }
void display(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
   Node* head = new Node(0);
   Node* a = new Node(3);
   Node* b = new Node(2);
   Node* c = new Node(0);
   Node* d = new Node(6);
   Node* e = new Node(0);
   Node* f = new Node(2);
   Node* tail = new Node(0);
   head->next = a;
   a->next = b;
   b->next = c;
   c->next = d;
   d->next = e;
   e->next=f;
   f->next = tail;
   display(head);
   head = mergeNodes(head);
   display(head);
    return 0;
}