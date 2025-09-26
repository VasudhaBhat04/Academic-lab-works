#include<stdio.h>
#include<stdlib.h>

void insertsort(int arr[],int n)
{
int i,j,key;
for(i=1;i<n;i++)
{
    key=arr[i];
    j=i-1;
    while(j>=0&&arr[j]>key)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}
}
void selectionsort(int arr[],int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
            {
                min=j;
            }
        }
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}
int main()
{
    int choice;
    int a[10],n;
    printf("enter number of elements in an array:\n");
    scanf("%d",&n);
    printf("enter %d elements:\n",n);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("menu\n1.insertion\n2.selection\nenter your choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:insertsort(a,n);
        break;
        case 2:selectionsort(a,n);
        break;
        default:("invalid option:\n ");
        break;
     }
     printf("the sorted array:\n");
     for(int i=0;i<n;i++)
    printf("%d\t",a[i]);
    return 0;

            
}
/*#include<stdio.h>
void insertionsort(int arr[],int n){
int i,j,key;
for( i=1;i<n;i++){
    key=arr[i];
    j=i-1;
    while(j>=0&&arr[j]>key)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}

}
void selectionsort(int arr[],int n){
int i,j,temp,min;
for(i=0;i<n-1;i++){
    min=i;
    for(j=i+1;j<n;j++)
    {
        if(arr[j]<arr[min])
        min=j;
    }
    temp=arr[min];
    arr[min]=arr[i];
    arr[i]=temp;
}
}
void display(int a[],int n){
    printf("the elements in the array are\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");

}
int main()
{   int n,choice,a[10];
    printf("enter number of elements\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter %d element:\n",i+1);
        scanf("%d",&a[i]);
    }
    display(a,n);
    printf("menu\n1.insertion sort\n2.selection sort\nenter your choice:\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:insertionsort(a,n);
        break;
    case 2:selectionsort(a,n);
    break;
    
    default:printf("invalid choice\n");
        break;
    }
    display(a,n);


}

*/
