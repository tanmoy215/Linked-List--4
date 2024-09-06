#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
vector<int> maxiandmini(Node* head){
   int idx = 1;
   int fidx = -1;
   int lidx = -1;
   Node* a = head;
   Node* b = head->next;
   Node* c = head->next->next;
   if(c==NULL) return {-1,-1}; //{-1,-1} its a vector form
   //finding maximum distance
   while(c!=NULL){
    if((a->data < b->data && c->data < b->data) || (a->data > b->data && c->data > b->data)){
        if(fidx==-1) fidx = idx;
        else lidx = idx;
    }
    idx++;
    a=a->next;
    b=b->next;
    c=c->next;
   }
    if(lidx==-1) return {-1,-1};
    int maxd = lidx - fidx;
    //finding Minimum distance
    fidx =-1;
    lidx=-1;
    idx=1;
    a=head;
    b=head->next;
    c=head->next->next;
    int mind = INT_MAX;
    while(c!=NULL){
        if((a->data < b->data && c->data < b->data) || (a->data > b->data && c->data > b->data)){
            fidx = lidx;
            lidx=idx;
            if(fidx!=-1){
                 int d = lidx-fidx;
            mind = min(mind,d);
            }
        }
        idx++;
         a=a->next;
         b=b->next;
         c=c->next;
    }
    return {mind,maxd};
}
void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head = new Node(2);
    Node* a = new Node(1);
    Node* b = new Node(3);
    Node* c = new Node(5);
    Node* tail = new Node(4); 
    head->next = a;
    a->next = b;
    b->next = c;
    c->next =tail;
    display(head);
    vector<int> arr = maxiandmini(head);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}