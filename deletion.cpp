#include<iostream>

using namespace std;
class List{
    public:
    int data;
    List *next;

    List(int data){
        data=data;
        next=NULL;
        
    }

};
void insertionatHead(List* &head,int d){
    
        List*temp=new List(d);
        temp->next=head;
        head=temp;
    
   
}
void InsertionAtTail(List*tail,int d){
    List*temp=new List(d);
    tail->next=temp;
    tail=tail->next;

}
void deleting(int position,List * &head){
    if(position==1){
       List*temp=head;
       head=head->next;
       temp=NULL;
       delete temp;
    }
    else{
        List*curr=head;
        List*prev=NULL;
        int cnt=1;
        while(cnt<=position-1){
            prev=curr;
            curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }
}

void print(List*&head){
    List*temp=head;
    while (temp!=NULL)
    {
        /* code */
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
 List *node=new List(34);
 
 List*head=node;
 List*tail=node;

 insertionatHead(head,34);
 insertionatHead(head,45);
 insertionatHead(head,12);
 InsertionAtTail(tail,56);
 print(head);
 deleting(2,head);


}