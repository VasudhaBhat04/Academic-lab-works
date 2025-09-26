#include<iostream>
using namespace std;

class EMPLOYEE
{
   char emp_name[30];
   int emp_number;
   float basic, da, it, gross_salary, net_salary;
   public:
   void read_emp_details(int i){
	 cout<<"\nEnter Employee "<<i<<" Details";
	 cout<<"\nEmployee Number: ";
	 cin>>emp_number;
	 cout<<"Employee Name: ";
	 cin>>emp_name;
	 cout<<"Basic Salary: ";
	 cin>>basic;
	 cout<<"\n---- Employee "<<i<<" Details are saved ----\n";
   }
   void display_emp_details(int i){
      cout<<"\nEmployee "<<i<<" Details\n";
      cout<<"\nEmployee Number	: "<<emp_number;
      cout<<"\nEmployee Name	: "<<emp_name;
      da = basic * 0.52;
      gross_salary = basic + da;
      it = gross_salary * 0.30;
      net_salary = (basic + da) - it;
      cout<<"\nNet Salary: "<<net_salary;
      cout<<"\n--------------------------\n";
   }
};
int main(){
   EMPLOYEE emp[100];
   int n, i;
 
   cout<<"\nPlease enter the number of Employees: ";
   cin>>n;
   for(i=0; i< n; i++){
      emp[i].read_emp_details(i+1);
   }
   for(i=0; i < n; i++){
      emp[i].display_emp_details(i+1);
   }
  return 0;
}
