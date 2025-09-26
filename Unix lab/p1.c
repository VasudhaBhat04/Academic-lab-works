
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main(int argc,char *argv[]){
    if(argc!=2){
        printf("command name file to read\n");
        exit(1);
    }
    char buf[2048];
    size_t count;
    FILE *fdold=fopen(argv[1],"r");
    if (fdold==NULL){
        printf("cant open file:%s",argv[1]);
        exit(1);
    }
    while((count=fread(buf,1,sizeof(buf),fdold))>0){
        printf("%s",buf);
    }
    return 0;
}


       
