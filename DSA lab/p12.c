#include<stdio.h>
#include<stdlib.h>

int key[20], n, m;
int *ht; 
int count = 0;

void insert(int key) {
    int index = key % m; 
    while(ht[index] != -1) {
        index = (index + 1) % m;
    }
    ht[index] = key;
    count++;
}

void display() {
    int i;
    if(count == 0) {
        printf("\nHash Table is empty");
        return;
    }

    printf("\nHash Table contents are:\n ");
    for(i = 0; i < m; i++)
        printf("\n T[%d] --> %d ", i, ht[i]);
}

int main() {
    int i;
    printf("\nEnter the number of employee records (N): ");
    scanf("%d", &n);

    printf("\nEnter the size of the hash table (m): ");
    scanf("%d", &m);

    ht = (int *)malloc(m * sizeof(int));
    if(ht == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    // Initialize hash table slots to -1 (empty)
    for(i = 0; i < m; i++)
        ht[i] = -1;

    printf("\nEnter the %d key values for employee records:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &key[i]);

    for(i = 0; i < n; i++) {
        if(count == m) {
            printf("\n~~~ Hash table is full. Cannot insert the record %d key ~~~", i + 1);
            break;
        }
        insert(key[i]);
    }

    // Displaying keys inserted into hash table
    display();
    // Free dynamically allocated memory
    free(ht);
    return 0;
}
/*
#include<stdio.h>
#include<stdlib.h>
int count=0,key[20],m,n;
int *ht;
void insert(int key){
    int index=key%m;
    while(ht[index]!=-1){
        index=(index+1)%m;
    }
    ht[index]=key;
    count++;
}
void display(){
    if(count==0){
        printf("hash is empty\n");
    }
    else{
        printf("the contents in the hash are:\n");
        for(int i=0;i<m;i++){
            printf(" T[%d]->%d\n",i,ht[i]);
        }
    }
}
int main(){
    printf("enter the size of memory locations(two digit)\n");
    scanf("%d",&m);
    printf("\nenter the number of file records to store\n");
    scanf("%d",&n);
    ht=(int*)malloc(m*sizeof(int));
    if(ht==NULL){
        printf("memory allocation failed\n");
        return 1;
    }
    for(int i=0;i<m;i++){
        ht[i]=-1;
    }
    printf("enter the %d employee records\n",n);
    for(int i=0;i<n;i++)
    scanf("%d",&key[i]);
    for(int i=0;i<n;i++){
        if(count==m){
            printf("hash table is full can't insert\n");
            break;
        }
        insert(key[i]);
    }
    display();
    return 0;
}
*/
