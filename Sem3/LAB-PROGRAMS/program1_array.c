#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct st{
    int stack[MAX];
    int top;
}stack_ds, stack_tmp;

int y;

void push(int val){
    if(stack_ds.top > MAX){
        printf("OverFlow\n");
    }
    else{
        stack_ds.stack[stack_ds.top++] = val;
    }
}

int length(){
    int count= 0;
    for(int i = 0; i < stack_ds.top; i++){
        count += 1;
    }
    return(count);
}
void pop(){
    if(stack_ds.top <= 0){
        printf("Underflow\n");
    }
    else{
        printf("Element at the top is : ");
        printf("%d" , stack_ds.stack[stack_ds.top--]);
    }
}   
void display(){
    printf("Contents are : \n");
    for(int i = 0; i < stack_ds.top; i++){
        printf("%d ", stack_ds.stack[i]);
    }
    printf("\n");
}

void third_from_top(){
    if (length() < 3){
        printf("There are lesser than 3 elements \n");   
    } 
    else{
        stack_tmp = stack_ds;
        int three = 3;
        while(three--){
            stack_tmp.top--;
        }
        printf("%d" , stack_tmp.stack[stack_tmp.top]);
    }
}
void third_from_bottom(){
    if (length() < 3){
        printf("There are lesser than 3 elements \n");   
    } 
    else{
        stack_tmp = stack_ds;
        int three = 3;
        while((length() - three--)){
            stack_tmp.top--;
        }
        printf("%d" , stack_tmp.stack[stack_tmp.top]);
    }
}

int main(){
    int choice;
    stack_ds.top = 0;
    printf("***************************************");
    printf("\n               MENU\n");
    printf("****************************************");
    printf("\n1.Add\n2.Pop n elements\n3.Display\n4.Third element from Top of Stack\n5.Third element from Bottom of Stack\n");
    
    while(true){
        printf("****************************************");
        printf("\nEnter choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                int value;
                printf("Enter the element : ");
                scanf("%d", &value);
                push(value);
                break;
            }
            case 2:{
                int n;
                printf("Enter number of elements to pop : ");
                scanf("%d" , &n);
                while(n--){
                    pop();
                }
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                printf("The length is\n");
                printf("%d\n" , length());
                break;
            }
            case 5:{
                printf("The third element from the top of the stack is : ");
                third_from_top();
                break;
            }
            case 6:{
                printf("The third element from the top of the stack is : ");
                third_from_top();
                printf("\n");
                break;
            }
            default:
            printf("Wrong Option! \n");
        }
    }
    return(0);
}
