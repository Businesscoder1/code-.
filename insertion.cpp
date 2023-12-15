#include<iostream>

using namespace std;
// struct Node{
   
//    int data;
//    Node* next;

// };
// class LinkedList{
   
//    private:
//    Node*head;
//    public:
//    LinkedList(){
//     head=NULL;

//    }
//    void push_back(int newElement){

//    }
// };
// void countNode(Node** head_ref,int new_data){
//     Node* new_node=new Node();

//     new_node->data=new_data;

//     new_node->next=(*head_ref);
//     (*head_ref)=new_node;
    
// }

class Node{
   
   public:
   int data;
   Node* next;
   //constructor call
   Node(int data){
    this ->data=data;
    this ->next=NULL;
   }
   ~Node(){
    int value=this->data;
    //memory free
    if(this->next !=NULL){
        delete next;
        this->next=NULL;
    }
    cout<<"memory is free for node with data"<<value<<endl;
   }
};
void InsertAtHead(Node* &head ,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;

}
void print(Node* &head){
    Node* temp=head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
    
}
void InsertionAtTail(Node* tail,int d){
    //new node
    Node* temp=new Node(d);
    tail->next=temp;
    tail=tail->next;
}
void DeleteNode(int position , Node* & head ){
     
//deleting staring node
if (position==1){
    Node *temp=head;
     head=head->next;
     //memory free
     temp->next=NULL;
     delete temp;
}
else
{
    Node* curr =head;
    Node* prev=NULL;
    int cnt=1;
    while(cnt<=position){
         
        prev=curr;
        curr=curr->next;
        cnt++;

    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
     
}


}
void InsertAtPosition(Node* &tail,Node* &head,int position, int data){
    if(position==1){
        InsertAtHead(head,data);
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;

    }InsertAtHead(head,12);
    InsertAtHead(head,15);
    InsertAtHead(head,18);
    InsertionAtTail(tail,16);
    if (temp->next==NULL)
    {
        InsertionAtTail(tail,data);
    }
    
    Node* NodeToInsert=new Node(data);
    NodeToInsert ->next=temp->next;
    temp->next=NodeToInsert;

}
int main(){
    Node* Node1=new Node(10);
    // Node* Node1=new Node(10);
    // cout<<Node1 ->data<<endl;
    // cout<<Node1 ->next<<endl;
    Node* head=Node1;
    Node* tail=Node1;
    InsertAtHead(head,12);
    InsertAtHead(head,15);
    InsertAtHead(head,18);
    InsertionAtTail(tail,16);
    // InsertAtPosition(tail,head,6,34);
    DeleteNode(1,head);
    print(head);
    DeleteNode(6,head);
    print(head);
    cout<<"tail="<<tail->data<<endl;
    return 0;
}