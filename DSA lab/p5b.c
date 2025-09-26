#include<stdio.h>
void toh(int n,char source,char destination,char auxillary){
if(n==1){
    printf("move disk 1 from %c to %c\n",source,destination);
    return;
}
toh(n-1,source,auxillary,destination);
printf("move disk %d from %c to %c\n",n,source,destination);
toh(n-1,auxillary,destination,source);
}
int main(){
    int n;
    printf("enter number of disks\n");
    scanf("%d",&n);
    toh(n,'a','c','b');
    return 0;
}
