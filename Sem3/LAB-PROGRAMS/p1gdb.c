
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    Node* next;
}*head;
int y;
//to create a node
Node* getnode(int value){
    struct Node* newNode = (Node*)malloc(1*sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    return(newNode);
}

//a node is created and pushed to the front
//add to front
void push(int value){
    Node* newNode = getnode(value);
    if(head == NULL){
        head = newNode;
    }
    else{
        newNode -> next = head;
        head = newNode;
    }
}

//delete from front
void pop(int num){
    int break_ = 0;
    while(num--){
    if(head == NULL){
        break_ = 1;
        //printf("\nStack is empty! Underflow Condition :(\n");
        break;
    }
    else if(head -> next == NULL){
        printf("%s", "The deleted element is : ");
        printf("%d", head -> data);
        free(head);
        break_ = 1;
        head = NULL;
        break;
    }
    else{
            struct Node* temp = head;
            head = head -> next;
            printf("%s", "The deleted element is : ");
            printf("%d\n", temp -> data);
            free(temp);
        }
        //printf("The stack is empty");
    }
    if(break_){
        printf("\nStack is Empty\n");
    }
    printf("\n");
}

void display(){
    if (head == NULL){
        printf("The stack is empty\n");
    }
    else{
        printf("%s\n" , "Contents are : ");
        struct Node* traverse = head;
        while(traverse != NULL){
            printf("%d ", traverse->data);
            traverse = traverse -> next;
        }
    }
    printf("\n");
}
//to get length of the stack
int length_of_ll(struct Node* traverse){
    int length = 0;
    if (traverse == NULL) {
        return(0);
    }
    if (traverse -> next == NULL){
        return(1);
    }
    else{
            while(traverse != NULL){
            length += 1;
            traverse = traverse -> next;
        }
        return(length);
    }
}
void third_from_top(){
    struct Node* temp = head;
    int length = length_of_ll(temp);
    if(length < 3){
        printf("\nStack has lesser than 3 elements\n");
    }
    else{
        int count = 1;
        while(count != 3){
            temp = temp -> next;
            count += 1;
        }
        printf("%s", "The third element from the top of the linked list is : ");
        printf("%d\n" , temp->data);
        y = temp -> data;
    }
}
void third_from_bottom(){
    Node* temp = head;
    int length = length_of_ll(temp);
    if((length - 3) < 0){
        printf("\nStack has lesser than 3 elements\n");
    }
    else{
        int count = 0;
        while(count != length - 3){
            temp = temp -> next;
            count += 1;
        }
        printf("%s", "The third element from the top of the linked list is : ");
        printf("%d\n" , temp->data);
        y = temp -> data;
    }
}

int main(){
    int choice;
    int y;
    head = NULL;
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
                pop(n);
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
