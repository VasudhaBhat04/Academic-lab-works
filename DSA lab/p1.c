#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int a[MAX],pos,ele;
int n=0;
void create()
{
    printf("enter number of elements\n");
    scanf("%d",&n);
    printf("enter %d elements\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void insert()
{    if (n==MAX)
{
    printf("cant insert\n");
}
else
   
   { printf("enter a valid position to insert an element \n");
    scanf("%d",&pos);
    if(pos>n)
    {
        printf("invalid position\n");
        return;
    }
    printf("eneter an element to insert\n");
    scanf("%d",&ele);
    for(int i=n-1;i>=pos;i--)
    {
        a[i+1]=a[i];
    }
    a[pos]=ele;
    printf("%d element inserted \n",ele);
    n++;

    
}
}
void delete()
{    if (n==0)
{
    printf("cant delete\n");
}
else{
    printf("enter a valid position to delete an element \n");
    scanf("%d",&pos);
    if(pos>n-1)
    {
        printf("invalid position\n");
        return;
    }
    ele=a[pos];
    printf("%d element deleted \n",ele);
    for(int i=pos;i<n;i++)
    {
        a[i]=a[i+1];
    }
    
    n--;
    
}
}
void display()
{
    if(n==00)
    {
        printf("the array is empty\n");
    }
    else
    {
        printf("the elements in the array are:\n");
        for(int i=0;i<n;i++)
        {
            printf("%d\t",a[i]);
        }
    }
}
int main()
{
    int choice;
    do
    {
        printf("menu\n1.create an array\n2.insert an element array\n3.de  lete an element\n4.display\n5.exit\nenter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:create();
        break;
        case 2:insert();
        break;
        case 3:delete();
        break;
        case 4:display();
        break;
        case 5: printf("thank you\n");
        break;
        
        default:
            break;
        }
    } while (choice!=5);
    return 0;
    
}
