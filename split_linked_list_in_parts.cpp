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
vector<Node*> splitlistpair(Node* head,int k){
     Node* temp = head;
     int len =0;
     while(temp!=NULL){
       len++;
        temp=temp->next;
     }
     int size = len/k;
     int rem = len%k;
     vector<Node*> ans;
      temp = head; 
     while(temp!=NULL){
       Node* c = new Node(-1);
       Node* tempc = c;
       int s = size;
       if(rem>0) s++;
       rem--;
       for(int i=1;i<=s;i++){
        tempc->next = temp;
        temp=temp->next;
        tempc = tempc->next;
       }
       tempc->next = NULL;
       ans.push_back(c->next);
     }
     if(ans.size()<k){
        int extra = k-ans.size();
        for(int i=1;i<=extra;i++){
            ans.push_back(NULL);
        }
     }
     return ans;
}
int main(){
     Node* head = new Node(10);
     Node* a = new Node(20);
     Node* b = new Node(30);
     Node* c = new Node(40);
     Node* d = new Node(50);
     Node* tail = new Node(60);
     head->next =a;
     a->next =b;
     b->next = c;
     c->next = d;
     d->next = tail;
     display(head);
     int k;
     cout<<"enter k : ";
     cin>>k;
     vector<Node*> arr = splitlistpair(head,k);
        for (int i = 0; i < arr.size(); i++) {
        cout << "List " << i + 1 << ": ";
        display(arr[i]);
    }
    return 0;
}