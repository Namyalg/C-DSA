#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 50

struct node {
char info;
struct node *prev;
struct node *next;
};

struct node *head;

struct node *getnode(char ele){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = ele;
    p->prev = p->next = NULL;
    return p;
}
void freenode(struct node *p){
    free(p);
}

void push(char ele) {
    struct node *p;
    p = getnode(ele);
    if(head == NULL)
    head = p;
    else {
    p->next = head;
    head->prev = p;
    head = p;
    }
}

char pop(){
    char res;
    if(head == NULL){
        printf("\rINVALID EXPRESSION  ");
        exit(0);
    }
    else {
        if(head->next == NULL){
        res= head->info;
        free(head);
        head = NULL;
        return res;
        }
        else {
        struct node *q;
        q = head;
        res= head->info;
        head = head->next;
        head->prev = NULL;
        free(q);
        return res;
        }
    }
}

int priority(char x)
{
    if(x == '(')
    return 0;
    if(x == '+' || x == '-')
    return 1;
    if(x == '*' || x == '/')
    return 2;
    if(x=='$')
    return 3;

    return 0;
}

int main(){
    char str[MAX],x;
    char *ptr,*i;
    int c=0,d=0;
    printf("Enter the expression : ");
    scanf("%s",str);
    ptr=str;

    for(int j=0; j<sizeof(str)-1; j++){
        if(isalnum(str[j]) && isalnum(str[j+1])){
        printf("\rInvalid Expression");
        exit(0);
        }
    }

    for(i=str; *i!='\0'; i++){
        if(isalnum(*i))
        c=c+1;
        else if(*i=='+' || *i=='-' || *i=='*' || *i=='/' || *i=='$')
        d=d+1;
        }
        if(c!= (d+1)){
        printf("\rINVALID EXPRESSION  ");
    exit(0);
}



while(*ptr != '\0')
{
        if(isalnum(*ptr))
            printf("%c ",*ptr);
        else if(*ptr == '(')
            push(*ptr);
        else if(*ptr == ')')
        {
            while((x = pop()) != '(')
            printf("%c ", x);
        }
        else
        {
            if(head==NULL){
            push(*ptr);
        }else{
            while( (head!=NULL) && (priority(head->info)>=priority(*ptr)) && priority(*ptr)!=3 ){
            printf("%c ",pop());
            }
            push(*ptr);
            }
        }
        ptr++;
    }
while(head != NULL)
{
if(head->info == '('){
    printf("\r INVALID EXPRESSION  ");
    exit(0);
    }else{
        printf("%c ",pop());
        }
    }return 0;
}
