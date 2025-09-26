#include<stdio.h>
#define max 10
int s[max],top=-1;
void push(){
    if(top==max-1){
        printf("stack overflow\n");
    }
    else{
        int ele;
        printf("enter element to push\n");
        scanf("%d",&ele);
        s[++top]=ele;
        printf("%d element pushed into stack\n",ele);

    }
}
void pop(){
    if(top==-1){
        printf("stack underflow\n");
    }
    else{
        int ele=s[top--];
        printf("%d element popped from stack\n",ele);
        
    }
}
void palindrome(){
    int i,flag=1;
    printf("the elements in the stack are\n");
    for(i=top;i>=0;i--)
     printf("%d\t",s[i]);
     printf("\nthe elements in the stack in reverse order\n");
    for(i=0;i<=top;i++)
    printf("%d\t",s[i]);
    printf("\n");
    for(i=0;i<=top/2;i++)
    {
        if(s[top-i]!=s[i])
        {
            flag=0;
            break;
        }
    }
    if(flag==0)
    {
        printf("not palindrome\n");
    }
    else{
        printf("palindrome\n");
    }
}
void display(){
     printf("the elements in the stack are\n");
    for(int i=top;i>=0;i--)
     printf("%d\t",s[i]);
     printf("\n");
}
int main(){
int choice;
do{
    printf("menu\n1.push\n2.pop\n3.palindrome\n4.display\n5.exit\nenter your choice\n");
    scanf("%d",&choice);
    switch (choice)
     {
    case 1:push();
    break;
    case 2:pop();
    break;
    case 3:palindrome();
    break;
    case 4:display();
    break;
    case 5:printf("exiting the program\n");
        break;
    
    default:printf("invalid choice\n");
        break;
    }
}while(choice!=5);
return 0;
}
