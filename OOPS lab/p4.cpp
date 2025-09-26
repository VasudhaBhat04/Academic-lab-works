#include<iostream>
#include<stdlib.h>
using namespace std;

class list{
     int data;
     list *next;
     public:
          void insert();
          void del();
          void display();
}*newnode,*head=NULL,*temp;

void list::insert()
{ 
   newnode = new list;
   cout<<"Enter the data:";
   cin>>newnode ->data;
   newnode ->next =NULL;
   if(head==NULL)
   {
       temp=head=newnode;
   }
   else
    {
       newnode->next=head;
       head=newnode;
    }
}
void list::del()
{
    temp=head;
    cout<<"The Deleted element is:"<<temp->data;
    head=temp->next;
    delete temp;
}
void list:: display()
{
  cout<<"Elements in the list are:";
  temp=head;
  while(temp!=NULL)
  {
      cout<<temp->data<<" ";
      temp=temp->next;
  }
}
int main()
{   
    list l;
    int ch;
    while(1){
      cout<<"\nLinked list Operations:-\n";
      cout<<"1.Insert front\n";
      cout<<"2.Delete front\n";
      cout<<"3.Display\n";
      cout<<"4.Exit\n";
      cout<<"Enter your choice :";
      cin>>ch; 
        switch(ch){
            case 1:l.insert();break;
            case 2:l.del();break;
            case 3:l.display();break;
            case 4:exit(0);
            default :cout<<"Invalid Choice!!\n";
        }
    }
}
