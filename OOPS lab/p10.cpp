#include <iostream>
using namespace std;
#define size 10

template<class T>
class Queue{
  public:
    int front;
    int rear;
    T Q[10];

 Queue() {
    front = -1;
    rear = -1;
  }
 void enqueue(T x) {
    if(rear == size-1)
    {
        cout << "Queue Overflow!!" << endl;     
    } 
    else 
    {
        rear++;
        Q[rear] = x;
    }
}
  T dequeue() {
    int x = -1;
   if (front == rear)                           
    {
        cout << "Queue Underflow!!" << endl;
    } 
    else 
    {
        front++;
        x = Q[front];
    }
      return x;
}
void display() {
    cout<<"The queue elements are: "<<endl;
    for (int i=front+1; i<=rear; i++)
        cout << Q[i]<< " ";
        cout << endl;
    }
};
int main(){
    Queue<int> a;
    Queue<double> b;
    int ch,x;
    double y;

    START :
    cout<<"\nQueue Using Template function:-"<<endl;
    cout<<"1.Integer queue"<<endl;
    cout<<"2.Double queue"<<endl;
    cout<<"3.Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    
    if(ch == 1){
        while(true){
        cout<<"\nInteger Queue :-"<<endl;
        cout<<"1.Insert"<<endl;
        cout<<"2.Delete"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter the element to be inserted: ";
                    cin>>x; 
                    a.enqueue(x);
                    break;
            case 2:  a.dequeue();
                    break;
            case 3: a.display();
                    break;
            default : goto START;
            }
        }
    }
   else if (ch==2)
    {
        while(true){
        cout<<"\nDouble Queue :-"<<endl;
        cout<<"1.Insert"<<endl;
        cout<<"2.Delete"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter the element to be inserted: ";
                    cin>>y;
                    b.enqueue(y);
                    break;
            case 2: b.dequeue();
                    break;
            case 3: b.display();
                    break;
            default : goto START;
            }
        }
    }
    else{
        exit(0);
    }
}
