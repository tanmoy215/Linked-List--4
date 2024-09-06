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
class CIR{
    public:
    int size;
     Node* head;
     Node* tail;
     CIR(){
     size = 0;
     head = tail = nullptr;
     }
  void InsertAtHead(int val){
     Node* temp = new Node(val);
     if(size==0){
         head = tail = temp;
         tail->next = head;
     }
     else{
         temp->next = head;
            head = temp;
            tail->next = head;
     }
     size++;
  }
  void InsertAtEnd(int val){
    Node* temp = new Node(val);
     if(size==0) head = tail=temp;
     else{
        tail->next = temp;
        temp->next = head;
        tail = temp;
     }
     size++;
  }
  void InsertAtIndex(int val,int idx){
     if(idx<0 || idx>size) cout<<"Invalid Input"<<endl;
     if(idx==0) InsertAtHead(val);
     if(idx==size) InsertAtEnd(val);
     else{
        Node* a = new Node(val);
          Node* temp = head;
          for(int i=0;i<idx-1;i++){
              temp=temp->next;
          }
          a->next =temp->next;
          temp->next = a;
     }
     size++;
  }
  void DeleteAtHead(){
    if(size==0){
      cout<<"Linked List is Empty"<<endl;
      return;
    }
   Node* temp = head;
   temp=temp->next;
   head = temp;
   tail->next = head;
   size--;
  }
void DeleteAtTail() {
    if (size == 0) {
        cout << "Linked List is Empty" << endl;
        return;
    }

    if (size == 1) { 
        head = tail = nullptr;
        size--;
        return;
    }
    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }  
    temp->next = head;
    size--;
}
void DeleteAtIndex(int idx){
    if(idx<0 || idx>=size){
        cout<<"Invalid Input"<<endl;
        return;
    }
    if(idx==0) DeleteAtHead();
    if(idx==size-1) DeleteAtTail();
    else{
        Node* temp = head;
        for(int i=0;i<idx-1;i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        size--;
    }
}
void GetAtIndex(int idx){
    if(idx<0 || idx>=size) {
        cout<<"Invalid Input"<<endl;
        return;
    }
    if(idx == 0){
         cout<<head->data<<endl;
         return;
    }
    if(idx==size-1) {
        cout<<tail->data<<endl;
        return;
    }
    else{
        Node* temp = head;
        for(int i=0;i<idx;i++){
            temp = temp->next;
        }
        cout<<temp->data<<endl;
    }
}
  void display() {
    if (head == nullptr) {
        // No elements to display
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";  // Print the data of the current node
        temp = temp->next;          // Move to the next node
    } while (temp != head);         // Continue until we loop back to the head
    cout << endl;
   }
};
int main(){
   CIR list;
   list.InsertAtHead(29);
   list.InsertAtHead(78);
   list.InsertAtHead(74);
   list.InsertAtHead(23);
   list.InsertAtHead(10);
     //list.display();
    list.InsertAtEnd(34);
    list.InsertAtEnd(45);
    list.InsertAtEnd(89);
    // list.display();
    // list.InsertAtIndex(90,2);
    // list.display();
    // list.DeleteAtHead();
    // list.display();
    // list.DeleteAtTail();
    // list.display();
    // list.DeleteAtIndex(3);
    list.display();
    list.GetAtIndex(0);
    return 0;
}