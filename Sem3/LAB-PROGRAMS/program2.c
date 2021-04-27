#include<cstring>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define EXPR_SIZE 100

int top = -1;
char op_stack[100];
void push(int n){
    if(top >= EXPR_SIZE)
        printf("Overflow\n");
    else
        op_stack[top] = n;
        top = top + 1;
}
char pop(){
    if(top > 0){
        int temp = op_stack[top];
        top = top - 1;
        return(temp);
    }
    else{
        return('U');
    }
}
void display(){
    for(int i = 0; i < top; i++){
        printf("%c ", op_stack[i]);
    }
}
int length(char infix[]){
    int count= 0;
    for(int i = 0; infix[i] != '\0'; i++){
        count += 1;
    }
    return count;
}
int valid(char s[]){
    int l = length(s);
    s[l] = ' ';
    if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/' || s[0] == '^'){
        return -1;
    }
    for(int i = 0; s[i] != '\0'; i++){
        if ((s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') && (s[i+1] == '+' || s[i+1] == '-' || s[i+1] == '*' || s[i+1] == '/' || s[i+1] == '^')){
            return -1;
        }
        if (isdigit(s[i]) && isdigit(s[i+1])){
            return -1;
        }
        if (s[i] == '('){
            push(s[i]);
        }
        if(s[i] == ')'){
            if (pop() == 'U'){
                return -1;
            }
            else{
                if(pop() != '('){
                    return -1;
                }
                else{
                    continue;
                }
            }
        }
    }
    return 1;
}
int precedence(char x)
{
    if(x == '^')
        return -1;
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return -1;
}

int main(){
    char infix[100];
    char postfix[100];
    int index = -1;
    printf("Enter the expression ");
    scanf("%s", infix);
    if(valid(infix) == 1){
        printf("Expression is valid\n");
        printf("Postfix expression is : ");
         int a,c=0,op;
         char ch;
        while(infix[c]!='\0')
        {
            if(infix[c]>=97&& infix[c]<=122||ch>=65&&ch<=90) {
                printf("%c",infix[c]);
            }
            else if(infix[c]=='(') {
                push(infix[c]);
            }
            else if(infix[c]==')') {
                while((ch=pop()) != '(') {
                    printf("%c",ch);
                }
            }


            if(infix[c]=='*' || infix[c]=='/' || infix[c]=='+' || infix[c]=='-'|| infix[c] == '^' )
            {
                while(precedence(op_stack[top])>precedence(infix[c])) {

                    printf("%c",pop());
                }
                push(infix[c]);
            }


            c=c+1;
        }
        while(top!=-1)
        {
            printf("%c",pop());
        }

    }
    else{
        printf("Invalid expression\n");
    }
    return 0;
}
