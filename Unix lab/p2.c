
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[]){
    if(argc!=3){
        printf("the syntax should be as follows:\ncommand name filetoread filetowrite\n");
        exit(1);
    }
    int fdone,fdtwo;
    char buf;
    fdone=open(argv[1],O_RDONLY);
    if(fdone==-1){
        printf("cant open file\n");
        close(fdone);
        exit(1);
    }
    fdtwo=open(argv[2],O_WRONLY|O_CREAT);
    if(fdtwo==-1){
        printf("cant open file\n");
        close(fdone);
        exit(1);
    }
    while(read(fdone,&buf,1)){
        write(fdtwo,&buf,1); 
    }
    printf("successfully copied");
    close(fdone);
    close(fdtwo);
    return 0;
}
