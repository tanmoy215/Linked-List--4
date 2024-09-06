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
 int length(Node* head) {
        int cnt = 0;
        Node* temp = head;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    Node* reverseKGroup(Node* head, int k) {
        int len = length(head);
        if (len < k or !head)
            return head;
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* curr = dummy;
        Node* prev = dummy;
        Node* nex = dummy;
        while (len >= k) {
            curr = prev->next;
            nex = curr->next;
            for (int i = 1; i < k; i++) {
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            prev = curr;
            len -= k;
        }
        return dummy->next;
    }
    Node* swapPairs(Node* head) { 
        return reverseKGroup(head, 2); 
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
   Node* head = new Node(10);
   Node* a = new Node(30);
   Node* b = new Node(29);
   Node* c = new Node(40);
   Node* d = new Node(69);
   Node* e = new Node(360);
   Node* f = new Node(249);
   Node* tail = new Node(27);
   head->next = a;
   a->next = b;
   b->next = c;
   c->next = d;
   d->next = e;
   e->next=f;
   f->next = tail;
   display(head);
   head = swapPairs(head);
   display(head);
    return 0;
}