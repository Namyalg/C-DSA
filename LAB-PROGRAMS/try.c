#include<stdio.h>

char stack[100];
int top = -1;

void push(char x)
{
    if(top!=99)
    stack[++top] = x;
}
char pop()
{
    if(top==-1)
        return -1;
    else
        return stack[top--];
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
int priority(char x)
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

int main()
{
    char st[20],ch;
    int a,c=0,op;
    printf("Enter the expression ");
    scanf("%s",st);
    if
    while(st[c]!='\0')
    {
        if(st[c]>=97&& st[c]<=122||ch>=65&&ch<=90) {
            printf("%c",st[c]);
        }
        else if(st[c]=='(') {
            push(st[c]);
        }
        else if(st[c]==')') {
            while((ch=pop()) != '(') {
                printf("%c",ch);
            }
        }


        if(st[c]=='*' || st[c]=='/' || st[c]=='+' || st[c]=='-'|| st[c] == '^' )
        {
            while(priority(stack[top])>priority(st[c])) {

                printf("%c",pop());
            }
            push(st[c]);
        }


        c=c+1;
    }
    while(top!=-1)
    {


        printf("%c",pop());
    }
}