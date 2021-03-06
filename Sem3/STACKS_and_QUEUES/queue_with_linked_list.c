#include<stdio.h>
#include <cstdlib>

//this is the implementation of a queue using linked lists as FIFO
struct node{
    int n;
    //char name[10];
    struct node* next;
    //pointer to struct, so the type has to be the same
};


struct node* head = NULL;
struct node* b = NULL;
void insert(int value){
    node* lk = (node*)malloc(1*sizeof(node));
    lk->n = value;
    lk->next= NULL;
    if (head == NULL){
        head = lk;
        b = lk;
    }
    else{
        head->next = lk;
        head = lk;
    }

}
void dltfrnt(){
    if(b == NULL){
        printf("%s", "Empty ");
    }
    else if(b->next == NULL){
        free(b);
    }
    else{
        struct node* temp;
        temp = b;
        b = b-> next;
        free(temp);
    }
    
}
//0 nodes
//1 node
//more than one node

void dltend(){
    if (head == NULL){
        printf("%s", "Empty");
    }
    else if(head->next == NULL){
    
        free(head);
        head = NULL;
    }
    else{
        struct node* temp;
        struct node* move = b;
        //while((q->next)->next){ 2 nodes ahead
        //u need such a loop to get control
        while((move->next)->next != NULL){
            //temp = move;
            move = move -> next;
        }
        //printf("%d", move->n);
        move-> next = NULL;
        free(head);
        head = move;
        }
    }



void display(){
    struct node* temp = b;
    while(temp != nullptr){
        printf("%d ", temp->n);
        temp = temp->next;
    }
    printf("\n");
    //printf("%p", temp);

}


int main(){

    //this points to where u are currently
    
   insert(30);
   insert(40);
   insert(50);
   insert(60);
   insert(70);
   insert(80);
   display();
   dltend();
   dltend();
   dltend();
   display();

   

    return 0;

}
