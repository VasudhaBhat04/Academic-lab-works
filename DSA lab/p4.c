#include<stdio.h>
#include<stdlib.h>
int top=-1;
char postfix[20],infix[20],stack[20];
char pop(){
    return stack[top--];
}
void push(char item){
 stack[++top]=item;
}
int prec(char symb){
int p;
switch(symb){
    case '#':p=-1;
    break;
    case '(':
    case ')':p=0;
    break;
    case '+':
    case '-':p=1;
    break;
    case '*':
    case '/':p=2;
    break;
    case '^':p=3;
    break;
}
return p;
}
void evaluate(){
push('#');
char symb,temp;
int i,j=0;
for(i=0;infix[i]!='\0';i++)
{
symb=infix[i];
switch(symb){
    case '(':push(symb);
    break;
    case ')':temp=pop();
             while(temp!='('){
                postfix[j++]=temp;
                temp=pop();
             }
    break;
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    while(prec(stack[top])>=prec(symb)){
        postfix[j++]=pop();
    } 
    push(symb); 
    break;
    default:postfix[j++]=symb;
    break;       
}
}
while(top>0){
    postfix[j++]=pop();
}
}

int main(){
    printf("enter a infix expression\n");
    scanf("%s",infix);
    evaluate();
    printf("\nthe postfix expression is:%s\n",postfix);
    return 0;
}
