#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
Node* reverseList(Node* head) {
   //Iterative 
   Node *curr=head,*pre = NULL,*Next = NULL;
//    ListNode* curr = head;
//    ListNode* pre = NULL;
//    ListNode* Next = NULL;
   while(curr!=NULL){
     Next = curr->next;
     curr->next = pre;
     pre=curr;
     curr=Next;
   }
   return pre;
}
    Node* reverseBetween(Node* head, int left, int right) {
        if(left==right) return head;
        Node* a = NULL;
         Node* b = NULL; 
         Node* c = NULL; 
         Node* d = NULL;
        int n=1;
        Node* temp = head;
        while(temp!=NULL){
            if(n==left-1) a = temp;
            if(n==left) b=temp;
            if(n==right) c =temp;
            if(n==right+1) d =temp;
            n++;
            temp=temp->next;
        }
        if(a!=NULL) a->next = NULL;
        if(c) c->next = NULL;
        c =reverseList(b);
        if(a!=NULL) a->next = c;
        b->next = d;
        if(a!=NULL) return head;
        return c;
    }
Node* reverseNode(Node* head){
    Node* temp = head;
    int gap = 1;
    while(temp!=NULL && temp->next != NULL){
        int rem = 0;
        Node* t = temp->next;
        for(int i=1;i<=gap+1,t!=NULL;i++){
            t=t->next;
            rem++;
        }
        if(rem < gap+1) gap = rem-1;
        if(gap%2!=0) reverseBetween(temp,2,2+gap);
        gap++;
        for(int i=1;i<=gap,temp!=NULL;i++){
            temp= temp->next;
        } 
    }
    return head;
}
int main(){
     Node* head = new Node(10);
     Node* a = new Node(20);
     Node* b = new Node(30);
     Node* c = new Node(40);
     Node* d = new Node(50);
     Node* e = new Node(60);
     Node* f = new Node(70);
     Node* tail = new Node(80);
     head->next =a;
     a->next =b;
     b->next = c;
     c->next = d;
     d->next = e;
     e->next = f;
     f->next = tail;
     display(head);
     head = reverseNode(head);
     display(head);
    return 0;
}