#include<stdio.h>
#define MAX 10

//Stack follows LIFO

//Structure def of stack, 
struct st{
    int stack[MAX];
    int top;
}stack_ds, stack_tmp;

int y;
int is_empty(){
    return stack_ds.top < 1;
}

int is_full(){
    return stack_ds.top >= MAX;
}


void push(int val){
    if(is_full()){
        printf("OverFlow\n");
        return;
    }
    else{
        stack_ds.stack[++stack_ds.top] = val;
    }
}

//Helper to get the length of the stack
int length(){
    return (stack_ds.top);
}

void pop(){    
    printf("Element at the top is : ");
    int top_element;
    top_element = stack_ds.stack[stack_ds.top--];
    //printf("%d \n" , stack_ds.stack[--stack_ds.top]);
    printf("%d \n" , top_element);
    
}   

void display(){
    if(is_empty()){
        printf("No elements in the stack \n");
    }
    else{
        printf("Contents are : \n");
        for(int i = 1; i <= stack_ds.top; i++){
            printf("%d \n", stack_ds.stack[i]);
        }
        printf("\n");
    }
}

void third_from_top(){
    if (length() < 3){
        printf("There are lesser than 3 elements \n");   
    } 
    else{
        stack_tmp = stack_ds;
        printf("The third element from the top of the stack is : ");
        printf("%d \n" , stack_tmp.stack[stack_tmp.top-2]);
    }
}

void third_from_bottom(){
    if (length() < 3){
        printf("There are lesser than 3 elements \n");   
    } 
    else{
        stack_tmp = stack_ds;
        int three = 2;
        int len = length();
        while((len > 3)){
            stack_tmp.top--;
            len -= 1;
        }
        printf("The third element from the bottom of the stack is : ");
        printf("%d \n" , stack_tmp.stack[stack_tmp.top]);
    }
}



int main(){
    int choice;
    stack_ds.top = 0;    
    printf("***************************************");
    printf("\n               MENU\n");
    printf("****************************************");
    printf("\n1.Add\n2.Pop n elements\n3.Display\n4.Third element from Top of Stack\n5.Third element from Bottom of Stack\n");
    
    while(1){
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
                if(n <= length()){
                    while(n--){
                        pop();
                    }
                }
                else{
                    printf("Not enough elements to pop \n");
                }
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                third_from_top();
                break;
            }
            case 5:{
              
                third_from_bottom();
                break;
            }
            default:
            printf("Wrong Option! \n");
        }
    }
    return(0);
}
