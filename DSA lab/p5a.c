#include<stdio.h>
#include<math.h>
int res,op1,op2,s[20],top=-1;
char postfix[20],symb;
void push(char item){
    s[++top]=item;
}
int pop(){
    return s[top--];
}
int main(){
    printf("enter a valid postfix expression\n");
    scanf("%s",postfix);
    for(int i=0;postfix[i]!='\0';i++){
        symb=postfix[i];
        if(symb>='0'&&symb<='9'){
            push(symb-'0');
        }
        else{
            op2=pop();
            op1=pop();
            switch (symb){
            case '+':push(op1+op2);
                break;
            case '-':push(op1-op2);
            break;
            case '*':push(op1*op2);
            break;
            case '/':push(op1/op2);
            break;
            case '^':push(pow(op1,op2));
            break;
            case '%':push(op1%op2);
                break;
            default:push(0);
                break;
            }
        }
    }
    res=pop();
    printf("\nthe resultant is :%d\n",res);
    return 0;
}
