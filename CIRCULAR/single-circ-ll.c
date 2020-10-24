#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    Node* next;
};
Node* head = NULL;
Node* start = NULL;
//head is pointing to the end of the linked list
Node* getnode(int value){
    Node* newn = (Node*)malloc(1*sizeof(Node));
    newn -> data = value;
    newn -> next = newn;
    return(newn);
}

void insertbeg(int value){
    Node* newn = getnode(value);
    if(head == NULL){
        head = newn;
        start = newn;
    }
    else{
        newn -> next = head -> next;
        head -> next = newn;
    }
}
void insertend(int value){
    Node* newn = getnode(value);
    if(head == NULL){
        head = newn;
        start = newn;
    }
    else{
        newn -> next = head -> next;
        head -> next = newn;
        head = newn;
    }
}

void dltfrnt(){
    if(head == NULL){
        printf("\nEmpty\n");
    }
    else if(head -> next == NULL){
        free(head);
        head = NULL;
    }
    else{
        Node* nn = head -> next -> next;
        head -> next = nn;
        free(head -> next);
    }
}

void dltend(){
    if(head == NULL){
        printf("\nEmpty\n");
    }
    else if(head -> next == NULL){
        free(head);
        head = NULL;
    }
    else{
        Node *t = head -> next;
        while(t -> next != head){
            t = t -> next;
        }
       t -> next = head -> next;
       free(head);
       head = t;
    }
}

void display(){
    if(head == NULL){
        printf("Empty\n");
    }
    else if(head -> next == NULL){
        printf("Empty\n");
    }
    else{
        Node* temp = head -> next;
        while(temp != head){
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
        //cause u will come out exacrlt when this happens
        printf("%d ", temp -> data);
    }
}

int main(){
   
    printf("MENU\n");
    printf("1.Add\n");
    printf("2.Delete\n");
    printf("3.Display");
    int ch;
    while(true){
        printf("\nEnter an option : ");
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                int el;
                printf("Enter the el : ");
                scanf("%d", &el);
                //insertbeg(el);
                insertend(el);
                break;
            }
            case 2:{
                dltfrnt();
                break;
            }
            case 3:{
                display();
                break;
            }
        }
    }
    return (0);
}