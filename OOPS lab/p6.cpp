#include<iostream>
using namespace std;
const int SIZE=5; 

class stack
{
   int items[SIZE];
   int top;
   int full();
   int empty();
   public:
   stack()
   {
      top=-1;
   }
   stack operator--(int);
   friend stack operator+(stack s1,int elem);
   friend ostream &operator<<(ostream &os,stack &s1);
};
int stack::full()
{
   if(top==SIZE-1)
      return 1;
   else
      return 0;
}
int stack::empty()
{
   if(top==-1)
      return 1;
   else
      return 0;
}
stack stack::operator--(int )
{
   if(empty())
   {
     cout<<"Stack underflow\n";
   }
   else
   {
       cout<<"\nThe element deleted is :"<<items[top];
       stack t;
       t.top=top--;
       for(int i=0;i<=top;i++)
           t.items[i]=items[i];
   }
   return *this;
}
ostream &operator<<(ostream &os,stack &s1)
{
   for(int i=s1.top;i>=0;i--)
    {
     os<<s1.items[i]<<"\n";
     }
   return os;
}
stack operator+(stack s1,int elem)
{
   if(s1.full())
     cout<<"\nStack overflow\n";
   else
     s1.items[++(s1.top)]=elem;
   return s1;
}
int main()
{
   stack s1;
   int choice,elem;
   
   for(;;)
   {
     cout<<"\n1:PUSH 2:POP 3:DISPLAY 4:EXIT\n"
     <<"Enter your choice:";
     cin>>choice;
     switch(choice)
     {
       case 1:
           cout<<"Enter the element to be inserted:";
           cin>>elem;
           s1=s1+elem;
           break;
       case 2:
           s1=s1--;
           break;
       case 3:
           cout <<"The contents of the stack are :\n"<<s1;
           break;
       case 4: exit(0);
       default: cout <<"Invalid choice\n";
       
       exit(0);
     }
   }
}
