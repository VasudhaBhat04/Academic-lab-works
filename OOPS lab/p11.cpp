#include<iostream>
using namespace std;

class DLIST{
    int data,n,i,pos,count;
    DLIST *prev,*next;
    public:
      void create();
      void insert();
      void del();
      void dis();
} *head=NULL,*temp=NULL,*newnode,*tail=NULL;
void DLIST::create(){
    cout<<"Enter the Number of Nodes to be created:";
    cin>>n;
  for(i=0;i<n;i++){
    newnode = new DLIST;
    cout<<"Enter the data field:";
    cin>>newnode->data;
    newnode->next=NULL;
    newnode->prev=NULL;
   if(head==NULL)
    head=temp=newnode;
   else{
    temp->next=newnode;
    newnode->prev=temp;
    temp=temp->next;
        }
    }
}
void DLIST::insert(){
    newnode = new DLIST;
    cout<<"Enter the data field:";
    cin>>newnode->data;
    newnode->next=NULL;
    newnode->prev=NULL;
    cout<<"Enter the position:";
    cin>>pos;
    temp=head;
    count=1;
   if(count<pos){
       while(count<pos){
           temp=temp->next;
           count++;
    }
     newnode->prev=temp->prev;
     temp->prev->next=newnode;
     temp->prev=newnode;
     newnode->next=temp;}
   else if(count==pos){
      newnode->next=head;
      head->prev=newnode;
      newnode->prev=NULL;
      head=newnode;
    }       
}
void DLIST::del(){
    cout<<"Enter the position:";
    cin>>pos;
    temp=head;
    count=1;
  if(head==NULL)
    cout<<"Underflow!!\n";
else if(count<pos){
  while(count<pos){
    temp=temp->next;
    count++;
}
  temp->prev->next=temp->next;
  temp->next->prev=temp->prev;
  free(temp);
    }
 else if(count==pos){
     temp=head;
     temp->next->prev=NULL;
     head=temp->next;
     delete temp;
 }
}
void DLIST::dis(){
    temp=head;
    if(head==NULL)
    cout<<"List is empty\n";
    else{
    while(temp->next!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }cout<<temp->data<<"  "<<endl;;
}
}
int main(){
    int ch;
    DLIST d;
    while(1){
    cout<<"Double Linked List:-"<<endl;
    cout<<"1.Create\n2.Insert\n3.Delete\n4.Display\n5.Exit\nEnter your choice:"<<endl;
    cin>>ch;
    switch(ch){
        case 1:d.create();
               break;
        case 2:d.insert();
               break;
        case 3:d.del();
               break;
        case 4:d.dis();
               break;
        case 5:exit(0);
        default:cout<<"Invalid Choice!!\n";
     }
  }
    return 0;
}
