#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    Node* prev;
    Node* next;
}*head, *pfrnt;

Node* getnode(int val){
    Node* temp = (Node*)malloc(1*sizeof(Node));
    temp -> data = val;
    temp -> prev = NULL;
    temp -> next = NULL;
    return temp;
}
void insert_with_1ptr_start(int val){
    Node* add = getnode(val);
    if(head == NULL){
        head = add;
    }
    else{
        add -> next = head;
        head -> prev = add;
        head = add;

    }
}
void insert_with_1ptr_end(int val){
    Node* add = getnode(val);
    if(head == NULL){
        head = add;
        pfrnt = add;
    }
    else{

       head -> next = add;
       add -> prev = head;
       head = add;

    }
}
void delt(){
    if(head == NULL){
        printf("%s", "Empty");
    }
    else if(head -> next == NULL){
        free(head);
        head = NULL;
    }
    else{
        Node * move = head;
        //go to the end, that's the only thing that is different here;
        while((move -> next) -> next != NULL){
            move = move -> next;
        }
        Node* last = move -> next;
        move -> next = NULL;
        free(last);
    }
}
void dlte(){
    if(head == NULL){
        printf("%s", "Empty");
    }
    else{
        Node* lb1 = head -> prev;
        lb1 -> next = NULL;
        free(head);
        head = lb1;
    }
}
void display(){
    Node* move = pfrnt;
    printf("%s\n", "Contents");
    while(move != NULL){
        printf("%d " , move->data);
        move = move -> next;
    }
    printf("\n");
}
int main(){
    int ch;
    head = NULL;
    pfrnt = NULL;
    while(true){
        printf("Enter 1 to add, 2 to delete \n");
        scanf("%d" , &ch);
        switch(ch){
            case 1:{
                    int el;
                    printf("Enter element \n");
                    scanf("%d" , &el);
                    insert_with_1ptr_end(el);
                    //insertend_with2ptr(el);
                    display();
                    break;
                }
            case 2:{
                   
                       //dltfront();
                       //dlt_with_1ptr();
                       dlte();
                       display();
                       break;
            }
            default:
                   printf("No option \n");

        }

    }
    return 0;
}