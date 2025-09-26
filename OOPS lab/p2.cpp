#include<iostream>
using namespace std;
#define SIZE 10

class STUDENT
{
  float m1,m2,m3;
  char name[20],num[10];
  public:
  void getdata();
  void dispdata();
};
void STUDENT::getdata()
{
  cout<<"\nEnter student USN: " ;
  cin>>num;
  cout<<"Enter student name: " ;
  cin>>name;
  cout<<"Enter student's 3 marks: " ;
  cin>>m1>>m2>>m3;
}
void STUDENT::dispdata()
{
  float avg,low=m1;
  if(m2<low){
    low=m2;}
  else if(m3<low){
    low=m3;}
  avg=(m1+m2+m3-low)/2.0;
  cout<<"\nStudent USN: "<<num
  <<"\nStudent name: "<<name
  <<"\nStudent average: "<<avg;
}
int main()
{
  STUDENT stud[SIZE];
  int n,i;
  
   cout<<"\nStudents Report";
   cout<<"\nEnter the number of students: ";
   cin>>n;
  for(int i=0;i<n;i++){
     stud[i].getdata();
  }
   cout<<"\n-----------------"
     <<"\nStudents Details::"
     <<"\n-----------------";
  for( i=0;i<n;i++)
  {
    cout<<"\nStudent:"<<i+1;
    stud[i].dispdata();
    cout<<"\n------------";
  }
}
