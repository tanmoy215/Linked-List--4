#include<bits/stdc++.h>
using namespace std;
class Node{
   public:
   int data;
   Node* next;
   Node* prev;
   Node(int data){
    this->data = data;
    next =prev= NULL;
   }
};
class DLL{
  public:
   Node* head;
   Node* tail;
   int size;
    DLL(){
        size = 0;
        head=tail=NULL;
    }
 void InsertAtHead(int val){
    Node* temp = new Node(val);
     if(size==0) head=tail=temp;
     else{
     temp->next = head;
     head->prev =temp;
     head=temp;
     head->prev = tail;
     tail->next = head;
     }
     size++;
 }
 void InsertAtTail(int val){
    Node* temp = new Node(val);
     if(size==0){
        head=tail=temp;
        return;
     }
     else{
        tail->next = temp;
        temp->prev = tail;
        tail=temp;
        tail->next = head;
        head->prev = tail;
     }
     size++;
 }
 void InsertAtIndex(int val,int idx){
    if(idx<0 || idx>=size){
        cout<<"Index out of Bound"<<endl;
        return;
    }
    else if(idx==0) InsertAtHead(val);
    else if(idx==size-1) InsertAtTail(val);
    else{
         Node* a = new Node(val);
         Node* temp = head;
         for(int i=0;i<idx-1;i++){
            temp=temp->next;
         }
         a->next = temp->next;
         temp->next->prev = a;
         temp->next =a;
         a->prev = temp;
         size++;
    }
 }
 void DeleteAtHead(){
    if(size==0){
        cout<<"Enpty Linked List"<<endl;
        return;
    }
    else{
        Node* temp = head;
        temp =  temp->next;
        temp->prev = tail;
        tail->next = temp;
        head = temp;
        size--;
    }
 }
 void DeleteAtTail(){
    if(size==0){
        cout<<"Enpty Linked List"<<endl;
        return;
    }
    else{
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        size--;
    }
 }
 void DeleteAtIndex(int idx) {
    if (idx < 0 || idx >= size) {
        cout << "Index out of Bound" << endl;
        return;
    } else if (idx == 0) {
        DeleteAtHead();
    } else if (idx == size - 1) {
        DeleteAtTail();
    } else {
        Node* temp = head;
        for (int i = 0; i < idx - 1; i++) {
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;

        // Updating pointers to bypass the node being deleted
        temp->next = nodeToDelete->next;
        nodeToDelete->next->prev = temp;

        // Free the memory of the node being deleted
        delete nodeToDelete;
        size--;
    }
}
 void Display(){
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
 }
 void reverse(){
    Node* temp = tail;
    do{ 
        cout<<temp->data<<" ";
        temp = temp->prev; 
    }while(temp!=tail);
    cout<<endl;
 }
};
int main(){
    DLL list;
    // list.InsertAtHead(20);
    // list.InsertAtHead(28);
    // list.InsertAtHead(12);
    list.InsertAtHead(37);
    list.InsertAtHead(45);
    list.InsertAtHead(234);
    //list.Display();
    list.InsertAtTail(90);
    //list.Display();
    list.InsertAtTail(7802);
    //list.Display();
    list.InsertAtHead(60);
    //list.Display();
    list.InsertAtIndex(34,5);
    //list.Display();
    //list.reverse();
    list.DeleteAtHead();
   // list.Display();
    list.DeleteAtTail();
    list.Display();
    list.DeleteAtIndex(3);
    list.Display();
    return 0;
}