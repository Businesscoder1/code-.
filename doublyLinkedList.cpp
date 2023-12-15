#include<iostream>

using namespace std;

class Node{
   public:
   int data;
   Node *prev;
   Node *next;
   Node(int d){
    this->data=d;
    this->next=NULL;
    this->prev=NULL;

   }
};

void print(Node *head){
    Node *temp=head;

    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
    
}
    

int length(Node *head){
     int len=0;
     Node *temp=head;
     while(temp!=NULL){
        temp=temp->next;
        len++;
     }
     cout<<"length of list:"<<len<<endl;
     return len;
}
void InsertAtHead(Node *&head,int d){
    Node*temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void InsertAtTail(Node* &tail,int d)
{
    Node *temp= new Node(d);
    // int cnt=0;
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    
}

void insertAtPosition(Node * &tail,Node * &head,int position ,int d){
    Node* temp=head;
    int cnt=1;
    while (cnt  <position)
    {
        temp=temp->next;
        cnt++;
    }

    
    if (position==1)
    {
        InsertAtHead(head,d);
    }
    

    else{
        Node *NodeToInsert=new Node(d);
        NodeToInsert->next=temp->next;
        temp->next->prev=NodeToInsert;
        temp->next=NodeToInsert;
        NodeToInsert->prev=temp;
        int len=length(head);
    if (position==len)
    {
        NodeToInsert->next=NULL;
        temp->next=NodeToInsert;
        NodeToInsert->prev=temp;
    }
    }
    
    
    
}
int main(){
   Node *Node1= new Node(12);
   Node *head=Node1;
   print(head);
   Node *tail=Node1;
   InsertAtHead(head,13);
   print(head);
   InsertAtHead(head,14);
   print(head);
   InsertAtHead(head,15);
   print(head);
   InsertAtHead(head,16);
   print(head);
   InsertAtTail(tail , 11);
   print(head);
   insertAtPosition(tail,head,4,56);
   insertAtPosition(tail,head,8,561);
   print(head);
   length(head);

}