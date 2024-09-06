#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
   int data;
    Node* next;
    Node* prev;
    Node(int data){
      this->data = data;
      next = prev = NULL;
    }
};
class DDL{
  public:
   Node* head;
   Node* tail;
   int size=0;
   DDL(){
     head = tail = NULL;
   }
   void InsertAtHead(int val){
    Node* temp = new Node(val);
    if(size==0) head = tail=temp;
    else{
      temp->next = head;
      head->prev = temp;
      head = temp;
      }
      size++;
   }
   void InsertAtTail(int val){
    Node* temp = new Node(val);
     if(size==0) head = tail=temp;
     else{
      tail->next = temp;
      temp->prev = tail;
      tail=temp;
     }
     size++;
   }
   void InsertAtIdx(int val,int idx){
    if(idx<0 || idx>size) cout<<"Invalid Input"<<endl;
     if(idx==0) InsertAtHead(val);
     if(idx==size) InsertAtTail(val);
     else{
          Node* a = new Node(val);
          Node* temp = head;
          for(int i=0;i<idx-1;i++){
              temp=temp->next;
          }
          a->next = temp->next;
          temp->next->prev = a;
          temp->next = a;
          a->prev = temp;
     }
     size++;
   }
   void DeleteAtHead(){
    if(size==0){
      cout<<"Linked List is Empty"<<endl;
      return;
    }
    Node* temp = head;
     temp = temp->next;
    if(temp!=NULL) temp->prev = NULL;
    if(temp==NULL) tail=NULL;
     head = temp;
     size--;
   }
   void DeleteAtTail(){
    if(size==0){
      cout<<"Linked List is Empty"<<endl;
      return; 
    }
    else if(size==1) {
      DeleteAtHead();
      return;
    }
    Node* temp = tail;
    temp = tail->prev;
    temp->next = NULL;
    tail = temp;
    size--;
   }
   void DeleteAtIndex(int idx){
    if(size==0){
    cout<<"Linked List is Empty"<<endl;
    return;
    } 
    else if(idx<0 || idx>=size) {
      cout<<"invalid Input"<<endl;
      return;
    }
    else if(idx==0) DeleteAtHead();
    else if(idx==size-1) DeleteAtTail();
    else{
       Node* temp = head;
     for(int i=0;i<idx-1;i++){
        temp = temp->next;
     }
     temp->next = temp->next->next;
     temp->next->prev = temp;
     size--;
    }
   }
   int GetAtIndex(int idx){
       if(idx<0 || idx>=size){
        cout<<"Invalid Index"<<endl;
        return -1;
       }
       else if(idx==0) return head->data;
       else if(idx==size-1) return tail->data;
       else{ 
        if(idx < size/2){
            Node* temp = head;
        for(int i=1;i<=idx;i++){
          temp=temp->next;
        }
        return temp->data;
        }
        else{
          Node* t = tail;
          for(int i=1;i<(size-idx);i++){
            t=t->prev;
          }
          return t->data;
        }
        
       }
   }
   void display(){
    Node* temp = head;
    while(temp){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<endl;
   }
   void reverse(){
    Node* temp = tail;
    while(temp!=NULL){
       cout<<temp->data<<" ";
       temp = temp->prev;
    }
    cout<<endl;
   }
};
int main(){
  DDL ll;
  ll.InsertAtHead(10);
  //ll.display();
  ll.InsertAtHead(20);
 // ll.display();
  ll.InsertAtTail(90);
 //ll.display();
  ll.InsertAtTail(80);
 // ll.display();
  ll.InsertAtHead(70);
  // ll.display();
  // ll.reverse();
  ll.InsertAtIdx(789,2);
  //ll.display();
  // ll.DeleteAtHead();
  // ll.display();
  // ll.DeleteAtTail();
  ll.display();
  ll.DeleteAtIndex(2);
  ll.display();
  cout<<ll.GetAtIndex(3);
  return 0;
}